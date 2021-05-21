#include <stdio.h>
#include "SqStack.h"
#include "LinkStack.h"

void e3_1() {
    SqStack S = SqStack_init(); // ��ʼ��ջ
    int x,e;
    printf("please input the insert node:");/*����������Ҫ��ջ����Ԫ��*/
    scanf("%d",&x);
    S=Push(S,x);
    printf("the stack after push is:\n");/*��ʾ�����ջ��ջ�и���Ԫ��ֵ*/
    Stack_display(S);   /*����˳��ջ���������*/
    S=Pop(S,&e);
    printf("the pop value is:%d\n",e);  /*�����ջԪ�ص�ֵ*/
    printf("the stack after pop is:\n");/*��ʾ�����ջ��ջ�и���Ԫ��ֵ*/
    Stack_display(S);   /*����˳��ջ���������*/
}

/*
���磬ջ����4��Ԫ�أ�13��12��11��10����ջ����ջ��ʱ��Ҫ��������Ϊ��
��1�ε�ջԪ��Ϊ��10
��2�ε�ջԪ��Ϊ��11
��3�ε�ջԪ��Ϊ��12
��4�ε�ջԪ��Ϊ��13
��ʱջ�ѿ�
 */
void e3_2() {
    SqStack S = SqStack_init(); // ��ʼ��ջ
    Stack_pop_all(S);
}

/*
�� ���������ջ��Ԫ�ظ����͸�Ԫ��ֵ����һ����ջ���������ջ�и�Ԫ��ֵ, �۲����������������������Ƿ�һ��,�ر�ע��ջ��Ԫ�ص�λ�á�
��	������Ԫ��x��ջ���������ջ�����ջ�и�Ԫ��ֵ��
�� ����ջ�е�ջ��Ԫ�س�ջ���������ջԪ�ص�ֵ�ͳ�ջ����ջ�и�Ԫ��ֵ��
 */
void e3_3() {
    int data, e;
    LinkStack LS;
    printf("����ջ���ݣ�0��ֹ����");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        LinkStack_Push(&LS, data);
    }
    LinkStack_display(LS);

    printf("����x��");
    scanf("%d", &e);
    LinkStack_Push(&LS, e);
    LinkStack_display(LS);

    LinkStack_Pop(&LS, &e);
    printf("��ջ��ֵ�ǣ�%d\n", e);
    LinkStack_display(LS);
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
//    e3_1();
//    e3_2();
    e3_3();
    return 0;
}