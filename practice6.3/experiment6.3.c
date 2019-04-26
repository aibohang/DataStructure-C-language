#include<stdio.h>

#define MAXSIZE 10
typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;		//�ؼ�����
	InfoType otherinfo;	// ���������� 
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];//r[0]�����û����ڱ���Ԫ
	int length;			//˳����� 
}SqList;				//˳�������


void BubbleSort(SqList *L)//ð������ 
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
	printf("�������Ա�ĳ��ȣ�");
	scanf_s("%d", &L.length);
	printf("�������Ա��е�Ԫ�أ�");
	for (i = 1; i <=L.length; i++)
		scanf_s("%d", &L.r[i].key);
	BubbleSort(&L);//ð������
	printf("ð����������;");
	Show(L);
	system("pause");
	return 0;
}
