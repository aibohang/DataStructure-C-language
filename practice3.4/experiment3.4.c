#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
typedef int Status;
typedef int QElemType;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;
Status InitQueue(LinkQueue *Q, int n)
{//用一个带头结点的单链表实现链队列
	printf("输入队列中的元素：");
	QNode*p;
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);//存储分配失败
	Q->front->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (QueuePtr)malloc(sizeof(QNode));
		scanf_s("%d", &p->data);
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
	}
	return OK;
}
Status DestroyQueue(LinkQueue *Q)
{//销毁队列
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{//插入元素e为Q的新的队尾元素
	QNode*p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	exit(OVERFLOW);//存储分配失败
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL)//若链队为空，新节点既是队首结点又是队尾结点
	{
		Q->front = Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;//将*p结点链到队尾，并使rear指向它
	}
	return OK;
}
Status DeQueue(LinkQueue*Q)
{
	if (Q->front == Q->rear)
	{
		printf("队列为空");
		return ERROR;
	}
	QNode*p;
	p = Q->front->next;//指向第一个数据结点
	Q->front->next = p->next;//队列中有多个结点时
	if (Q->rear == p)
		Q->rear = Q->front;//若队头元素是队列中唯一一个元素，
										//则删除节点后,修改尾指针，使他指向头结点					
	free(p);
	return OK;
}
Status PrintfQueue(LinkQueue Q)
{
	QNode *p;
	printf("队列元素是:");
	p = Q.front->next;//p指向第一个数据元素
	if (Q.front == Q.rear)
	{
		printf("队列为空");
		return ERROR;
	}
	while (p != Q.rear)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("%5d", p->data);//打印Q->rear所指的队尾元素
	printf("\n");
	return OK;
}
int main()
{
	LinkQueue Q;
	QElemType e;
	int n;
	printf("输入队列中元素的个数");
	scanf_s("%d", &n);
	InitQueue(&Q, n);
	PrintfQueue(Q);
	printf("输入插入队列中的元素");
	scanf_s("%d", &e);
	EnQueue(&Q, e);
	printf("插入后数据元素%d后", e);
	PrintfQueue(Q);
	printf("删除队头元素后");
	DeQueue(&Q);
	PrintfQueue(Q);
	system("pause");
	return 0;
}