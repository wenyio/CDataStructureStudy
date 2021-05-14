#include <stdio.h>
#include <malloc.h>
#include "Linklist.h"

void e2_1() {
    Linklist L = NULL;
    int i, x;
    L = create(L);/*调用单链表建立函数*/
    printf("the Linklist is:\n");
    display(L); /*调用单链表元素输出(遍历)函数*/
    printf("please input the position  you want to insert:");/*请求输入插入操作位置*/
    scanf("%d", &i);
    printf("please input the node you want to insert:");/*请求输入需要插入的元素*/
    scanf("%d", &x);
    L = insert(L, i, x);/*调用单链表插入函数*/
    printf("the Linklist after inserted is:\n");
    display(L);/*调用单链表元素输出(遍历)函数*/
    printf("please input the node position you want to delete:"); /*请求输入删除操作位置*/
    scanf("%d", &i);
    L = delete(L, i); /*调用单链表删除函数*/
    printf("the Linklist after deleted is:\n");
    display(L); /*调用单链表元素输出(遍历)函数*/
    printf("please input the position you want to search:"); /*请求输入待查找元素的位置*/
    scanf("%d", &i);
    x = search(L, i);  /*调用单链表查找函数*/
    if (x)   /*如果查找成功，则显示第i个元素的值，否则显示第i个元素不存在*/
        printf("  the %dth elem is %d\n", i, x);
    else
        printf("  the %dth elem is not exsit\n");
}
/*
 ① 从键盘输入若干个整数，以此序列为顺序建立一个不带头结点的单链表；
 ② 输出此单链表中的各个数据元素值；
 ③ 给定一个x的具体整数值，计算并返回此单链表中数据域值为x的结点个数值。
 */
void e2_2() {
    Linklist L = NULL;
    int i;
    L = create(L); // 调用单链表建立函数
    printf("the Linklist is:\n");
    display(L); // 调用单链表元素输出(遍历)函数
    printf("please input the node you want to count: \n");
    scanf("%d", &i);
    printf("It appears %d times.", count(L, i));
}

int main() /*主函数*/
{
    setvbuf(stdout, NULL, _IONBF, 0);
//    e2_1();
    e2_2();
}
