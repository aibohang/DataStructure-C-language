#include<stdio.h>

#define MAXSIZE 10
typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;		//�ؼ�����
	InfoType otherinfo;	// ����������
} RedType;

typedef struct {
	RedType r[MAXSIZE + 1];//r[0]�����û����ڱ���Ԫ
	int length;			//˳�����
} SqList;				//˳�������

void ShellInsert(SqList *L, int dk) {
	//��˳���L��һ��ϣ���������򣬱��㷨
	//1.ǰ���¼ λ�õ�������dk,����1
	//2.r[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ ������λ���Ѿ��ҵ�
	int i, j;
	for (i = dk + 1; i <= L->length; i++)
		if (L->r[i].key < L->r[i - dk].key) {
			L->r[0] = L->r[i];
			for (j = i - dk; j > 0 && (L->r[0].key < L->r[j].key); j = j - dk)
				L->r[j + dk] = L->r[j];//��¼���ƣ����Ҳ���λ��
			L->r[j + dk] = L->r[0];//����
		}
}

void SellSort(SqList *L, int dlta[], int t) {
	//����������dlka[0..t-1]��˳���L��ϣ������
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(L, dlta[k]);//һ������Ϊdlta[k] �Ĳ�������
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
	printf("�������Ա�ĳ��ȣ�");
	scanf_s("%d", &L.length);
	printf("�������Ա��е�Ԫ�أ�");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	SellSort(&L, dlta, 3);
	printf("ϣ����������;");
	Show(L);
	system("pause");
	return 0;
}
