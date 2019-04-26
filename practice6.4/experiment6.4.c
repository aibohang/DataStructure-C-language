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

int Partition(SqList *L, int low, int high)
{//����˳���L���ӱ�r[low..high]�ļ�¼�������¼��λ������������λ��
  //��ʱ����֮ǰ�ģ��󣩵ļ�¼������С������ 
	int pivokey;
	L->r[0] = L->r[low];//���ӱ�ĵ�һ����¼�������¼
	pivokey = L->r[low].key; //�����¼�ؼ���
	while (low < high)
	{//�ӱ�����˽�������м�ɨ�� 

		while (low < high&&L->r[high].key >= pivokey)
		{
			--high;//highָ��ָ���Ԫ�ر������highָ�����ǰ�ƶ� 
		}
		L->r[low] = L->r[high];//���������¼С�ļ�¼�ƶ����׶� 

		while (low < high&&L->r[low].key <= pivokey)
		{
			++low;//lowָ��ָ���Ԫ�ر�����С��lowָ�������ƶ�
		}
		L->r[high] = L->r[low];//���������ļ�¼�ƶ������ 	   

	}
	L->r[low] = L->r[0];//�����¼��λ 
	return low;
}

void QSort(SqList *L, int low, int high)
{//��˳���L�е������� L.r[low..high]���������� 
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);//��Lһ��Ϊ�� 
		QSort(L, low, pivotloc - 1);//�Ե��ӱ�ݹ�����pivotloc������λ��
		QSort(L, pivotloc + 1, high);//�Ը��ӱ�ݹ����� 		
	}
}

void QuickSort(SqList *L)
{//��˳���L���п������� 
	QSort(L, 1, L->length);
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
	QuickSort(&L);
	printf("������������;");
	Show(L);
	system("pause");
	return 0;
}
