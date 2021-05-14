typedef struct LNode {
    int data;
    struct Lnode *next;
} LNode, *Linklist;

Linklist create(Linklist L)  /*单链表建立函数 */
{
    int node;
    Linklist p;
    L = (Linklist) malloc(sizeof(LNode));
    L->next = NULL;
    printf("\nplease input the node(end with 0):\n");  /*请求输入线性表中各个元素，以0结束*/
    scanf("%d", &node);
    while (node != 0) {
        p = (Linklist) malloc(sizeof(LNode));
        if (!p) return NULL;
        p->data = node;
        p->next = L->next;
        L->next = p;
        scanf("%d", &node);
    }
    return L;
}

Linklist insert(Linklist L, int i, int x)  /*单链表插入函数*/
{
    int j;
    Linklist p, s;
    p = L;
    j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == NULL || j > i - 1)
        printf("\n ERROR position!\n");
    else {
        s = (Linklist) malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
    return L;
}

Linklist delete(Linklist L, int i)  /*单链表删除函数*/
{
    int j, x;
    Linklist p, q;
    p = L;
    j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == NULL || j > i - 1)
        printf("\n ERROE position!\n");
    else {
        q = p->next;
        p->next = q->next;
        x = q->data;
        printf("the delete data is:%d\n", x);
        free(q);
    }
    return L;
}

int search(Linklist L, int i) /*单链上的查找函数*/
{
    Linklist p;
    int j;
    p = L->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p && j > i)
        return 0;   /*如果i值不合法，即i值小于1或大于表长，则函数返回0值*/
    else
        return (p->data);    /*否则函数返回第i个元素的值*/
}

void display(Linklist L)  /*单链表元素输出函数*/
{
    Linklist p;
    p = L->next;
    while (p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 统计链表中i出现的次数
 * @param L
 * @param i
 * @return 出现的次数
 */
int count(Linklist L, int i) {
    int result = 0;
    Linklist p;
    p = L->next;
    while (p != NULL) {
        if (p->data == i) // 如果和i相等 result就+1
            result++;
        p = p->next;
    }
    return result;
}
