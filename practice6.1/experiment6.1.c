#include<stdio.h>
#define MAXSIZE 20

typedef int KeyType;//定义关键字类型为整数类型
typedef int InfoType;

typedef struct {
	KeyType key;//关键字项 
	InfoType otherinfo;//其他数据项 
}RedType;//记录类型 
typedef struct {
	RedType  r[MAXSIZE + 1];//用r[0] 做闲置或者做哨兵单元
	int length;//顺序表长度 
}SqList;//顺序表类型


void InsertSort(SqList *L)
{//对顺序表L做直接插入排序 
	int i, j;
	for (i = 2; i <= L->length; i++)
		if (L->r[i].key < L->r[i - 1].key)
		{
			L->r[0] = L->r[i];//复制为哨兵
			L->r[i] = L->r[i - 1];
			for (j = i - 2; L->r[0].key < L->r[j].key; --j)
				L->r[j + 1] = L->r[j];//记录后移 
			L->r[j + 1] = L->r[0]; //插入到正确的位置上 		
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
	SqList L;
	int i;
	printf("输入线性表的长度：");
	scanf_s("%d", &L.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	InsertSort(&L);
	printf("直接插入的排序结果是;");
	Show(L);
	system("pause");
	return 0;
}
