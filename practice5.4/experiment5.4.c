#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef int KeyType;
typedef struct {
	KeyType key;//�ؼ�����
						//������
}SElemType;

typedef struct {
	SElemType *elem;//����Ԫ�ش洢�ռ��ַ������ʱ����ʵ�ʳ��ȷ��䣬0��Ԫ������
	int length;//����
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
{//��������ұ����۰������ؼ��ֵ���key������Ԫ�أ����ҵ�������ֵ
//Ϊ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int low, high, mid;
	low = 1;
	high = ST.length;//�������ֵ
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid].key))
			return mid;//�ҵ�����Ԫ��
		else if (LT(key, ST.elem[mid].key))
			high = mid - 1;//������ǰ��������в���
		else
			low = mid + 1;//�����ں��������в���
	}
	return 0;//˳����в����ڴ���Ԫ��
}


Status CreateTable(SSTable *ST)
{
	printf("����˳����ȣ�");
	scanf_s("%d", &ST->length);
	ST->elem = (SElemType*)malloc((ST->length + 1) * sizeof(ElemType));
	printf("��������и���Ԫ�ص�ֵ��");
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
	printf("��������Ҫ���ҵ�ֵ��");
	scanf_s("%d", &key);
	n = Search_Bin(ST, key);
	printf("��Ҫ���ҵ�Ԫ���ڱ��е�λ����%d\n", n);
	system("pause");
	return 0;
}

