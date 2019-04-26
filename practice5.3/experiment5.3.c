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

int Search_Seq(SSTable ST, KeyType key)
{//在顺序表中顺序查找其关键字等于key的数据元素，
//若找到，函数值为该元素在表中的位置，否则为0
	int i;
	ST.elem[0].key = key;//哨兵
	for (i = ST.length; !EQ(ST.elem[i].key, key); --i);//从后往前找
	if (i == 0)
		printf("该元素不在顺序表中");
	return i;//找不到时，i为0

}

Status EQ(ElemType a, ElemType b)
{
	if (a == b)
		return TRUE;
	else
		return FALSE;
}


Status CreateTable(SSTable *ST)
{
	printf("输入顺序表长度:");
	scanf_s("%d", &ST->length);
	ST->elem = (SElemType*)malloc((ST->length + 1) * sizeof(ElemType));
	printf("请输入表中各个元素的值:");
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
	n = Search_Seq(ST, key);
	printf("你要查找的元素在表中的位置是%d\n", n);
	system("pause");
	return 0;
}


