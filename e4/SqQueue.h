#define MAXSIZE 100 /*顺序循环队列的最大长度*/
#define QElemType int

typedef struct {
    QElemType base[MAXSIZE]; /*存放队列元素的数组空间*/
    int front;  /*头指针，若队列不空，则指向队列头元素*/
    int rear; /*尾指针，若队列不空，则指向队列尾元素的下一个存储单元*/
} SqQueue;

/**
 * 队列的入队函数
 * @param Q
 * @param e
 * @return
 */
SqQueue enqueue(SqQueue Q, int e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)    /*尾指针在循环意义上加1后等于头指针，表明队满*/
        printf("ERROR\n");
    else {
        Q.base[Q.rear] = e;     /*新元素插入队尾*/
        Q.rear = (Q.rear + 1) % MAXSIZE;    /*队尾指针加1*/
    }
    return Q;
}

/**
 * 队列的出队函数
 * @param Q
 * @param e
 * @return
 */
SqQueue dequeue(SqQueue Q, int *e)
{
    int x;
    if (Q.front == Q.rear)     /*队空*/
        printf("ERROR\n ");
    else {
        *e = Q.base[Q.front];     /*保存队头元素*/
        Q.front = (Q.front + 1) % MAXSIZE;     /*队头指针加1*/
    }
    return Q;
}

/**
 * 队列元素输出函数
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


