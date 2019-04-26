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


int SelectMiniKey(SqList L, int i) {
	int minik;
	int mini = MAX;
	for (i; i <= L.length; i++) {
		if (L.r[i].key < mini) {
			mini = L.r[i].key;
			minik = i;
		}
	}
	return minik;
}
void SelectSort(SqList *L) {
	//对顺序表进行简单选择排序

	int i, j, temp;
	for (i = 1; i <= L->length; i++) { //选择第i小记录，并交换到位
		j = SelectMiniKey(*L, i);//在L.r[i..L.length]中选择Key最小的记录
		if (i != j) {
			temp = L->r[i].key;
			L->r[i].key = L->r[j].key;
			L->r[j].key = temp;
		}
	}
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
	printf("输入线性表的长度：");
	scanf_s("%d", &L.length);
	printf("输入线性表中的元素：");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	SelectSort(&L);
	printf("简单选择排序结果是;");
	Show(L);
	system("pause");
	return 0;
}
