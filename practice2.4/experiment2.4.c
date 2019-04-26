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
LinkList MergeList(LinkList a, LinkList b)
{
	LNode *pa, *pb, *pc, *pan, *pbn;
	pa = a->next;
	pb = b->next;
	pc = a;
	pc->next = NULL;
	while (pa&&pb)
	{
		if (pa->data < pb->data)//pa��ָ�Ľ������pc��paָ�����
		{
			pan = pa->next;
			pa->next = pc->next;
			pc->next = pa;
			pa = pan;
		}
		else//pb��ָ�Ľ������pc,pbָ�����
		{
			pbn = pb->next;
			pb->next = pc->next;
			pc->next = pb;
			pb = pbn;
		}
	}
	while (pa)
	{
		pan = pa->next;
		pa->next = pc->next;
		pc->next = pa;
		pa = pan;
	}
	while (pb)
	{
		pbn = pb->next;
		pb->next = pc->next;
		pc->next = pb;
		pb = pbn;
	}
	free(pb);
	return pc;
}
void InvertLinkList(LinkList L)
{//�͵����õ�����L
	LNode*p, *pn;
	p = L->next;
	if (!p || !p->next)
		return ERROR;
	pn = p->next;//pnָ��p��ֱ�Ӻ�̽��
	p->next = NULL;//����Ԫ����ָ����Ϊ��
	while (pn)
	{
		p = pn;
		pn = pn->next;//ָ�����
		p->next = L->next;
		L->next = p;//������֮��
	}
}
int main()
{
	int n;
	LinkList L, S, K;
	printf("�����һ��Ҫ������˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(β�巨����������):");
	L = CreateList_L_Tail(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(L);
	printf("����ڶ���Ҫ������˳�������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("����˳�������Ԫ��(β�巨����������):");
	S = CreateList_L_Tail(n);
	printf("˳�����Ԫ���ǣ�");
	PrintList(S);
	printf("�鲢������������ǣ�");
	K = MergeList(L, S);
	PrintList(K);
	printf("���ú�����Ա��ǣ�");
	InvertLinkList(K);
	PrintList(K);
	system("pause");
	return 0;
}