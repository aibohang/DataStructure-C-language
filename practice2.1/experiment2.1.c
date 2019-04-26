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
LinkList CreateList_L(int n)
{//逆位序输入n个元素的值，建立带表头结点的单链线性表L
	LNode *p;
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//创建头结点，其数据域置为NULL
	for (int i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新结点
		scanf_s("%d", &p->data);//输入元素的值
		p->next = L->next;
		L->next = p;//插入到表头
	}
	return L;
}
Status ListInsert_L(LinkList L, int i, ElemType e)
{//在带头结点的单链线性表L的第i个位置之前插入元素e
	LNode *p, *s;//结构体变量p,s
	int j;
	p = L;
	j = 0;
	while (p&&j < i - 1)
	{//寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)return ERROR;//i小于1或者大于表长加1
	s = (LinkList)malloc(sizeof(LNode));//生成新节点
	s->data = e;
	s->next = p->next;
	p->next = s;//插入L中
	return OK;
}
Status ListDelete_L(LinkList L, int i)
{//再带头结点的单链线性表L中，删除第i个元素
	LNode *p, *q;
	int j = 0;
	p = L;
	while (p->next&&j < i - 1)
	{//寻找第i个结点，并另p指向其前驱
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)return ERROR;//删除位置不合理
	q = p->next;
	p->next = q->next;//删除并释放结点
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
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(逆序创建单链表):");
	L = CreateList_L(n);
	printf("顺序表中元素是：");
	PrintList(L);
	printf("输入要插入的元素的位置：");
	scanf_s("%d", &i);
	printf("输入要插入的元素的值：");
	scanf_s("%d", &e);
	ListInsert_L(L, i, e);
	printf("插入后的顺序链表是：");
	PrintList(L);
	printf("输入要删除的元素的位置：");
	scanf_s("%d", &j);
	ListDelete_L(L, j);
	printf("删除后的顺序链表是：");
	PrintList(L);
	system("pause");
	return 0;
}