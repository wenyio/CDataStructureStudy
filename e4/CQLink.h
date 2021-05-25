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
 * ��ʼ���ô�ͷ����ѭ�������ʾ�Ķ���rear,����rearָ���βԪ��
 * @param rear
 */
void InitCiQueue(CQLink *rear)
{
    *rear = (CQNode *) malloc(sizeof(CQNode)); /*����һ��ͷ��㣬��ʹ��βָ��ָ����*/
    (*rear)->next = *rear;   /*�γ�ѭ��*/
}

/**
 * ��Ӳ���: ��Ԫ��x���뵽�ö�βָ��rear��ʾ�Ĵ�ͷ����ѭ��������rear��
 * @param rear
 * @param x
 * @return
 */
status EnCiQueue(CQLink *rear, int x)
{
    CQNode* p = (CQNode *) malloc(sizeof(CQNode));
    if (!p)
        return (OVERFLOW);
    p->data = x;           /*����һ���½��p*/
    p->next = (*rear)->next;   /*ֱ�Ӱ�p���뵽rear�ĺ���*/
    (*rear)->next = p;
    (*rear) = p;         /*�޸�βָ��,ʹp��Ϊ�µĶ�β���*/
    return OK;
}

/**
 * ���ö�βָ��rear��ʾ�Ĵ�ͷ����ѭ����������ɾ��һ������Ԫ�أ�����x�������������ֵ��
 * @param rear
 * @param x
 * @return
 */
status DeCiQueue(CQLink *rear, int *x)
{
    if (*rear == (*rear)->next) return ERROR;  /*�������Ϊ�գ���������ERROR*/
    CQNode* p = (*rear)->next->next;/*��pָ��ָ����׽��,Ҳ�Ǵ�ɾ���*/
    *x = p->data;   /* ��x�����ɾ���׽����������ֵ*/
    (*rear)->next->next = p->next;/*�޸�����ʹp�ĺ�̳�Ϊ�µĶ��׽��*/
    if ((*rear) == p) /*�����ɾ�Ľ��p�Ƕ�β���,��Ҫʹ��βָ��ָ��ԭ����β���ĺ��(ͷ���)*/
        (*rear) = (*rear)->next;
    free(p);    /*�ͷŴ�ɾ���Ŀռ�*/
    return OK;
}

/**
 * ��ʾ�����������Ԫ��
 * @param rear
 */
void CQLink_display(CQLink rear) {
    CQLink p = rear->next->next; // ��¼ͷ��λ��
    printf("����Ԫ������Ϊ��ͷ-��β����");
    while(p != rear->next) {
        printf("%d ", p->data);
        p = p->next;
    }
}