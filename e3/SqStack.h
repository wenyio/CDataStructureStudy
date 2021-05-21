#define MAXSIZE 100
typedef struct {
    int base[MAXSIZE];
    int top;    /* topָʾ�洢ջ��Ԫ�ص���һ�洢��Ԫ*/
} SqStack;   /*˳��ջ�����Ͷ���*/

/**
 * ˳��ջ����ջ��������
 * @param S
 * @param e
 * @return
 */
SqStack Push(SqStack S, int e)
{
    if (S.top >= MAXSIZE)
        printf("Stack is Overflow\n");
    else
        S.base[S.top++] = e;
    return S;
}

/**
 * ˳��ջ�ĳ�ջ��������
 * @param S
 * @param e
 * @return
 */
SqStack Pop(SqStack S, int *e)
{
    if (S.top == 0)
        printf("Stack is Empty\n");
    else
        *e = S.base[--S.top];
    return S;
}

/**
 * ��ջʱһ��һ��ѭ����ջ��ʾ
 * @param S
 */
void Stack_pop_all(SqStack S)
{
    int i = 0;
    while (S.top != 0) {
        i++;
        printf("��%d�ε�ջԪ��Ϊ��%d\n", i, S.base[--S.top]);
    }
    printf("��ʱջ�ѿ�\n");
}

/**
 * ˳��ջ���������
 * @param S
 */
void Stack_display(SqStack S)
{
    int i;
    for (i = 0; i < S.top; i++)   /*�������ջ�и�Ԫ�ص�ֵ��ջ��Ԫ���ڱ��β��*/
        printf("%4d", S.base[i]);
    printf("\n");
}

/**
 * ��ʼ��һ����ջ
 * @return
 */
SqStack SqStack_init() {
    SqStack S;
    int i, n;
    printf("please input the length:");/*��������˳��ջ��Ԫ�ظ���*/
    scanf("%d",&n);
    printf("please input the Value:\n  ");/*��������˳��ջ�и���Ԫ��ֵ*/
    for(i=0;i<n;i++)
        scanf("%d",&S.base[i]);
    (S).top=n;
    printf("the stack is:\n");
    Stack_display(S);
    return S;
}
