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
{//头插法创建带头结点的单链表
	DuLinkList L;
	DuLNode *s;
	int i;
	L = (DuLinkList)malloc(sizeof(DuLNode));//创建头结点
	L->prior = L->next = NULL;//前后指针域置为NULL
	for (i = 0; i < n; i++)
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		scanf_s("%d", &s->data);//创建数据结点*s
		s->next = L->next;//将*s插入到头结点之后
		if (L->next != NULL)//若L存在数据节点，修改前驱指针
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
	return L;
}
DuLinkList CreateListR(int n)
{//尾插法创建带头结点的单链表
	DuLinkList L;
	DuLNode*s, *r;
	int i;
	L = (DuLinkList)malloc(sizeof(DuLNode));//创建头结点
	r = L;//r始终指向尾结点，开始时指向头结点
	for (i = 0; i < n; i++)//循环建立数据节点
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		scanf_s("%d", &s->data);//创建数据节点*s
		r->next = s;
		s->prior = r;//将*s插入到*r之后
		r = s;//r指向尾节点
	}
	r->next = NULL;//尾结点next域置为NULL
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
{//双链表的插入算法
	int j = 0;
	DuLNode *p, *s;
	p = L;//p指向头结点
	while (j < i - 1 && p != NULL)//查找第i-1个结点*P
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//未找到第i-1个结点，返回FALSE
		return FALSE;
	else//新建结点*s将其插入到*p结点之后
	{
		s = (DuLinkList)malloc(sizeof(DuLNode));
		s->data = e;//创建新节点*s
		s->next = p->next;//在*p之后插入*s结点
		if (p->next != NULL)//若存在后继结点，则修改其前驱指针
			p->next->prior = s;
		s->prior = p;
		p->next = s;
		return TRUE;
	}
}
/*另外解法：在双链表中，可以查找第i个结点，
并在他前面插入一个结点*/
Status ListDelete(DuLinkList L, int i)
{
	int j = 0;//j设置为0
	DuLNode*p, *q;
	p = L;//p指向头结点
	while (j < i - 1 && p != NULL)//查找第i-1个结点*p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//未找到第i-1个结点
		return FALSE;
	else//找到第i-1个结点*p
	{
		q = p->next;//q指向第i个结点
		if (q == NULL)//当不存在第i个结点时返回FALSE
			return FALSE;
		p->next = q->next;//从双链表中删除*q结点
		if (p->next != NULL)//修改其前驱指针
			p->next->prior = p;
		free(q);//释放*q结点
		return TRUE;
	}
}
void Reverse(DuLinkList L)
{//双链表结点逆置
	DuLNode *p, *q;
	p = L->next;//p指向开头节点
	L->next = NULL;//构造只有头结点的双链表L
	while (p != NULL)//扫描L的数据节点
	{
		q = p->next;//用q保存其后继节点
		p->next = L->next;//采用头插法将*p结点插入
		if (L->next != NULL)//修改其前驱指针
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;//让p重新指向其后继节点
	}
}
int main()
{
	int n, i, j;
	ElemType e;
	DuLinkList L, S;
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的%d个元素(头插法创建单链表):", n);
	L = CreateListF(n);
	printf("顺序表中元素是：");
	PrintList(L);
	printf("输入插入的位置：");
	scanf_s("%d", &i);
	printf("输入要插入的值：");
	scanf_s("%d", &e);
	ListInsert(L, i, e);
	printf("插入后的线性链表是：");
	PrintList(L);
	printf("输入删除的位置：");
	scanf_s("%d", &j);
	ListDelete(L, j);
	printf("删除后的线性链表是：");
	PrintList(L);
	printf("输入要建立顺序链表的元素个数：");
	scanf_s("%d", &n);
	printf("输入顺序链表的%d个元素(尾插法创建单链表):", n);
	S = CreateListR(n);
	printf("顺序表中元素是：");
	PrintList(S);
	Reverse(S);
	printf("逆置后顺序双链表中元素是：");
	PrintList(S);
	system("pause");
	return 0;
}