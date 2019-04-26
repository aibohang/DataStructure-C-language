#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0
#define OK 1
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�洢�ռ�ķ�������
typedef  int  ElemType;
typedef  int  Status;
typedef struct {
	ElemType *elem;//�洢�ռ��ַ
	int length;//���Ա�ǰ����
	int listsize;//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
} SqList;
Status InitList_Sq(SqList *L)
{
	//����յ����Ա�L
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);//�洢����ʧ��
	L->length = 0;//�ձ���Ϊ��
	L->listsize = LIST_INIT_SIZE;//��ʼ�洢����
	return OK;
}
void Create(SqList *L)//����
{
	//	SqList L;
		//InitList_Sq(&L);
	int n;
	int i = 0;
	printf("�������Ա���Ԫ�ظ���(����100��):\n");
	while (scanf("%d", &n) && n > 100 || n < 0)
	{
		printf("���ݲ��Ϸ�������������\n");
	}
	printf("������%d�������ÿո�ֿ�\n", n);
	while (n--)
	{
		scanf("%d", &L->elem[i]);
		i++;
		L->length++;
	}
}
Status InsertOrderList(SqList *L, int x)
{
	ElemType *newbase, *p;
	if (L->length >= L->listsize)
	{//��ǰ�洢�ռ����������ӷ���
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//�洢����ʧ��
		L->elem = newbase;//�»�ַ
		L->listsize += LISTINCREMENT;//���Ӵ洢����
	}
	p = &(L->elem[L->length - 1]);//ָ���βԪ�ص�λ��
	while (p >= &(L->elem[0]) && *p > x)
	{
		*(p + 1) = *p;
		p--;
	}
	*(p + 1) = x;
	L->length++;
	return OK;
}
void Show(SqList *L)
{
	printf("˳����е�Ԫ���ǣ�\t");
	for (int i = 0; i < L->length; i++)
	{
		printf("%5d", L->elem[i]);
	}
	printf("\n");
}
int main()
{
	ElemType  x;
	SqList L;
	InitList_Sq(&L);
	Create(&L);
	printf("����Ҫ�����Ԫ��:\n");
	scanf("%d", &x);
	InsertOrderList(&L, x);
	Show(&L);
	system("pause");
}