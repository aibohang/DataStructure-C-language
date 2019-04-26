#include<stdio.h>

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

void ShellInsert(SqList *L, int dk) {
	//对顺序表L做一趟希尔插入排序，本算法
	//1.前后记录 位置的增量是dk,不是1
	//2.r[0]只是暂存单元，不是哨兵，当j<=0时 ，插入位置已经找到
	int i, j;
	for (i = dk + 1; i <= L->length; i++)
		if (L->r[i].key < L->r[i - dk].key) {
			L->r[0] = L->r[i];
			for (j = i - dk; j > 0 && (L->r[0].key < L->r[j].key); j = j - dk)
				L->r[j + dk] = L->r[j];//记录后移，查找插入位置
			L->r[j + dk] = L->r[0];//插入
		}
}

void SellSort(SqList *L, int dlta[], int t) {
	//按增量序列dlka[0..t-1]对顺序表L做希尔排序
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);//一趟增量为dlta[k] 的插入排序
}


void Show(SqList L) {
	int i;
	for (i = 1; i <= L.length; i++)
		printf("%4d", L.r[i].key);
	printf("\n");
}



int main() {

	SqList L;
	int i;
	int dlta[3] = { 5,3,1 };
	printf("输入线性表的长度：");
	scanf_s("%d", &L.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	SellSort(&L, dlta, 3);
	printf("希尔排序结果是;");
	Show(L);
	system("pause");
	return 0;
}
