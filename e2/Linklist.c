#include <stdio.h>
#include <malloc.h>
#include "Linklist.h"

void e2_1() {
    Linklist L = NULL;
    int i, x;
    L = create(L);/*���õ�����������*/
    printf("the Linklist is:\n");
    display(L); /*���õ�����Ԫ�����(����)����*/
    printf("please input the position  you want to insert:");/*��������������λ��*/
    scanf("%d", &i);
    printf("please input the node you want to insert:");/*����������Ҫ�����Ԫ��*/
    scanf("%d", &x);
    L = insert(L, i, x);/*���õ�������뺯��*/
    printf("the Linklist after inserted is:\n");
    display(L);/*���õ�����Ԫ�����(����)����*/
    printf("please input the node position you want to delete:"); /*��������ɾ������λ��*/
    scanf("%d", &i);
    L = delete(L, i); /*���õ�����ɾ������*/
    printf("the Linklist after deleted is:\n");
    display(L); /*���õ�����Ԫ�����(����)����*/
    printf("please input the position you want to search:"); /*�������������Ԫ�ص�λ��*/
    scanf("%d", &i);
    x = search(L, i);  /*���õ�������Һ���*/
    if (x)   /*������ҳɹ�������ʾ��i��Ԫ�ص�ֵ��������ʾ��i��Ԫ�ز�����*/
        printf("  the %dth elem is %d\n", i, x);
    else
        printf("  the %dth elem is not exsit\n");
}
/*
 �� �Ӽ����������ɸ��������Դ�����Ϊ˳����һ������ͷ���ĵ�����
 �� ����˵������еĸ�������Ԫ��ֵ��
 �� ����һ��x�ľ�������ֵ�����㲢���ش˵�������������ֵΪx�Ľ�����ֵ��
 */
void e2_2() {
    Linklist L = NULL;
    int i;
    L = create(L); // ���õ�����������
    printf("the Linklist is:\n");
    display(L); // ���õ�����Ԫ�����(����)����
    printf("please input the node you want to count: \n");
    scanf("%d", &i);
    printf("It appears %d times.", count(L, i));
}

int main() /*������*/
{
    setvbuf(stdout, NULL, _IONBF, 0);
//    e2_1();
    e2_2();
}
