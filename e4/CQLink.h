#define QElemType int
#define status int
#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef struct CQNode {
    QElemType data;
    struct CQNode *next;
} CQNode, *CQLink;

/**
 * 初始化用带头结点的循环链表表示的队列rear,其中rear指向队尾元素
 * @param rear
 */
void InitCiQueue(CQLink *rear)
{
    *rear = (CQNode *) malloc(sizeof(CQNode)); /*产生一个头结点，并使队尾指针指向它*/
    (*rear)->next = *rear;   /*形成循环*/
}

/**
 * 入队操作: 把元素x插入到用队尾指针rear表示的带头结点的循环链队列rear中
 * @param rear
 * @param x
 * @return
 */
status EnCiQueue(CQLink *rear, int x)
{
    CQNode* p = (CQNode *) malloc(sizeof(CQNode));
    if (!p)
        return (OVERFLOW);
    p->data = x;           /*产生一个新结点p*/
    p->next = (*rear)->next;   /*直接把p插入到rear的后面*/
    (*rear)->next = p;
    (*rear) = p;         /*修改尾指针,使p成为新的队尾结点*/
    return OK;
}

/**
 * 从用队尾指针rear表示的带头结点的循环链队列中删除一个队首元素，并用x返回其数据域的值。
 * @param rear
 * @param x
 * @return
 */
status DeCiQueue(CQLink *rear, int *x)
{
    if (*rear == (*rear)->next) return ERROR;  /*如果队列为空，则函数返回ERROR*/
    CQNode* p = (*rear)->next->next;/*用p指针指向队首结点,也是待删结点*/
    *x = p->data;   /* 用x保存待删队首结点的数据域的值*/
    (*rear)->next->next = p->next;/*修改链，使p的后继成为新的队首结点*/
    if ((*rear) == p) /*如果待删的结点p是队尾结点,则要使队尾指针指向原来队尾结点的后继(头结点)*/
        (*rear) = (*rear)->next;
    free(p);    /*释放待删结点的空间*/
    return OK;
}

/**
 * 显示队列里的所有元素
 * @param rear
 */
void CQLink_display(CQLink rear) {
    CQLink p = rear->next->next; // 记录头的位置
    printf("队列元素依此为（头-》尾）：");
    while(p != rear->next) {
        printf("%d ", p->data);
        p = p->next;
    }
}