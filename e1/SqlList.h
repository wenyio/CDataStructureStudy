#define MAX_LEN  30  // ���Ա����󳤶�

typedef struct {
    int elem[MAX_LEN]; // ˳����д��Ԫ�ص����飬����elem typeΪ�����������ͣ��ڳ������ʵ��ʱ�������������ʹ���
    int length;   // ˳���ĳ��ȣ���Ԫ�ظ���
} SqList;   // ˳��������

/**
 * ˳�����뺯��
 * @param L
 * @param i
 * @param x
 * @return
 */
SqList SqList_insert(SqList L, int i, int x) {
    int j;
    if (i < 1 || i > L.length + 1)          // ����λ�ò���ȷ�����
        printf("ERROR!");
    else if (L.length >= MAX_LEN)
        printf("OVERFLOW!");    // ˳���L���ѷ���Ԫ�أ�����������������
    else {
        for (j = L.length - 1; j >= i - 1; j--)
            L.elem[j + 1] = L.elem[j];  // ����i��Ԫ�ؼ�����Ԫ��λ�������һλ
        L.elem[i - 1] = x;  // �ڵ�i��Ԫ��λ�ô�������Ԫ��x
        L.length++;  // ˳���L�ĳ��ȼ�1
    }
    return L;
}

/**
 * ˳���ɾ������
 * @param L
 * @param i
 * @return
 */
SqList SqList_delete(SqList L, int i) {
    int j;
    if (i < 1 || i > L.length) printf("ERROR!");   // ɾ��λ�ò���ȷ�����
    else {
        for (j = i; j <= L.length - 1; j++)
            L.elem[j - 1] = L.elem[j];   // ����i+1��Ԫ�ؼ����Ԫ��λ����ǰ��һλ
        L.length--;      // ˳���L�ĳ��ȼ�1
    }
    return L;
}

/**
 * ��˳����в���ֵΪx��Ԫ�أ�����ҵ����������ظ�Ԫ����˳����е�λ�ã����򷵻�0
 * @param L
 * @param x
 * @return
 */
int SqList_search(SqList L, int x) {
    int i;
    // �ӵ�һ��Ԫ�ؿ�ʼ���ν�ÿ��Ԫ��ֵ�����ֵx�Ƚ�
    for (i = 1; i <= L.length && L.elem[i - 1] != x; i++);
    if (i <= L.length)
        return i;
    else
        return 0;
}

/**
 * ˳���Ԫ���������
 * @param L
 */
void SqList_display(SqList L) {
    int j;
    for (j = 0; j <= L.length - 1; j++)
        printf("%4d  ", L.elem[j]);
    printf("\n");
}

/**
 * ȥ��˳������ظ���Ԫ��
 * @param L
 * @return
 */
SqList delSqList(SqList L) {
    int i = 0, j;
    while (i < L.length - 1)
        if (L.elem[i] == L.elem[i + 1])     // ���ڵ�����Ԫ�رȽ����
        {
            for (j = i + 1; j < L.length; j++)   // ɾ����ȵ�����Ԫ����ǰ���Ǹ�Ԫ��
                L.elem[j - 1] = L.elem[j];
            L.length--;              // ����˳���ı���1
        } else
            i++;
    return L;
}

/**
 * ˳�������ĺϲ� TODO �ǵ���
 * @param LA
 * @param LB
 * @return LC
 */
SqList SqList_merge(SqList LA, SqList LB) {
    SqList LC;
    LC.length = LA.length + LB.length; // �±�ĳ���
    int *pc = LC.elem; // pc ָ���±��һ��Ԫ��
    int *pa = LA.elem; // pa ָ��A���һ��Ԫ��
    int *pb = LB.elem; // pb ָ��B���һ��Ԫ��
    int pa_last = LA.elem[LA.length - 1]; // ָ��pa_lastָ��LA�����һ��Ԫ��
    int pb_last = LB.elem[LB.length - 1]; // ָ��pb_lastָ��LB�����һ��Ԫ��
    while ((*pa <= pa_last) && (*pb <= pb_last)) { // ��û�е���β��
        if (*pa <= *pb) { // ��� pa С�� pb����pa���� pc��������� pb
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while(*pa <= pa_last) { // pb �ѵ����β����pa���Ԫ�ز��� pc
        *pc++ = *pa++;
    }
    while(*pb <= pb_last) { // pa �ѵ����β����pb���Ԫ�ز��� pc
        *pc++ = *pb++;
    }
    return LC;
}