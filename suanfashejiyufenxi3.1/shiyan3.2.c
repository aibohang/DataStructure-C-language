#include<stdio.h>
#include<stdlib.h>
#define N 10000

int b[N], a[N];//ȫ�ֱ�����b[i]��ʾ������,a[i]��ʾ������

int b[N], a[N];//ȫ�ֱ�����b[i]��ʾ������,a[i]��ʾ������

void SwapAij(int i, int j)
{//�����±�Ϊa[i]��a[j]�������±�
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void SwapAij2(int i, int j)
{//�����±�Ϊa[i]��a[j]�������±�
	int temp;
	temp = b[i];
	b[i] = b[j];
	b[j] = temp;
}




int SearchMid(int s, int e, int t)
{//��a[s]��a[e]���ҵ�tС�ģ��������ڿ��������㷨˼�룬�������a[s]
	int nleft = 0;//���ڼ�������¼��a[s]С�����ĸ���
	int i;
	int j = e;

	for (i = s + 1; i <= j; i++)
	{
		if (a[i] <= a[s])
		{
			nleft++;//��ߵ����ܸ�����1
		}
		else
		{//���a[i]>a[s],�ʹ�a[e]��a[s]���ҵ���ʼ�ң�
			//���ҵ�һ����a[s]С������������ղ���һ���Ǹ���a[s]���������
			for (; j > i; j--)
			{
				if (a[j] <= a[s])
				{
					SwapAij(i, j);
					nleft++;//��������ߵ�����1
				}
			}
		}
	}

	if (nleft + 1 == t)
		return a[s];
	else if (nleft + 1 < t)//���nleft����,���ұ���
		SearchMid(s + nleft + 1, e, t - nleft - 1);
	else//��ߵĶ࣬������
		SearchMid(s + 1, i - 1, t);
}

int SearchMid2(int s, int e, int t)
{//��b[s]��a[e]���ҵ�tС�ģ��������ڿ��������㷨˼�룬�������a[s]
	int nleft = 0;//���ڼ�������¼��a[s]С�����ĸ���
	int i;
	int j = e;

	for (i = s + 1; i <= j; i++)
	{
		if (b[i] <= b[s])
		{
			nleft++;//��ߵ����ܸ�����1
		}
		else
		{//���a[i]>a[s],�ʹ�a[e]��a[s]���ҵ���ʼ�ң�
			//���ҵ�һ����a[s]С������������ղ���һ���Ǹ���a[s]���������
			for (; j > i; j--)
			{
				if (b[j] <= b[s])
				{
					SwapAij2(i, j);
					nleft++;//��������ߵ�����1
				}
			}
		}
	}

	if (nleft + 1 == t)
		return b[s];
	else if (nleft + 1 < t)//���nleft����,���ұ���
		SearchMid2(s + nleft + 1, e, t - nleft - 1);
	else//��ߵĶ࣬������
		SearchMid2(s + 1, i - 1, t);
}




int main()
{
	int n, mid1, mid2, sum1 = 0, sum2 = 0, sum = 0;
	printf("����ʿ���ĸ�����");
	scanf_s("%d", &n);
	printf("����ʿ���ĺ�������:\n");
	for (int i = 0; i < n; i++)
		scanf_s("%d %d", &b[i], &a[i]);//�������������

	for (int i = 0; i < n; i++)
	{
		b[i] = b[i] - 1;
	}

	mid1 = SearchMid(0, n - 1, n / 2 + 1);//�����������λ���� ��a[0]��a[n - 1]�ҵ�n / 2 - 1С��
	mid2 = SearchMid2(0, n - 1, n / 2 + 1);


	printf("��������λ��mid1=%d\n", mid1);
	printf("��������λ��mid2=%d\n", mid2);

	for (int i = 0; i < n; i++)
		sum1 += abs(a[i] - mid1);//�����;�λ�õ��������ȥ��λ���ľ���ֵ��Ϊ��С�����ܺ�
	for (int i = 0; i < n; i++)
		sum2 += abs(b[i] - mid2);//�����;�λ�õĺ������ȥ��λ���ľ���ֵ��Ϊ��С�����ܺ�

	sum = sum1 + sum2;

	printf("%d\n", sum1);
	printf("%d\n", sum2);

	printf("���͹ܵ���С�����ܺ��ǣ�%d\n", sum);
	system("pause");
	return 0;

}









	



	
	
	
