#include "stdio.h"
#include "SqlList.h"

SqList init() {
    SqList L;
    int j;
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("\n请输入顺序表中元素个数:");
    scanf("%d", &L.length);

    printf("请输入顺序表中各个元素:\n");
    for (j = 0; j <= L.length - 1; j++)
        scanf("%d", &L.elem[j]);
    return L;
}

/*
编程实现如下功能：
（1）根据输入顺序表的长度n和各个数据元素值建立一个顺序表，并输出顺序表中各元素值，观察输入的内容与输出的内容是否一致。
（2）在顺序表的第i个元素之前插入一个值为x的元素，并输出插入后的顺序表中各元素值。
（3）删除顺序表中第i个元素，并输出删除后的顺序表中各元素值。
（4）在顺序表中查找值为e的数据元素，如果查找成功，则显示“查找成功”和该元素在顺序表中的位置，否则显示“查找失败”。
*/
void e1_test() {
    SqList L = init();
    int i, x;

    printf("请输入插入操作位置:");
    scanf("%d", &i);

    printf("请输入需要插入的新元素:");
    scanf("%d", &x);

    L = SqList_insert(L, i, x);  // 调用顺序表插入函数
    SqList_display(L);  // 调用顺序表元素输出函数

    printf("请输入删除操作位置:");
    scanf("%d", &i);
    L = SqList_delete(L, i);   // 调用顺序表删除函数
    SqList_display(L);  // 调用顺序表元素输出函数

    printf("请输入查找的结点值:");
    scanf("%d", &x);
    if (SqList_search(L, x))  // 如果查找成功，则显示查找成功和找到的元素位置，否则显示查找不成功
        printf("  查找成功 --> %d 的坐标是 %d\n", x, SqList_search(L, x));
    else
        printf("  查找失败\n");

    printf("顺序表中元素：\n");
    SqList_display(L);
}

/*
① 根据输入的n个非递减的有序数据建立一个有序顺序表，并输出有序顺序表中各元素值。TODO 建立有序表
② 删除有序顺序表中所有的重复元素，并显示删除后的有序顺序表中各元素值。
 */
void e2_test() {
    SqList L = init();
    L = delSqList(L);
    printf("去重后顺序表中元素：\n");
    SqList_display(L);
}

/*
已知顺序有序表LA和LB的元素按值非递减排列，归并LA和LB得到新的顺序有序表LC，LC的元素按值非递增排列。
 */
void e3_test() {
    SqList LA = init();
    SqList LB = init();
    SqList LC = SqList_merge(LA, LB);
    printf("合并后如下：\n");
    SqList_display(LC);
}

/**
 * 主函数
 * @return
 */
int main() {

//    e1_test();
//    e2_test();
    e3_test();

    return 0;
}
