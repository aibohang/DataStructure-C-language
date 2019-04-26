#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0
#define OK 1
typedef  int  ElemType;
typedef  int  Status;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode, *DuLinkList;
DuLinkList CreateListF(int n)
{//ͷ�巨������ͷ���ĵ�����
	DuLinkList L;
	DuLNode *s;
	int i;
	L = (DuLinkList)malloc(sizeof(DuLNode));//����ͷ���
	L->prior = L->next = NULL;//ǰ��ָ������ΪNULL
	for (i = 0; i < n; i++)
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		scanf_s("%d", &s->data);//�������ݽ��*s
		s->next = L->next;//��*s���뵽ͷ���֮��
		if (L->next != NULL)//��L�������ݽڵ㣬�޸�ǰ��ָ��
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
	return L;
}
DuLinkList CreateListR(int n)
{//β�巨������ͷ���ĵ�����
	DuLinkList L;
	DuLNode*s, *r;
	int i;
	L = (DuLinkList)malloc(sizeof(DuLNode));//����ͷ���
	r = L;//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (i = 0; i < n; i++)//ѭ���������ݽڵ�
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		scanf_s("%d", &s->data);//�������ݽڵ�*s
		r->next = s;
		s->prior = r;//��*s���뵽*r֮��
		r = s;//rָ��β�ڵ�
	}
	r->next = NULL;//β���next����ΪNULL
	return L;
}
void PrintList(DuLinkList L)
{
	DuLNode* p;
	p = L->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
Status ListInsert(DuLinkList L, int i, ElemType e)
{//˫����Ĳ����㷨
	int j = 0;
	DuLNode *p, *s;
	p = L;//pָ��ͷ���
	while (j < i - 1 && p != NULL)//���ҵ�i-1�����*P
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//δ�ҵ���i-1����㣬����FALSE
		return FALSE;
	else//�½����*s������뵽*p���֮��
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		s->data = e;//�����½ڵ�*s
		s->next = p->next;//��*p֮�����*s���
		if (p->next != NULL)//�����ں�̽�㣬���޸���ǰ��ָ��
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return TRUE;
	}
}
/*����ⷨ����˫�����У����Բ��ҵ�i����㣬
������ǰ�����һ�����*/
Status ListDelete(DuLinkList L, int i)
{
	int j = 0;//j����Ϊ0
	DuLNode*p, *q;
	p = L;//pָ��ͷ���
	while (j < i - 1 && p != NULL)//���ҵ�i-1�����*p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//δ�ҵ���i-1�����
		return FALSE;
	else//�ҵ���i-1�����*p
	{
		q = p->next;//qָ���i�����
		if (q == NULL)//�������ڵ�i�����ʱ����FALSE
			return FALSE;
		p->next = q->next;//��˫������ɾ��*q���
		if (p->next != NULL)//�޸���ǰ��ָ��
			p->next->prior = p;
		free(q);//�ͷ�*q���
		return TRUE;
	}
}
void Reverse(DuLinkList L)
{//˫����������
	DuLNode *p, *q;
	p = L->next;//pָ��ͷ�ڵ�
	L->next = NULL;//����ֻ��ͷ����˫����L
	while (p != NULL)//ɨ��L�����ݽڵ�
	{
		q = p->next;//��q�������̽ڵ�
		p->next = L->next;//����ͷ�巨��*p������
		if (L->next != NULL)//�޸���ǰ��ָ��
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;//��p����ָ�����̽ڵ�
	}
}
int main()
{
	int n, i, j;
	ElemType e;
	DuLinkList L, S;
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������%d��Ԫ��(ͷ�巨����������):", n);
	L = CreateListF(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(L);
	printf("��������λ�ã�");
	scanf_s("%d", &i);
	printf("����Ҫ�����ֵ��");
	scanf_s("%d", &e);
	ListInsert(L, i, e);
	printf("���������������ǣ�");
	PrintList(L);
	printf("����ɾ����λ�ã�");
	scanf_s("%d", &j);
	ListDelete(L, j);
	printf("ɾ��������������ǣ�");
	PrintList(L);
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������%d��Ԫ��(β�巨����������):", n);
	S = CreateListR(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(S);
	Reverse(S);
	printf("���ú�˳��˫������Ԫ���ǣ�");
	PrintList(S);
	system("pause");
	return 0;
}