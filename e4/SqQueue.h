#define MAXSIZE 100 /*˳��ѭ�����е���󳤶�*/
#define QElemType int

typedef struct {
    QElemType base[MAXSIZE]; /*��Ŷ���Ԫ�ص�����ռ�*/
    int front;  /*ͷָ�룬�����в��գ���ָ�����ͷԪ��*/
    int rear; /*βָ�룬�����в��գ���ָ�����βԪ�ص���һ���洢��Ԫ*/
} SqQueue;

/**
 * ���е���Ӻ���
 * @param Q
 * @param e
 * @return
 */
SqQueue enqueue(SqQueue Q, int e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)    /*βָ����ѭ�������ϼ�1�����ͷָ�룬��������*/
        printf("ERROR\n");
    else {
        Q.base[Q.rear] = e;     /*��Ԫ�ز����β*/
        Q.rear = (Q.rear + 1) % MAXSIZE;    /*��βָ���1*/
    }
    return Q;
}

/**
 * ���еĳ��Ӻ���
 * @param Q
 * @param e
 * @return
 */
SqQueue dequeue(SqQueue Q, int *e)
{
    int x;
    if (Q.front == Q.rear)     /*�ӿ�*/
        printf("ERROR\n ");
    else {
        *e = Q.base[Q.front];     /*�����ͷԪ��*/
        Q.front = (Q.front + 1) % MAXSIZE;     /*��ͷָ���1*/
    }
    return Q;
}

/**
 * ����Ԫ���������
 * @param Q
 */
void display(SqQueue Q)
{
    int k, m;
    k = Q.front;
    m = Q.rear;
    while (k != m) {
        printf("%4d", Q.base[k]);
        k = (k + 1) % MAXSIZE;
    }
    printf("\n");
}


