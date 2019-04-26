#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
#define MAXQSIZE 100
typedef int Status;
typedef char QElemType;
typedef struct {
	QElemType *base;
	int front;//指向队列的第一个元素
	int rear;//指向队列的最后一个元素的下一个元素
} SqQueue;
Status InitQueue(SqQueue *Q) {
	//构造一个空队列Q
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));//
	if (!Q->base)
		exit(OVERFLOW);//存储分配失败
	Q->front = Q->rear = 0;//初始化头指针，尾指针
	return OK;
}
Status EnQueue(SqQueue *Q, QElemType e) {
	//插入元素e作为Q的新的队尾元素
	if ((Q->rear + 1) % MAXQSIZE == Q->front)//队列满
		return ERROR;
	Q->base[Q->rear] = e;//把这个入队列的数保存在头指针指的那个位置，其实他不是一个真正的指针，只不过是为了方便保存元素
	Q->rear = (Q->rear + 1) % MAXQSIZE;//尾指针向前移动一位
	return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e) {
	//若队列不空，则删除Q 的队头元素，用e返回其值，并返回OK否则返回ERROR
	if (Q->front == Q->rear)//队列满
		return ERROR;
	*e = Q->base[Q->front];//出队列时，队头元素先出去
	Q->front = (Q->front + 1) % MAXQSIZE;//头指针向前移动一位	
	return OK;
}
Status DeQueue_rear(SqQueue *Q, QElemType *e) {
	//若队列不空，则删除Q 的队尾元素，用e返回其值，并返回OK否则返回ERROR
	if (Q->front == Q->rear)//队列满 
		return ERROR;
	Q->rear = (Q->rear - 1) % MAXQSIZE;//队尾指针总是指向最后一个元素的下一个元素的位置，因此在删队尾元素时要先把指针向前移动一位 
	*e = Q->base[Q->rear];//然后取出这个元素 
	return OK;
}
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
int QueueLength(SqQueue Q) {
	//返回Q中元素的个数，即队列的长度
	return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status Match(char*a) {
	char c, b;
	char*p; //定义字符指针变量p 
	p = a;//把字符串数组的首地址赋给p 
	SqQueue Q;//定义队列Q 
	InitQueue(&Q);//初始化队列Q 
	while (*p != '@') {//p当前所指的元素值不是对称中心字符 的标记 
		EnQueue(&Q, *p);//让p所指的字符进队列 
		p++;//p指针指向下一个字符 
	}
	p++;//跳过对称中心标志@，不让他进队列	
	while (*p != '#') { //p当前所指的字符不是队尾结束
		EnQueue(&Q, *p);//继续进队列 
		p++;// p指针后移 
	}
	while (QueueLength(Q) != 0)
	{//循环的条件限制为队列不是空的，从队尾队头分别删除字符进行比较	
		if (!DeQueue(&Q, &b))//取出队头元素，同时检查是否能取成功 
			return OVERFLOW;
		if (!DeQueue_rear(&Q, &c))//取出队尾元素，同时检查是否能取成功
			return OVERFLOW;
		//队长不为零，取队头元素和队尾元素比较
		if (b != c) //如果检测出有一对队头与队尾字符不匹配，就证明这个字符串不是中心对称的 
		{
			printf("不是中心对称字符序列!\n");
			return FALSE;
		}
	}
	if (Q.rear == Q.front)//当从队头队尾删除字符的两个指针相遇时，说明他们之前的字符都成功匹配上了 
		printf("是中心对称字符序列！");
	return OK;
}
int main() {
	char a[100];//定义字符数组 
	printf("请输入要检验的字符序列,以#作为结束标志！\n");
	gets(a);//接收字符串 
	Match(a);//数组名做实参，把数组首元素的地址传递给形参 
	system("pause");
	return 0;
}