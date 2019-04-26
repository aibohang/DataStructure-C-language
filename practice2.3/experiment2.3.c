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
LinkList DeleteBetween(LinkList L, int mink, int maxk)
{//删除大于mink小于maxk的元素并释放空间
	if (mink > maxk)//判断输入的边界值是否合法
	{
		printf("the llue is wrong");
		exit(OVERFLOW);
	}
	LNode*p, *q;
	q = L->next;
	p = L;
	while (q->data<= mink)
	{//寻找要删除的结点所在下边界的位置
		p = q;
		q = p->next;
	}
	while (q&&q->data < maxk)
	{//寻找要删除的结点所在的下边界的位置
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
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的元素(尾插法创建单链表):");
	L = CreateList_L_Tail(n);
	printf("顺序表中元素是：");
	PrintList(L);
	printf("输入上、下界(空格间隔开):");
	scanf_s("%d%d", &mink, &maxk);
	L=DeleteBetween(L, mink, maxk);
	printf("删除后顺序表中元素是：");
	PrintList(L);
	system("pause");
	return 0;
}