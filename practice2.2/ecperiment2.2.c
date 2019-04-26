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
LinkList  CreateList_L_Head(int n)
{
	LinkList L;
	LNode *p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//����ͷ�ڵ㣬��next����ΪNULL
	for (int i = n; i > 0; --i)//ѭ���������ݽڵ�
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);//�������ݽڵ�*p,����Ԫ�ص�ֵ
		p->next = L->next;//��*p����ԭ��ʼ�ڵ�֮ǰ��ͷ���֮��
		L->next = p;
	}
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
int main()
{
	int n;
	LinkList L, S;
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(β�巨����������):");
	L = CreateList_L_Tail(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(L);
	printf("����Ҫ����˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(ͷ�巨����������):");
	S = CreateList_L_Head(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(S);
	system("pause");
	return 0;
}