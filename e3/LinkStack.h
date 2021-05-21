#define SElemType int
#define status int
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#include "malloc.h"

typedef struct {
    SElemType data; // ������
    struct SNode *next; // ָ����
} SNode, *LinkStack; // ����SNodeΪ��ջ�еĽ��������, LinkStackΪָ�����ָ��������

/**
 * ������Ԫ��eѹ�뵽��ջtop�У�ʹ���Ϊ�µ�ջ��Ԫ��
 * @param top
 * @param e
 * @return
 */
status LinkStack_Push(LinkStack *top, int e) {
    LinkStack p;
    p = (LinkStack) malloc(sizeof(SNode)); /*����һ���µĽ��*/
    if (!p)  /*�������ռ�ʧ�ܣ���������"OVERFLOW"*/
        return OVERFLOW;
    p->data = e;   /*�½���������ֵ*/
    p->next = *top; /*�޸���ʹ�½����뵽�����ͷ��,����Ϊ�µ�ջ��Ԫ��*/
    *top = p;
    return OK;
}

/**
 * ����ջtop�е�ջ��Ԫ�ش�ջ��ɾ��������e������ֵ
 * @param top
 * @param e
 * @return
 */
status LinkStack_Pop(LinkStack *top, int *e) {
    LinkStack q;
    if (!*top)   /*���ջ�գ���������ERROR*/
        return ERROR;
    *e = (*top)->data;   /*����ɾ��ջ��Ԫ�ص�ֵ������e��*/
    q = *top;     /*��q���´�ɾ��ջ��Ԫ��*/
    *top = q->next;
/*�޸���ʹ��ɾ�������С�ж�¡�����ʱ��ɾ���ĺ�̳�Ϊ�µ�ջ��Ԫ�ؽ��*/
    free(q);    /*�ͷű�ɾ���Ĵ洢�ռ�*/
    return OK;
}

void LinkStack_display(LinkStack top) {
    printf("��ջԪ���ǣ�ͷ->β����");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}