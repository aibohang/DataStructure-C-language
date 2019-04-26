#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0
#define OK 1
#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表存储空间的分配增量
typedef  int  ElemType;
typedef  int  Status;
typedef struct {
	ElemType *elem;//存储空间基址
	int length;//线性表当前长度
	int listsize;//当前分配的存储容量（以sizeof(ElemType)为单位）
} SqList;
Status InitList_Sq(SqList *L)
{
	//构造空的线性表L
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);//存储分配失败
	L->length = 0;//空表长度为零
	L->listsize = LIST_INIT_SIZE;//初始存储容量
	return OK;
}
void Create(SqList *L)//创建
{
	//	SqList L;
		//InitList_Sq(&L);
	int n;
	int i = 0;
	printf("输入线性表中元素个数(少于100个):\n");
	while (scanf("%d", &n) && n > 100 || n < 0)
	{
		printf("数据不合法，请重新输入\n");
	}
	printf("请输入%d个数，用空格分开\n", n);
	while (n--)
	{
		scanf("%d", &L->elem[i]);
		i++;
		L->length++;
	}
}
Status InsertOrderList(SqList *L, int x)
{
	ElemType *newbase, *p;
	if (L->length >= L->listsize)
	{//当前存储空间已满，增加分配
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//存储分配失败
		L->elem = newbase;//新基址
		L->listsize += LISTINCREMENT;//增加存储容量
	}
	p = &(L->elem[L->length - 1]);//指向表尾元素的位置
	while (p >= &(L->elem[0]) && *p > x)
	{
		*(p + 1) = *p;
		p--;
	}
	*(p + 1) = x;
	L->length++;
	return OK;
}
void Show(SqList *L)
{
	printf("顺序表中的元素是：\t");
	for (int i = 0; i < L->length; i++)
	{
		printf("%5d", L->elem[i]);
	}
	printf("\n");
}
int main()
{
	ElemType  x;
	SqList L;
	InitList_Sq(&L);
	Create(&L);
	printf("输入要插入的元素:\n");
	scanf("%d", &x);
	InsertOrderList(&L, x);
	Show(&L);
	system("pause");
}