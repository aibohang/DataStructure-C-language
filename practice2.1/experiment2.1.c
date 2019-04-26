#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0
#define OK 1
typedef  int  ElemType;
typedef  int  Status;
typedef struct LNode {
	ElemType data;//������
	struct LNode *next;//ָ����
}LNode, *LinkList;
LinkList CreateList_L(int n)
{//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
	LNode *p;
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//����ͷ��㣬����������ΪNULL
	for (int i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½��
		scanf_s("%d", &p->data);//����Ԫ�ص�ֵ
		p->next = L->next;
		L->next = p;//���뵽��ͷ
	}
	return L;
}
Status ListInsert_L(LinkList L, int i, ElemType e)
{//�ڴ�ͷ���ĵ������Ա�L�ĵ�i��λ��֮ǰ����Ԫ��e
	LNode *p, *s;//�ṹ�����p,s
	int j;
	p = L;
	j = 0;
	while (p&&j < i - 1)
	{//Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)return ERROR;//iС��1���ߴ��ڱ���1
	s = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
	s->data = e;
	s->next = p->next;
	p->next = s;//����L��
	return OK;
}
Status ListDelete_L(LinkList L, int i)
{//�ٴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ��
	LNode *p, *q;
	int j = 0;
	p = L;
	while (p->next&&j < i - 1)
	{//Ѱ�ҵ�i����㣬����pָ����ǰ��
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)return ERROR;//ɾ��λ�ò�����
	q = p->next;
	p->next = q->next;//ɾ�����ͷŽ��
	free(q);
	return OK;
}
void PrintList(LinkList L)
{
	LNode* p;
	p = L->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int n, i, j;
	LinkList L;
	ElemType e;
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(���򴴽�������):");
	L = CreateList_L(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(L);
	printf("����Ҫ�����Ԫ�ص�λ�ã�");
	scanf_s("%d", &i);
	printf("����Ҫ�����Ԫ�ص�ֵ��");
	scanf_s("%d", &e);
	ListInsert_L(L, i, e);
	printf("������˳�������ǣ�");
	PrintList(L);
	printf("����Ҫɾ����Ԫ�ص�λ�ã�");
	scanf_s("%d", &j);
	ListDelete_L(L, j);
	printf("ɾ�����˳�������ǣ�");
	PrintList(L);
	system("pause");
	return 0;
}