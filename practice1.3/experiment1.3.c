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
void Show(SqList *L)
{
	printf("顺序表中的元素是：\t");
	for (int i = 0; i < L->length; i++)
	{
		printf("%5d", L->elem[i]);
	}
	printf("\n");
}
void MergeList_Sq(SqList *La, SqList*Lb, SqList*Lc)
{//已知顺序线性表La,Lb的元素按值非递减排列
 //归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
	ElemType*pa, *pb, *pc,*pa_last,*pb_last;//声明5个指针变量
	pa = La->elem;
	pb = Lb->elem;
	Lc->listsize = Lc->length = La->length + Lb->length;
	pc = Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem)exit(OVERFLOW);//存储分配失败
	pa_last = La->elem + La->length - 1;//pa-last指向线性表La最后一个元素
	pb_last = Lb->elem + Lb->length - 1;//pb-last指向线性表Lb最后一个元素
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;//插入La中剩余元素
	while (pb <= pb_last)*pc++ = *pb++;//插入Lb中剩余元素
}
int main()
{
	SqList La,Lb,Lc;
    InitList_Sq(&La);
	InitList_Sq(&Lb);
    Create(&La);
	Create(&Lb);
	MergeList_Sq(&La, &Lb, &Lc);
	printf("归并后的顺序表");
	Show(&Lc);
	system("pause");
}