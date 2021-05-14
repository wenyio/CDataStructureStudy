typedef struct LNode {
    int data;
    struct Lnode *next;
} LNode, *Linklist;

Linklist create(Linklist L)  /*������������ */
{
    int node;
    Linklist p;
    L = (Linklist) malloc(sizeof(LNode));
    L->next = NULL;
    printf("\nplease input the node(end with 0):\n");  /*�����������Ա��и���Ԫ�أ���0����*/
    scanf("%d", &node);
    while (node != 0) {
        p = (Linklist) malloc(sizeof(LNode));
        if (!p) return NULL;
        p->data = node;
        p->next = L->next;
        L->next = p;
        scanf("%d", &node);
    }
    return L;
}

Linklist insert(Linklist L, int i, int x)  /*��������뺯��*/
{
    int j;
    Linklist p, s;
    p = L;
    j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == NULL || j > i - 1)
        printf("\n ERROR position!\n");
    else {
        s = (Linklist) malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
    return L;
}

Linklist delete(Linklist L, int i)  /*������ɾ������*/
{
    int j, x;
    Linklist p, q;
    p = L;
    j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == NULL || j > i - 1)
        printf("\n ERROE position!\n");
    else {
        q = p->next;
        p->next = q->next;
        x = q->data;
        printf("the delete data is:%d\n", x);
        free(q);
    }
    return L;
}

int search(Linklist L, int i) /*�����ϵĲ��Һ���*/
{
    Linklist p;
    int j;
    p = L->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p && j > i)
        return 0;   /*���iֵ���Ϸ�����iֵС��1����ڱ�����������0ֵ*/
    else
        return (p->data);    /*���������ص�i��Ԫ�ص�ֵ*/
}

void display(Linklist L)  /*������Ԫ���������*/
{
    Linklist p;
    p = L->next;
    while (p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * ͳ��������i���ֵĴ���
 * @param L
 * @param i
 * @return ���ֵĴ���
 */
int count(Linklist L, int i) {
    int result = 0;
    Linklist p;
    p = L->next;
    while (p != NULL) {
        if (p->data == i) // �����i��� result��+1
            result++;
        p = p->next;
    }
    return result;
}
