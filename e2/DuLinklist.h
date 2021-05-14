#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior; // ָ��ֱ��ǰ��ָ����
    struct DuLNode *next; // ָ��ֱ�Ӻ��ָ����
} DuLNode, *DuLinklist;

/**
 * ����n������������nΪ����������Щ������Ϊdata����β�巨����һ����ͷ����˫��ѭ������ĺ���
 * @param L
 * @param n
 * @return
 */
DuLinklist DuList_create(DuLinklist L, int n) {
    DuLinklist r, p;
    L = (DuLinklist) malloc(sizeof(DuLNode)); // Ϊͷ������ռ�
    L->next = L->prior = L; // ʹͷ���ĺ��ָ���ǰ��ָ�붼ָ�������γɿյ�˫��ѭ������
    r = L; // βָ���ʼָ��ͷ���
    printf("�����������Ԫ�أ�");
    for (int i = 0; i < n; i++) {
        p = (DuLinklist) malloc(sizeof(DuLNode));// Ϊһ���½�����ռ�
        scanf("%d", &p->data); // �Ӽ�������ֵ�����������½����������
        p->next = r->next; // �½����ָ��ָ��β���r�ĺ�̽��
        p->prior = r;    // �½���ǰ��ָ��ָ��β���r
        r->next = p;  // β���ĺ��ָ��ָ���½��
        r = p;      // βָ��ָ���½�㣬���½���Ϊβ���
    }
    L->prior = r;    // ʹβ����Ϊͷ����ǰ�����
    return L;
}

/**
 * ˳���ӡ������������ͳ���
 * @param L
 * @param n
 */
void DuList_display(DuLinklist L, int n) {
    printf("����Ԫ�طֱ��ǣ�\n");
    DuLinklist r = L->next;
    for (int i = 0; i < n; i++) {
        printf("%d ", r->data);
        r = r->next;
    }
    printf("\n");
}

/**
 * �ڴ�ͷ����˫��ѭ������L�в��ҵ�i��Ԫ�أ�������ҳɹ�����e������ֵ
 * @param L
 * @param i
 * @return
 */
ElemType DuList_search(DuLinklist L, int i, ElemType e) {
    DuLinklist p;
    int j = 1; // ����������ֵΪ1
    p = L->next;  // ʹָ��pָ���1��Ԫ�ؽ��
    while (p != L && j < i)  // ˳�ź��ָ����ҵ�i��Ԫ�ؽ��
    {
        p = p->next;
        j++;
    }
    if (j != i)
        return NULL;  // ���iֵ���Ϸ�����iֵС��1����ڱ��������
    e = p->data;    // �����i��Ԫ�ش��ڣ��򽫸�Ԫ��ֵ����e
    return e;
}

/**
 * �ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ������Ԫ��x
 * @param L
 * @param i
 * @param x
 * @return
 */
DuLinklist DuList_insert(DuLinklist L, int i, ElemType x) {
    int j = 1;
    DuLinklist p, s;
    p = L->next;
    while (p != L && j < i) // Ѱ�Ҳ���λ�ã���ʹpָ�����λ�õĽ�㣬��L�еĵ�i�����
    {
        p = p->next;
        ++j;
    }
    if (j != i)
        return NULL;  // ��λ�ò���ȷ,��iС��1����ڱ�ĳ��ȼ�1�������
    s = (DuLinklist) malloc(sizeof(DuLNode)); // Ϊһ���½��s����ռ�
    s->data = x;   // Ϊ�½��������ֵ
    // ������������������޸��������½��s���뵽p���֮ǰ
    s->next = p;
    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    return L;
}

/**
 * �ڴ�ͷ����˫��ѭ������L�У�ɾ����i��Ԫ�ؽ�㣬����x������ֵ
 * @param L
 * @param i
 * @param x
 * @return
 */
DuLinklist DuList_delete(DuLinklist L, int i, ElemType *x) {
    DuLinklist p, q;
    int j = 1;
    p = L->next;
    j = 1;
    while (p != L && j < i) // Ѱ�ұ�ɾ��㣬��ʹpָ��ɾ����ǰ��
    {
        p = p->next;
        ++j;
    }
    if (j != i)
        return NULL;   // ��λ�ò���ȷ����iС��1����ڱ��������
    q = p;   // ���±�ɾ���
    p->prior->next = p->next;   // �޸���ʹ��p������������
    p->next->prior = p->prior;
    *x = q->data;
    printf("ɾ����Ԫ���ǣ�%d\n", *x);
    free(q);  // �ͷű�ɾ���ռ�
    return L;
}

/**
 * ��˫��ѭ�������в���ֵΪxԪ�أ�������ҳɹ�������ʾ��Ԫ���������е�λ�ã�������ʾ��Ԫ�ز����ڡ�
 * @param L ����
 * @param i Ԫ���������е�λ��
 * @param x Ҫ���ҵ�Ԫ��
 * @param n Ԫ�صĳ��ȣ���ֹ��ѭ��
 * @return
 */
void DuList_search_x(DuLinklist L, int *i, ElemType *x, int n) {
    if (!L || n <= 0) {
        return;
    }
    DuLinklist p = L->next;
    for (int j = 0; j < n; j++) {
        if (p->data == *x) {
            *i = j + 1;
            break;
        }
        p = p->next;
    }
}