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
	while (scanf_s("%d", &n) && n > 100 || n < 0)
	{
		printf("���ݲ��Ϸ�������������\n");
	}
	printf("������%d�������ÿո�ֿ�\n", n);
	while (n--)
	{
		scanf_s("%d", &L->elem[i]);
		i++;
		L->length++;
	}
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
void MergeList_Sq(SqList *La, SqList*Lb, SqList*Lc)
{//��֪˳�����Ա�La,Lb��Ԫ�ذ�ֵ�ǵݼ�����
 //�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	ElemType*pa, *pb, *pc,*pa_last,*pb_last;//����5��ָ�����
	pa = La->elem;
	pb = Lb->elem;
	Lc->listsize = Lc->length = La->length + Lb->length;
	pc = Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem)exit(OVERFLOW);//�洢����ʧ��
	pa_last = La->elem + La->length - 1;//pa-lastָ�����Ա�La���һ��Ԫ��
	pb_last = Lb->elem + Lb->length - 1;//pb-lastָ�����Ա�Lb���һ��Ԫ��
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;//����La��ʣ��Ԫ��
	while (pb <= pb_last)*pc++ = *pb++;//����Lb��ʣ��Ԫ��
}
int main()
{
	SqList La,Lb,Lc;
    InitList_Sq(&La);
	InitList_Sq(&Lb);
    Create(&La);
	Create(&Lb);
	MergeList_Sq(&La, &Lb, &Lc);
	printf("�鲢���˳���");
	Show(&Lc);
	system("pause");
}