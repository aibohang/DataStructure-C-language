#include<stdio.h>

#define MAXSIZE 10
typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;		//关键字项
	InfoType otherinfo;	// 其他数据项 
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];//r[0]做闲置或者哨兵单元
	int length;			//顺序表长度 
}SqList;				//顺序表类型

int Partition(SqList *L, int low, int high)
{//交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回所在位置
  //此时在他之前的（后）的记录均不大（小）于他 
	int pivokey;
	L->r[0] = L->r[low];//用子表的第一个记录做枢轴记录
	pivokey = L->r[low].key; //枢轴记录关键字
	while (low < high)
	{//从表的两端交替的向中间扫描 

		while (low < high&&L->r[high].key >= pivokey)
		{
			--high;//high指针指向的元素比枢轴大，high指针就向前移动 
		}
		L->r[low] = L->r[high];//将比枢轴记录小的记录移动到底端 

		while (low < high&&L->r[low].key <= pivokey)
		{
			++low;//low指针指向的元素比枢轴小，low指针就向后移动
		}
		L->r[high] = L->r[low];//将比枢轴大的记录移动到后端 	   

	}
	L->r[low] = L->r[0];//枢轴记录到位 
	return low;
}

void QSort(SqList *L, int low, int high)
{//对顺序表L中的子序列 L.r[low..high]做快速排序 
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);//将L一分为二 
		QSort(L, low, pivotloc - 1);//对低子表递归排序，pivotloc是枢轴位置
		QSort(L, pivotloc + 1, high);//对高子表递归排序 		
	}
}

void QuickSort(SqList *L)
{//对顺序表L进行快速排序 
	QSort(L, 1, L->length);
}

void Show(SqList L)
{
	int i;
	for (i = 1; i <= L.length; i++)
		printf("%4d", L.r[i].key);
	printf("\n");
}

int main()
{
	SqList L;
	int i;
	printf("输入线性表的长度：");
	scanf_s("%d", &L.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	QuickSort(&L);
	printf("快速排序结果是;");
	Show(L);
	system("pause");
	return 0;
}
