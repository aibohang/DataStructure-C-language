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
LinkList  CreateList_L_Tail(int n)
{//β�巨����������
	LinkList L;
	LNode *p, *r;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	r = L;//rʼ��ָ��β�ڵ㣬��ʼʱָ��ͷ���
	for (int i = n; i > 0; i--)
	{//ѭ���������ݽڵ�
		p = (LinkList)malloc(sizeof(LNode));//�����½��
		scanf_s("%d", &p->data);//�������ݽڵ�*p,����Ԫ�ص�ֵ
		r->next = p;//��*p���뵽*r֮��
		r = p;
	}
	r->next = NULL;
	return L;
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
LinkList DeleteBetween(LinkList L, int mink, int maxk)
{//ɾ������minkС��maxk��Ԫ�ز��ͷſռ�
	if (mink > maxk)//�ж�����ı߽�ֵ�Ƿ�Ϸ�
	{
		printf("the llue is wrong");
		exit(OVERFLOW);
	}
	LNode*p, *q;
	q = L->next;
	p = L;
	while (q->data<= mink)
	{//Ѱ��Ҫɾ���Ľ�������±߽��λ��
		p = q;
		q = p->next;
	}
	while (q&&q->data < maxk)
	{//Ѱ��Ҫɾ���Ľ�����ڵ��±߽��λ��
		p->next = p->next->next;
		free(q);
		q = p->next;
	}
	return L;
}
int main()
{
	int n, mink, maxk;
	LinkList L;
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(β�巨����������):");
	L = CreateList_L_Tail(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(L);
	printf("�����ϡ��½�(�ո�����):");
	scanf_s("%d%d", &mink, &maxk);
	L=DeleteBetween(L, mink, maxk);
	printf("ɾ����˳�����Ԫ���ǣ�");
	PrintList(L);
	system("pause");
	return 0;
}