#include <stdio.h>
#include "SqStack.h"
#include "LinkStack.h"

void e3_1() {
    SqStack S = SqStack_init(); // 初始化栈
    int x,e;
    printf("please input the insert node:");/*请求输入需要入栈的新元素*/
    scanf("%d",&x);
    S=Push(S,x);
    printf("the stack after push is:\n");/*提示输出入栈后栈中各个元素值*/
    Stack_display(S);   /*调用顺序栈的输出函数*/
    S=Pop(S,&e);
    printf("the pop value is:%d\n",e);  /*输出出栈元素的值*/
    printf("the stack after pop is:\n");/*提示输出出栈后栈中各个元素值*/
    Stack_display(S);   /*调用顺序栈的输出函数*/
}

/*
例如，栈中有4个元素：13，12，11，10，弹栈（出栈）时，要求输出结果为：
第1次弹栈元素为：10
第2次弹栈元素为：11
第3次弹栈元素为：12
第4次弹栈元素为：13
此时栈已空
 */
void e3_2() {
    SqStack S = SqStack_init(); // 初始化栈
    Stack_pop_all(S);
}

/*
① 根据输入的栈中元素个数和各元素值建立一个链栈，并输出链栈中各元素值, 观察输入的内容与输出的内容是否一致,特别注意栈顶元素的位置。
①	将数据元素x入栈，并输出入栈后的链栈中各元素值。
③ 将链栈中的栈顶元素出栈，并输入出栈元素的值和出栈后链栈中各元素值。
 */
void e3_3() {
    int data, e;
    LinkStack LS;
    printf("输入栈数据（0终止）：");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        LinkStack_Push(&LS, data);
    }
    LinkStack_display(LS);

    printf("输入x：");
    scanf("%d", &e);
    LinkStack_Push(&LS, e);
    LinkStack_display(LS);

    LinkStack_Pop(&LS, &e);
    printf("出栈的值是：%d\n", e);
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