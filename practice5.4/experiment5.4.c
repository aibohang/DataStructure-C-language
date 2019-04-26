#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef int KeyType;
typedef struct {
	KeyType key;//关键字域
						//其他域
}SElemType;

typedef struct {
	SElemType *elem;//数据元素存储空间基址，建表时按照实际长度分配，0号元素留空
	int length;//表长度
}SSTable;
Status EQ(ElemType a, ElemType b)
{
	if (a == b)
		return OK;
	else
		return FALSE;
}
Status LT(ElemType a, ElemType b)
{
	if (a < b)
		return OK;
	else
		return FALSE;
}

int Search_Bin(SSTable ST, KeyType key)
{//在有序查找表中折半查找其关键字等于key的数据元素，若找到，则函数值
//为该元素在表中的位置，否则为0
	int low, high, mid;
	low = 1;
	high = ST.length;//置区间初值
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid].key))
			return mid;//找到待查元素
		else if (LT(key, ST.elem[mid].key))
			high = mid - 1;//继续在前半区间进行查找
		else
			low = mid + 1;//继续在后半区间进行查找
	}
	return 0;//顺序表中不存在待查元素
}


Status CreateTable(SSTable *ST)
{
	printf("输入顺序表长度：");
	scanf_s("%d", &ST->length);
	ST->elem = (SElemType*)malloc((ST->length + 1) * sizeof(ElemType));
	printf("请输入表中各个元素的值：");
	for (int i = 1; i <= ST->length; i++)
	{
		scanf_s("%d", &ST->elem[i].key);
	}
	return OK;
}

int main()
{
	SSTable ST;
	int  key, n;
	CreateTable(&ST);
	printf("请输入你要查找的值：");
	scanf_s("%d", &key);
	n = Search_Bin(ST, key);
	printf("你要查找的元素在表中的位置是%d\n", n);
	system("pause");
	return 0;
}

