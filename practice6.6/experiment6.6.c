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
typedef SqList HeapType;//��������˳���洢��ʾ 
void HeapAdjust(HeapType *H, int s, int m)
{
	//��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������ѵĶ��壬
	//����������H.r[s] �Ĺؼ��֣�ʹH.r[s..m]��Ϊһ���󶥶ѣ������м�¼�Ĺؼ��ֶ��ԣ�
	RedType rc;
	int j;
	rc = H->r[s];
	for (j = 2 * s; j <= m; j = j * 2)
	{//����key�ϴ�ĺ��ӽ������ɸѡ
		if (j < m && (H->r[j].key < H->r[j + 1].key))
			j++;//jΪkey�ϴ�ļ�¼���±�
		if (!(rc.key < H->r[j].key))
			break;
		H->r[s] = H->r[j];
		s = j;
	}
	H->r[s] = rc;//���� 
}

void HeapSort(HeapType *H)
{//��˳���H���ж����� 
	RedType temp;
	int i;
	for (i = H->length / 2; i > 0; --i)//��H.r[1..H.length] ���ɴ󶥶�
		HeapAdjust(H, i, H->length);
	for (i = H->length; i > 1; --i)
	{
		temp = H->r[1];
		H->r[1] = H->r[i];
		H->r[i] = temp;//���Ѷ���¼�͵�ǰδ�������������H.r[1..i]�����һ����¼�໥����
		HeapAdjust(H, 1, i - 1);//��H.r[1..i-1]���µ���Ϊ�󶥶� 
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
	HeapType H;
	int i;
	printf("�������Ա�ĳ��ȣ�");
	scanf_s("%d", &H.length);
	printf("�������Ա��е�Ԫ�أ�");
	for (i = 1; i <= H.length; i++)
		scanf_s("%d", &H.r[i].key);

	HeapSort(&H);
	printf("����������;");
	Show(H);
	system("pause");
	return 0;
}
