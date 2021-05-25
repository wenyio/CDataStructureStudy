#include<stdio.h>
#include<malloc.h>
#include "SqQueue.h"
#include "CQLink.h"

void init(SqQueue *Q)
{
    int n, i, x;
    (*Q).rear = (*Q).front = 0; /*初始化顺序队列，使其成为空队列*/
    printf("\nplease input the length:");/*请求输入队列的长度*/
    scanf("%d", &n);
    printf("please input create data:\n  ");/*请求输入队列中各个元素*/
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        *Q = enqueue(*Q, x);
    }  /*调用队列插入函数*/
    printf("the queue is:\n");
    display(*Q);  /*调用队列元素输出函数*/
}

void e4_1() {
    SqQueue Q;
    init(&Q);
    int y, e;
    printf("please input a insert data:");  /*请求输入需要插入的元素*/
    scanf("%d", &y);
    Q = enqueue(Q, y);/*调用队列插入函数*/
    printf("the queue after insert is:\n");/*提示显示执行入队操作后的队列*/
    display(Q);/*调用队列元素输出函数*/
    Q = dequeue(Q, &e);/*调用队列删除函数*/
    printf("the delete data is:%d\n", e); /*显示被删的队首元素值*/
    printf("the queue after delete is:\n");/*提示显示执行出队操作后的队列*/
    display(Q);/*调用队列元素输出函数*/
}

void e4_2() {
    CQLink CQL;
    InitCiQueue(&CQL);
    int n, i, x, e;
    printf("请输入队列长度n：");
    scanf("%d", &n);
    printf("请输入队列数据：");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        EnCiQueue(&CQL, x);
    }
    CQLink_display(CQL);
    printf("\n请输入要入队列的值e：");
    scanf("%d", &e);
    EnCiQueue(&CQL, e);
    CQLink_display(CQL);
    DeCiQueue(&CQL, &x);
    printf("\n出列的值是：%d\n", x);
    CQLink_display(CQL);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
//    e4_1();
    e4_2();
    return 0;
}