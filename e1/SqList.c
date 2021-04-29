#include "stdio.h"
#include "SqlList.h"

SqList init() {
    SqList L;
    int j;
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("\n������˳�����Ԫ�ظ���:");
    scanf("%d", &L.length);

    printf("������˳����и���Ԫ��:\n");
    for (j = 0; j <= L.length - 1; j++)
        scanf("%d", &L.elem[j]);
    return L;
}

/*
���ʵ�����¹��ܣ�
��1����������˳���ĳ���n�͸�������Ԫ��ֵ����һ��˳��������˳����и�Ԫ��ֵ���۲����������������������Ƿ�һ�¡�
��2����˳���ĵ�i��Ԫ��֮ǰ����һ��ֵΪx��Ԫ�أ������������˳����и�Ԫ��ֵ��
��3��ɾ��˳����е�i��Ԫ�أ������ɾ�����˳����и�Ԫ��ֵ��
��4����˳����в���ֵΪe������Ԫ�أ�������ҳɹ�������ʾ�����ҳɹ����͸�Ԫ����˳����е�λ�ã�������ʾ������ʧ�ܡ���
*/
void e1_test() {
    SqList L = init();
    int i, x;

    printf("������������λ��:");
    scanf("%d", &i);

    printf("��������Ҫ�������Ԫ��:");
    scanf("%d", &x);

    L = SqList_insert(L, i, x);  // ����˳�����뺯��
    SqList_display(L);  // ����˳���Ԫ���������

    printf("������ɾ������λ��:");
    scanf("%d", &i);
    L = SqList_delete(L, i);   // ����˳���ɾ������
    SqList_display(L);  // ����˳���Ԫ���������

    printf("��������ҵĽ��ֵ:");
    scanf("%d", &x);
    if (SqList_search(L, x))  // ������ҳɹ�������ʾ���ҳɹ����ҵ���Ԫ��λ�ã�������ʾ���Ҳ��ɹ�
        printf("  ���ҳɹ� --> %d �������� %d\n", x, SqList_search(L, x));
    else
        printf("  ����ʧ��\n");

    printf("˳�����Ԫ�أ�\n");
    SqList_display(L);
}

/*
�� ���������n���ǵݼ����������ݽ���һ������˳������������˳����и�Ԫ��ֵ��TODO ���������
�� ɾ������˳��������е��ظ�Ԫ�أ�����ʾɾ���������˳����и�Ԫ��ֵ��
 */
void e2_test() {
    SqList L = init();
    L = delSqList(L);
    printf("ȥ�غ�˳�����Ԫ�أ�\n");
    SqList_display(L);
}

/*
��֪˳�������LA��LB��Ԫ�ذ�ֵ�ǵݼ����У��鲢LA��LB�õ��µ�˳�������LC��LC��Ԫ�ذ�ֵ�ǵ������С�
 */
void e3_test() {
    SqList LA = init();
    SqList LB = init();
    SqList LC = SqList_merge(LA, LB);
    printf("�ϲ������£�\n");
    SqList_display(LC);
}

/**
 * ������
 * @return
 */
int main() {

//    e1_test();
//    e2_test();
    e3_test();

    return 0;
}
