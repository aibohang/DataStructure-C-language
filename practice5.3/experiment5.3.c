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

int Search_Seq(SSTable ST, KeyType key)
{//��˳�����˳�������ؼ��ֵ���key������Ԫ�أ�
//���ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int i;
	ST.elem[0].key = key;//�ڱ�
	for (i = ST.length; !EQ(ST.elem[i].key, key); --i);//�Ӻ���ǰ��
	if (i == 0)
		printf("��Ԫ�ز���˳�����");
	return i;//�Ҳ���ʱ��iΪ0

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
	printf("����˳�����:");
	scanf_s("%d", &ST->length);
	ST->elem = (SElemType*)malloc((ST->length + 1) * sizeof(ElemType));
	printf("��������и���Ԫ�ص�ֵ:");
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
	n = Search_Seq(ST, key);
	printf("��Ҫ���ҵ�Ԫ���ڱ��е�λ����%d\n", n);
	system("pause");
	return 0;
}


