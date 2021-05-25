#include<stdio.h>
#include<malloc.h>
#include "SqQueue.h"
#include "CQLink.h"

void init(SqQueue *Q)
{
    int n, i, x;
    (*Q).rear = (*Q).front = 0; /*��ʼ��˳����У�ʹ���Ϊ�ն���*/
    printf("\nplease input the length:");/*����������еĳ���*/
    scanf("%d", &n);
    printf("please input create data:\n  ");/*������������и���Ԫ��*/
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        *Q = enqueue(*Q, x);
    }  /*���ö��в��뺯��*/
    printf("the queue is:\n");
    display(*Q);  /*���ö���Ԫ���������*/
}

void e4_1() {
    SqQueue Q;
    init(&Q);
    int y, e;
    printf("please input a insert data:");  /*����������Ҫ�����Ԫ��*/
    scanf("%d", &y);
    Q = enqueue(Q, y);/*���ö��в��뺯��*/
    printf("the queue after insert is:\n");/*��ʾ��ʾִ����Ӳ�����Ķ���*/
    display(Q);/*���ö���Ԫ���������*/
    Q = dequeue(Q, &e);/*���ö���ɾ������*/
    printf("the delete data is:%d\n", e); /*��ʾ��ɾ�Ķ���Ԫ��ֵ*/
    printf("the queue after delete is:\n");/*��ʾ��ʾִ�г��Ӳ�����Ķ���*/
    display(Q);/*���ö���Ԫ���������*/
}

void e4_2() {
    CQLink CQL;
    InitCiQueue(&CQL);
    int n, i, x, e;
    printf("��������г���n��");
    scanf("%d", &n);
    printf("������������ݣ�");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        EnCiQueue(&CQL, x);
    }
    CQLink_display(CQL);
    printf("\n������Ҫ����е�ֵe��");
    scanf("%d", &e);
    EnCiQueue(&CQL, e);
    CQLink_display(CQL);
    DeCiQueue(&CQL, &x);
    printf("\n���е�ֵ�ǣ�%d\n", x);
    CQLink_display(CQL);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
//    e4_1();
    e4_2();
    return 0;
}