#define MAXSIZE 100
typedef struct {
    int base[MAXSIZE];
    int top;    /* top指示存储栈顶元素的下一存储单元*/
} SqStack;   /*顺序栈的类型定义*/

/**
 * 顺序栈的入栈操作函数
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
 * 顺序栈的出栈操作函数
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
 * 出栈时一个一个循环弹栈显示
 * @param S
 */
void Stack_pop_all(SqStack S)
{
    int i = 0;
    while (S.top != 0) {
        i++;
        printf("第%d次弹栈元素为：%d\n", i, S.base[--S.top]);
    }
    printf("此时栈已空\n");
}

/**
 * 顺序栈的输出函数
 * @param S
 */
void Stack_display(SqStack S)
{
    int i;
    for (i = 0; i < S.top; i++)   /*依次输出栈中各元素的值，栈顶元素在表的尾部*/
        printf("%4d", S.base[i]);
    printf("\n");
}

/**
 * 初始化一个堆栈
 * @return
 */
SqStack SqStack_init() {
    SqStack S;
    int i, n;
    printf("please input the length:");/*请求输入顺序栈中元素个数*/
    scanf("%d",&n);
    printf("please input the Value:\n  ");/*请求输入顺序栈中各个元素值*/
    for(i=0;i<n;i++)
        scanf("%d",&S.base[i]);
    (S).top=n;
    printf("the stack is:\n");
    Stack_display(S);
    return S;
}
