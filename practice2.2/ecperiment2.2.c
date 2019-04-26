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
LinkList  CreateList_L_Head(int n)
{
	LinkList L;
	LNode *p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//创建头节点，其next域置为NULL
	for (int i = n; i > 0; --i)//循环建立数据节点
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);//创建数据节点*p,输入元素的值
		p->next = L->next;//将*p插在原开始节点之前，头结点之后
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
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(尾插法创建单链表):");
	L = CreateList_L_Tail(n);
	printf("顺序表中元素是：");
	PrintList(L);
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(头插法创建单链表):");
	S = CreateList_L_Head(n);
	printf("顺序表中元素是：");
	PrintList(S);
	system("pause");
	return 0;
}