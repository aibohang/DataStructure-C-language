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
	ElemType data;//数据域
	struct LNode *next;//指针域
}LNode, *LinkList;
LinkList  CreateList_L_Tail(int n)
{//尾插法建立单链表
	LinkList L;
	LNode *p, *r;
	L = (LinkList)malloc(sizeof(LNode));//创建头结点
	r = L;//r始终指向尾节点，开始时指向头结点
	for (int i = n; i > 0; i--)
	{//循环建立数据节点
		p = (LinkList)malloc(sizeof(LNode));//生成新结点
		scanf_s("%d", &p->data);//创建数据节点*p,输入元素的值
		r->next = p;//将*p插入到*r之后
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
		if (pa->data < pb->data)//pa所指的结点连到pc，pa指针后移
		{
			pan = pa->next;
			pa->next = pc->next;
			pc->next = pa;
			pa = pan;
		}
		else//pb所指的结点链到pc,pb指针后移
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
{//就地逆置单链表L
	LNode*p, *pn;
	p = L->next;
	if (!p || !p->next)
		return ERROR;
	pn = p->next;//pn指向p的直接后继结点
	p->next = NULL;//令首元结点的指针域为空
	while (pn)
	{
		p = pn;
		pn = pn->next;//指针后移
		p->next = L->next;
		L->next = p;//插入结点之后
	}
}
int main()
{
	int n;
	LinkList L, S, K;
	printf("输入第一个要建立的顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(尾插法创建单链表):");
	L = CreateList_L_Tail(n);
	printf("顺序表中元素是：");
	PrintList(L);
	printf("输入第二个要建立的顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(尾插法创建单链表):");
	S = CreateList_L_Tail(n);
	printf("顺序表中元素是：");
	PrintList(S);
	printf("归并后的线性链表是：");
	K = MergeList(L, S);
	PrintList(K);
	printf("逆置后的线性表是：");
	InvertLinkList(K);
	PrintList(K);
	system("pause");
	return 0;
}