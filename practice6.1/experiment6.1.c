#include<stdio.h>
#define MAXSIZE 20

typedef int KeyType;//����ؼ�������Ϊ��������
typedef int InfoType;

typedef struct {
	KeyType key;//�ؼ����� 
	InfoType otherinfo;//���������� 
}RedType;//��¼���� 
typedef struct {
	RedType  r[MAXSIZE + 1];//��r[0] �����û������ڱ���Ԫ
	int length;//˳����� 
}SqList;//˳�������


void InsertSort(SqList *L)
{//��˳���L��ֱ�Ӳ������� 
	int i, j;
	for (i = 2; i <= L->length; i++)
		if (L->r[i].key < L->r[i - 1].key)
		{
			L->r[0] = L->r[i];//����Ϊ�ڱ�
			L->r[i] = L->r[i - 1];
			for (j = i - 2; L->r[0].key < L->r[j].key; --j)
				L->r[j + 1] = L->r[j];//��¼���� 
			L->r[j + 1] = L->r[0]; //���뵽��ȷ��λ���� 		
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
	printf("�������Ա�ĳ��ȣ�");
	scanf_s("%d", &L.length);
	printf("�������Ա��е�Ԫ�أ�");
	for (i = 1; i <= L.length; i++)
		scanf_s("%d", &L.r[i].key);
	InsertSort(&L);
	printf("ֱ�Ӳ������������;");
	Show(L);
	system("pause");
	return 0;
}
