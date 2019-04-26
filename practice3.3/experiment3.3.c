#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define MAXQSIZE 100//最大队列长度
typedef int QElemType;
typedef int Status;
typedef struct {
	QElemType *base;//初始化的动态分配存储空间
	int front;//头指针，若队列不空，指向队列头元素
	int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
				//他们并不是真正的指针，只是用于指示位置
}SqQueue;
Status InitQueue(SqQueue* Q, int n)
{//构造一个空队列Q
	QElemType e;
	if (n > MAXQSIZE - 1)
	{
		printf("队列元素个数超出队列空间\n");
		return ERROR;
	}
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);//存储分配失败
	Q->front = Q->rear = 0;
	printf("输入队列元素：");
	for (Q->rear = 0; Q->rear < n; Q->rear++)
	{
		scanf_s("%d", &e);
		Q->base[Q->rear] = e;
	}
	return OK;
}
int QueueLength(SqQueue  Q)
{//返回Q中元素的个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnQueue(SqQueue*Q, QElemType e)
{//插入元素e作为Q的新的队列元素


	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		//if后边不要带 ; 很坑虽然能运行程序，
		//但会直接进入下一个语句，退出EnQueue()函数
	{
		printf("当前队列已满");
		return ERROR;
	}

	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue*Q)
{//出队列
	QElemType e;
	if (Q->front == Q->rear)
	{
		printf("当前队列为空");
		return ERROR;
	}
	e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	printf("出队的队头元素是%5d\n", e);
	return OK;
}
Status  PrintQueue(SqQueue Q)
{
	QElemType p;
	printf("当前队列元素是:");
	if (Q.rear == Q.front)
	{
		printf("当前队列为空");
		return ERROR;
	}
	p = Q.front;
	while (p != Q.rear)
	{
		printf("%5d", Q.base[p%MAXQSIZE]);
		p++;
	}
	printf("\n");
	return OK;
}
int main()
{
	QElemType e;
	SqQueue Q;
	int n, Qlength;
	printf("请输入队列中的元素个数（小于100个）：");
	scanf_s("%d", &n);
	InitQueue(&Q, n);
	PrintQueue(Q);
	Qlength = QueueLength(Q);
	printf("队列长度是:%5d", Qlength);
	printf("\n");
	printf("输入你要入队的元素：");
	scanf_s("%d", &e);
	EnQueue(&Q, e);
	PrintQueue(Q);
	DeQueue(&Q);
	PrintQueue(Q);
	system("pause");
	return 0;
}