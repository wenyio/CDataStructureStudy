#include <stdio.h>                         /*顺序表Sqlist的定义*/

#define MAX_LEN 50

typedef struct {
    int elem[MAX_LEN];
    int length;
} SqList;

/* 顺序表元素输出函数 */
void SqList_display(SqList L) {
    int j;
    for (j = 0; j <= L.length - 1; j++)
        printf("%4d  ", L.elem[j]);
    printf("\n");
}

/**
 * 删除顺序表里的元素
 * @param L 顺序表
 * @param i 删除的位置
 * @param e 用作回收
 * @return SqList
 */
SqList ListDelete_Sq(SqList L, int i, int *e) {
    int j;
    if ((i < 1) || (i > L.length)) {
        return L; // i值不合法
    }

    *e = L.elem[i - 1]; // 将欲删除的元素保留在e中

    for (j = i; j <= L.length - 1; j++) {
        L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
    }

    --L.length; // 表长减1
    return L;
}

/* 主函数 gcc 4.7 无论代码段中有多少printf，总是先执行scanf */
int main() {
    SqList L;
    int i, j, e;

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("输入顺序表中元素个数: \n");
//    fflush(stdout);
    scanf("%d", &L.length);

    printf("输入顺序表中各个元素: \n");
//    fflush(stdout);
    for (j = 0; j <= L.length - 1; j++) {
        scanf("%d", &L.elem[j]);
    }

    printf("请输入要删除的位置: \n");
//    fflush(stdout);
    scanf("%d", &i);
    L = ListDelete_Sq(L, i, &e);
    printf("删除了: %d \n剩余元素如下：\n", e);
    SqList_display(L);   /*调用顺序表元素输出函数*/

    return 0;
}