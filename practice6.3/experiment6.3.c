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


void BubbleSort(SqList *L)//冒泡排序 
{
	int i, j, temp;
	for (i = 0; i <= L->length; i++)

		for (j = 0; j <= L->length - i; j++)
		{
			if (L->r[j].key > L->r[j + 1].key)
			{
				temp = L->r[j].key;
				L->r[j].key = L->r[j + 1].key;
				L->r[j + 1].key = temp;
			}
		}
}

void Show(SqList L)
{
	int i;
	for (i = 1; i <= L.length; i++)
		printf("%4d", L.r[i].key);
}

int main()
{
	SqList L;
	int i;
	printf("输入线性表的长度：");
	scanf_s("%d", &L.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <=L.length; i++)
		scanf_s("%d", &L.r[i].key);
	BubbleSort(&L);//冒泡排序
	printf("冒泡排序结果是;");
	Show(L);
	system("pause");
	return 0;
}
