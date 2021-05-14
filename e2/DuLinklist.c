#include "stdio.h"
#include "malloc.h"
#include "DuLinklist.h"

/*
① 输入链表的长度和各元素的值，用尾插法建立双向循环链表，并输出链表中各元素值，观察输入的内容与输出的内容是否一致。
② 在双向循环链表的第i个元素之前插入一个值为x的元素，并输出插入后的链表中各元素值。
③ 删除双向循环链表中第i个元素，并输出删除后的链表中各元素值。
④ 在双向循环链表中查找值为x元素，如果查找成功，则显示该元素在链表中的位置，否则显示该元素不存在。
 */

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("1. 输入链表的长度和各元素的值，用尾插法建立双向循环链表，并输出链表中各元素值，观察输入的内容与输出的内容是否一致。\n");
    int n; // n 个元素
    DuLinklist L = NULL;
    printf("请输入链表的长度：");
    scanf("%d", &n);
    L = DuList_create(L, n);
    DuList_display(L, n);

    printf("2. 在双向循环链表的第i个元素之前插入一个值为x的元素，并输出插入后的链表中各元素值。\n");
    int i, x;
    printf("请输入插入元素的位置i：");
    scanf("%d", &i);
    printf("请输入插入元素的值x：");
    scanf("%d", &x);
    n++; // 链表长度增1
    L = DuList_insert(L, i, x);
    DuList_display(L, n);

    printf("3. 删除双向循环链表中第i个元素，并输出删除后的链表中各元素值。\n");
    printf("请输入删除元素的位置i：");
    scanf("%d", &i);
    n--; // 链表长度减1
    L = DuList_delete(L, i, &x);
    printf("被删除的元素是：%d\n", x);
    DuList_display(L, n);

    printf("4. 在双向循环链表中查找值为x元素，如果查找成功，则显示该元素在链表中的位置，否则显示该元素不存在。\n");
    i = -1; // 默认未找到
    printf("请输入要查找的元素x：");
    scanf("%d", &x);
    DuList_search_x(L, &i, &x, n);
    if (i == -1) {
        printf("没有该元素");
    } else {
        printf("%d在链表中的位置是：%d", x, i);
    }
    return 0;
}