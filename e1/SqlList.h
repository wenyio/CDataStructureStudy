#define MAX_LEN  30  // 线性表的最大长度

typedef struct {
    int elem[MAX_LEN]; // 顺序表中存放元素的数组，其中elem type为抽象数据类型，在程序具体实现时可以用任意类型代替
    int length;   // 顺序表的长度，即元素个数
} SqList;   // 顺序表的类型

/**
 * 顺序表插入函数
 * @param L
 * @param i
 * @param x
 * @return
 */
SqList SqList_insert(SqList L, int i, int x) {
    int j;
    if (i < 1 || i > L.length + 1)          // 插入位置不正确则出错
        printf("ERROR!");
    else if (L.length >= MAX_LEN)
        printf("OVERFLOW!");    // 顺序表L中已放满元素，再做插入操作则溢出
    else {
        for (j = L.length - 1; j >= i - 1; j--)
            L.elem[j + 1] = L.elem[j];  // 将第i个元素及后续元素位置向后移一位
        L.elem[i - 1] = x;  // 在第i个元素位置处插入新元素x
        L.length++;  // 顺序表L的长度加1
    }
    return L;
}

/**
 * 顺序表删除函数
 * @param L
 * @param i
 * @return
 */
SqList SqList_delete(SqList L, int i) {
    int j;
    if (i < 1 || i > L.length) printf("ERROR!");   // 删除位置不正确则出错
    else {
        for (j = i; j <= L.length - 1; j++)
            L.elem[j - 1] = L.elem[j];   // 将第i+1个元素及后继元素位置向前移一位
        L.length--;      // 顺序表L的长度减1
    }
    return L;
}

/**
 * 在顺序表中查找值为x的元素，如果找到，则函数返回该元素在顺序表中的位置，否则返回0
 * @param L
 * @param x
 * @return
 */
int SqList_search(SqList L, int x) {
    int i;
    // 从第一个元素开始依次将每个元素值与给定值x比较
    for (i = 1; i <= L.length && L.elem[i - 1] != x; i++);
    if (i <= L.length)
        return i;
    else
        return 0;
}

/**
 * 顺序表元素输出函数
 * @param L
 */
void SqList_display(SqList L) {
    int j;
    for (j = 0; j <= L.length - 1; j++)
        printf("%4d  ", L.elem[j]);
    printf("\n");
}

/**
 * 去除顺序表中重复的元素
 * @param L
 * @return
 */
SqList delSqList(SqList L) {
    int i = 0, j;
    while (i < L.length - 1)
        if (L.elem[i] == L.elem[i + 1])     // 相邻的两个元素比较相等
        {
            for (j = i + 1; j < L.length; j++)   // 删除相等的两个元素中前面那个元素
                L.elem[j - 1] = L.elem[j];
            L.length--;              // 有序顺序表的表长减1
        } else
            i++;
    return L;
}

/**
 * 顺序有序表的合并 TODO 非递增
 * @param LA
 * @param LB
 * @return LC
 */
SqList SqList_merge(SqList LA, SqList LB) {
    SqList LC;
    LC.length = LA.length + LB.length; // 新表的长度
    int *pc = LC.elem; // pc 指向新表第一个元素
    int *pa = LA.elem; // pa 指向A表第一个元素
    int *pb = LB.elem; // pb 指向B表第一个元素
    int pa_last = LA.elem[LA.length - 1]; // 指针pa_last指向LA的最后一个元素
    int pb_last = LB.elem[LB.length - 1]; // 指针pb_last指向LB的最后一个元素
    while ((*pa <= pa_last) && (*pb <= pb_last)) { // 都没有到达尾部
        if (*pa <= *pb) { // 如果 pa 小于 pb，将pa插入 pc，否则插入 pb
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while(*pa <= pa_last) { // pb 已到达表尾，将pa最后元素插入 pc
        *pc++ = *pa++;
    }
    while(*pb <= pb_last) { // pa 已到达表尾，将pb最后元素插入 pc
        *pc++ = *pb++;
    }
    return LC;
}