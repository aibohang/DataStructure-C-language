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
	while (scanf_s("%d", &n) && n > 100 || n < 0)
	{
		printf("数据不合法，请重新输入\n");
	}
	printf("请输入%d个数，用空格分开\n", n);
	while (n--)
	{
		scanf_s("%d", &L->elem[i]);
		i++;
		L->length++;
	}
}
void Reverse(SqList *L)
{
	int temp;
	for (int i = 0; i < (L->length - 1) / 2; i++)
	{
		temp = L->elem[i];
		L->elem[i] = L->elem[L->length - 1 - i];
		L->elem[L->length - 1 - i] = temp;
	}
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
	SqList L;
	InitList_Sq(&L);
	Create(&L);
	Show(&L);
	printf("逆置后的顺序表如下所示：\n");
	Reverse(&L);
	Show(&L);
	system("pause");
}