#include <stdio.h>                         /*˳���Sqlist�Ķ���*/

#define MAX_LEN 50

typedef struct {
    int elem[MAX_LEN];
    int length;
} SqList;

/* ˳���Ԫ��������� */
void SqList_display(SqList L) {
    int j;
    for (j = 0; j <= L.length - 1; j++)
        printf("%4d  ", L.elem[j]);
    printf("\n");
}

/**
 * ɾ��˳������Ԫ��
 * @param L ˳���
 * @param i ɾ����λ��
 * @param e ��������
 * @return SqList
 */
SqList ListDelete_Sq(SqList L, int i, int *e) {
    int j;
    if ((i < 1) || (i > L.length)) {
        return L; // iֵ���Ϸ�
    }

    *e = L.elem[i - 1]; // ����ɾ����Ԫ�ر�����e��

    for (j = i; j <= L.length - 1; j++) {
        L.elem[j - 1] = L.elem[j]; // ��ɾ��Ԫ��֮���Ԫ��ǰ��
    }

    --L.length; // ����1
    return L;
}

/* ������ gcc 4.7 ���۴�������ж���printf��������ִ��scanf */
int main() {
    SqList L;
    int i, j, e;

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("����˳�����Ԫ�ظ���: \n");
//    fflush(stdout);
    scanf("%d", &L.length);

    printf("����˳����и���Ԫ��: \n");
//    fflush(stdout);
    for (j = 0; j <= L.length - 1; j++) {
        scanf("%d", &L.elem[j]);
    }

    printf("������Ҫɾ����λ��: \n");
//    fflush(stdout);
    scanf("%d", &i);
    L = ListDelete_Sq(L, i, &e);
    printf("ɾ����: %d \nʣ��Ԫ�����£�\n", e);
    SqList_display(L);   /*����˳���Ԫ���������*/

    return 0;
}