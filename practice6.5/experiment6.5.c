#include<stdio.h>
#define MAX 10000
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
	//��˳�����м�ѡ������

	int i, j, temp;
	for (i = 1; i <= L->length; i++) { //ѡ���iС��¼����������λ
		j = SelectMiniKey(*L, i);//��L.r[i..L.length]��ѡ��Key��С�ļ�¼
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
	printf("�������Ա�ĳ��ȣ�");
	scanf_s("%d", &L.length);
	printf("�������Ա��е�Ԫ�أ�");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	SelectSort(&L);
	printf("��ѡ����������;");
	Show(L);
	system("pause");
	return 0;
}
