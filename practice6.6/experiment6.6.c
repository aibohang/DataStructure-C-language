#include<stdio.h>
#define MAX 10000
#define MAXSIZE 10
typedef int KeyType;
typedef int InfoType;

typedef struct {
	KeyType key;		//关键字项
	InfoType otherinfo;	// 其他数据项
} RedType;

typedef struct {
	RedType r[MAXSIZE + 1];//r[0]做闲置或者哨兵单元
	int length;			//顺序表长度
} SqList;				//顺序表类型
typedef SqList HeapType;//堆排序用顺序表存储表示 
void HeapAdjust(HeapType *H, int s, int m)
{
	//已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，
	//本函数调整H.r[s] 的关键字，使H.r[s..m]成为一个大顶堆（对其中记录的关键字而言）
	RedType rc;
	int j;
	rc = H->r[s];
	for (j = 2 * s; j <= m; j = j * 2)
	{//沿着key较大的孩子结点向下筛选
		if (j < m && (H->r[j].key < H->r[j + 1].key))
			j++;//j为key较大的记录的下标
		if (!(rc.key < H->r[j].key))
			break;
		H->r[s] = H->r[j];
		s = j;
	}
	H->r[s] = rc;//插入 
}

void HeapSort(HeapType *H)
{//对顺序表H进行堆排序 
	RedType temp;
	int i;
	for (i = H->length / 2; i > 0; --i)//把H.r[1..H.length] 建成大顶堆
		HeapAdjust(H, i, H->length);
	for (i = H->length; i > 1; --i)
	{
		temp = H->r[1];
		H->r[1] = H->r[i];
		H->r[i] = temp;//将堆顶记录和当前未经排序的子序列H.r[1..i]中最后一个记录相互交换
		HeapAdjust(H, 1, i - 1);//将H.r[1..i-1]重新调整为大顶堆 
	}
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
	HeapType H;
	int i;
	printf("输入线性表的长度：");
	scanf_s("%d", &H.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <= H.length; i++)
		scanf_s("%d", &H.r[i].key);

	HeapSort(&H);
	printf("堆排序结果是;");
	Show(H);
	system("pause");
	return 0;
}
