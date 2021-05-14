#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior; // 指向直接前驱指针域
    struct DuLNode *next; // 指向直接后继指针域
} DuLNode, *DuLinklist;

/**
 * 输入n个整数（其中n为表长），将这些整数作为data域并用尾插法建立一个带头结点的双向循环链表的函数
 * @param L
 * @param n
 * @return
 */
DuLinklist DuList_create(DuLinklist L, int n) {
    DuLinklist r, p;
    L = (DuLinklist) malloc(sizeof(DuLNode)); // 为头结点分配空间
    L->next = L->prior = L; // 使头结点的后继指针和前驱指针都指向自身，形成空的双向循环链表
    r = L; // 尾指针初始指向头结点
    printf("请输入链表的元素：");
    for (int i = 0; i < n; i++) {
        p = (DuLinklist) malloc(sizeof(DuLNode));// 为一个新结点分配空间
        scanf("%d", &p->data); // 从键盘输入值，并保存在新结点数据域中
        p->next = r->next; // 新结点后继指针指向尾结点r的后继结点
        p->prior = r;    // 新结点的前驱指针指向尾结点r
        r->next = p;  // 尾结点的后继指针指向新结点
        r = p;      // 尾指针指向新结点，即新结点成为尾结点
    }
    L->prior = r;    // 使尾结点成为头结点的前驱结点
    return L;
}

/**
 * 顺序打印链表，传入链表和长度
 * @param L
 * @param n
 */
void DuList_display(DuLinklist L, int n) {
    printf("链表元素分别是：\n");
    DuLinklist r = L->next;
    for (int i = 0; i < n; i++) {
        printf("%d ", r->data);
        r = r->next;
    }
    printf("\n");
}

/**
 * 在带头结点的双向循环链表L中查找第i个元素，如果查找成功则用e返回其值
 * @param L
 * @param i
 * @return
 */
ElemType DuList_search(DuLinklist L, int i, ElemType e) {
    DuLinklist p;
    int j = 1; // 计数器赋初值为1
    p = L->next;  // 使指针p指向第1个元素结点
    while (p != L && j < i)  // 顺着后继指针查找第i个元素结点
    {
        p = p->next;
        j++;
    }
    if (j != i)
        return NULL;  // 如果i值不合法，即i值小于1或大于表长，则出错
    e = p->data;    // 如果第i个元素存在，则将该元素值赋给e
    return e;
}

/**
 * 在带头结点的双向循环链表L中第i个位置之前插入新元素x
 * @param L
 * @param i
 * @param x
 * @return
 */
DuLinklist DuList_insert(DuLinklist L, int i, ElemType x) {
    int j = 1;
    DuLinklist p, s;
    p = L->next;
    while (p != L && j < i) // 寻找插入位置，并使p指向插入位置的结点，即L中的第i个结点
    {
        p = p->next;
        ++j;
    }
    if (j != i)
        return NULL;  // 若位置不正确,即i小于1或大于表的长度加1，则出错
    s = (DuLinklist) malloc(sizeof(DuLNode)); // 为一个新结点s分配空间
    s->data = x;   // 为新结点数据域赋值
    // 下面四条语句就是完成修改链，将新结点s插入到p结点之前
    s->next = p;
    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    return L;
}

/**
 * 在带头结点的双向循环链表L中，删除第i个元素结点，并用x返回其值
 * @param L
 * @param i
 * @param x
 * @return
 */
DuLinklist DuList_delete(DuLinklist L, int i, ElemType *x) {
    DuLinklist p, q;
    int j = 1;
    p = L->next;
    j = 1;
    while (p != L && j < i) // 寻找被删结点，并使p指向被删结点的前驱
    {
        p = p->next;
        ++j;
    }
    if (j != i)
        return NULL;   // 若位置不正确，即i小于1或大于表长，则出错
    q = p;   // 记下被删结点
    p->prior->next = p->next;   // 修改链使得p结点从链中脱离
    p->next->prior = p->prior;
    *x = q->data;
    printf("删除的元素是：%d\n", *x);
    free(q);  // 释放被删结点空间
    return L;
}

/**
 * 在双向循环链表中查找值为x元素，如果查找成功，则显示该元素在链表中的位置，否则显示该元素不存在。
 * @param L 链表
 * @param i 元素在链表中的位置
 * @param x 要查找的元素
 * @param n 元素的长度，防止死循环
 * @return
 */
void DuList_search_x(DuLinklist L, int *i, ElemType *x, int n) {
    if (!L || n <= 0) {
        return;
    }
    DuLinklist p = L->next;
    for (int j = 0; j < n; j++) {
        if (p->data == *x) {
            *i = j + 1;
            break;
        }
        p = p->next;
    }
}