#define SElemType int
#define status int
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#include "malloc.h"

typedef struct {
    SElemType data; // 数据域
    struct SNode *next; // 指针域
} SNode, *LinkStack; // 其中SNode为链栈中的结点类型名, LinkStack为指向结点的指针类型名

/**
 * 将数据元素e压入到链栈top中，使其成为新的栈项元素
 * @param top
 * @param e
 * @return
 */
status LinkStack_Push(LinkStack *top, int e) {
    LinkStack p;
    p = (LinkStack) malloc(sizeof(SNode)); /*生成一个新的结点*/
    if (!p)  /*如果分配空间失败，则函数返回"OVERFLOW"*/
        return OVERFLOW;
    p->data = e;   /*新结点的数据域赋值*/
    p->next = *top; /*修改链使新结点插入到链表的头部,并成为新的栈顶元素*/
    *top = p;
    return OK;
}

/**
 * 将链栈top中的栈顶元素从栈中删除，并用e返回其值
 * @param top
 * @param e
 * @return
 */
status LinkStack_Pop(LinkStack *top, int *e) {
    LinkStack q;
    if (!*top)   /*如果栈空，则函数返回ERROR*/
        return ERROR;
    *e = (*top)->data;   /*将被删的栈顶元素的值保存在e中*/
    q = *top;     /*用q记下待删的栈顶元素*/
    *top = q->next;
/*修改链使待删结点从链中“卸下”，此时被删结点的后继成为新的栈顶元素结点*/
    free(q);    /*释放被删结点的存储空间*/
    return OK;
}

void LinkStack_display(LinkStack top) {
    printf("链栈元素是（头->尾）：");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}