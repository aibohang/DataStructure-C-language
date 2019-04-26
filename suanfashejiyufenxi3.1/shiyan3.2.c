#include<stdio.h>
#include<stdlib.h>
#define N 10000

int b[N], a[N];//全局变量，b[i]表示纵坐标,a[i]表示横坐标

int b[N], a[N];//全局变量，b[i]表示横坐标,a[i]表示纵坐标

void SwapAij(int i, int j)
{//交换下标为a[i]和a[j]的两个下标
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


void SwapAij2(int i, int j)
{//交换下标为a[i]和a[j]的两个下标
	int temp;
	temp = b[i];
	b[i] = b[j];
	b[j] = temp;
}




int SearchMid(int s, int e, int t)
{//从a[s]到a[e]中找第t小的，用类似于快速排序算法思想，枢轴就是a[s]
	int nleft = 0;//用于记数，记录比a[s]小的数的个数
	int i;
	int j = e;

	for (i = s + 1; i <= j; i++)
	{
		if (a[i] <= a[s])
		{
			nleft++;//左边的数总个数加1
		}
		else
		{//如果a[i]>a[s],就从a[e]到a[s]从右到左开始找，
			//当找到一个比a[s]小的数后，让他与刚才上一级那个比a[s]大的数交换
			for (; j > i; j--)
			{
				if (a[j] <= a[s])
				{
					SwapAij(i, j);
					nleft++;//交换后左边的数加1
				}
			}
		}
	}

	if (nleft + 1 == t)
		return a[s];
	else if (nleft + 1 < t)//左边nleft不够,从右边找
		SearchMid(s + nleft + 1, e, t - nleft - 1);
	else//左边的多，继续找
		SearchMid(s + 1, i - 1, t);
}

int SearchMid2(int s, int e, int t)
{//从b[s]到a[e]中找第t小的，用类似于快速排序算法思想，枢轴就是a[s]
	int nleft = 0;//用于记数，记录比a[s]小的数的个数
	int i;
	int j = e;

	for (i = s + 1; i <= j; i++)
	{
		if (b[i] <= b[s])
		{
			nleft++;//左边的数总个数加1
		}
		else
		{//如果a[i]>a[s],就从a[e]到a[s]从右到左开始找，
			//当找到一个比a[s]小的数后，让他与刚才上一级那个比a[s]大的数交换
			for (; j > i; j--)
			{
				if (b[j] <= b[s])
				{
					SwapAij2(i, j);
					nleft++;//交换后左边的数加1
				}
			}
		}
	}

	if (nleft + 1 == t)
		return b[s];
	else if (nleft + 1 < t)//左边nleft不够,从右边找
		SearchMid2(s + nleft + 1, e, t - nleft - 1);
	else//左边的多，继续找
		SearchMid2(s + 1, i - 1, t);
}




int main()
{
	int n, mid1, mid2, sum1 = 0, sum2 = 0, sum = 0;
	printf("输入士兵的个数：");
	scanf_s("%d", &n);
	printf("输入士兵的横纵坐标:\n");
	for (int i = 0; i < n; i++)
		scanf_s("%d %d", &b[i], &a[i]);//输入居民点的坐标

	for (int i = 0; i < n; i++)
	{
		b[i] = b[i] - 1;
	}

	mid1 = SearchMid(0, n - 1, n / 2 + 1);//求纵坐标的中位数即 从a[0]到a[n - 1]找第n / 2 - 1小的
	mid2 = SearchMid2(0, n - 1, n / 2 + 1);


	printf("纵坐标中位数mid1=%d\n", mid1);
	printf("横坐标中位数mid2=%d\n", mid2);

	for (int i = 0; i < n; i++)
		sum1 += abs(a[i] - mid1);//所有油井位置的纵坐标减去中位数的绝对值即为最小长度总和
	for (int i = 0; i < n; i++)
		sum2 += abs(b[i] - mid2);//所有油井位置的横坐标减去中位数的绝对值即为最小长度总和

	sum = sum1 + sum2;

	printf("%d\n", sum1);
	printf("%d\n", sum2);

	printf("输油管道最小长度总和是：%d\n", sum);
	system("pause");
	return 0;

}









	



	
	
	
