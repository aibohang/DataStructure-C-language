#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define MAXQSIZE 100//�����г���
typedef int QElemType;
typedef int Status;
typedef struct {
	QElemType *base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
				//���ǲ�����������ָ�룬ֻ������ָʾλ��
}SqQueue;
Status InitQueue(SqQueue* Q, int n)
{//����һ���ն���Q
	QElemType e;
	if (n > MAXQSIZE - 1)
	{
		printf("����Ԫ�ظ����������пռ�\n");
		return ERROR;
	}
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);//�洢����ʧ��
	Q->front = Q->rear = 0;
	printf("�������Ԫ�أ�");
	for (Q->rear = 0; Q->rear < n; Q->rear++)
	{
		scanf_s("%d", &e);
		Q->base[Q->rear] = e;
	}
	return OK;
}
int QueueLength(SqQueue  Q)
{//����Q��Ԫ�صĸ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnQueue(SqQueue*Q, QElemType e)
{//����Ԫ��e��ΪQ���µĶ���Ԫ��


	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		//if��߲�Ҫ�� ; �ܿ���Ȼ�����г���
		//����ֱ�ӽ�����һ����䣬�˳�EnQueue()����
	{
		printf("��ǰ��������");
		return ERROR;
	}

	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue*Q)
{//������
	QElemType e;
	if (Q->front == Q->rear)
	{
		printf("��ǰ����Ϊ��");
		return ERROR;
	}
	e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	printf("���ӵĶ�ͷԪ����%5d\n", e);
	return OK;
}
Status  PrintQueue(SqQueue Q)
{
	QElemType p;
	printf("��ǰ����Ԫ����:");
	if (Q.rear == Q.front)
	{
		printf("��ǰ����Ϊ��");
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
	printf("����������е�Ԫ�ظ�����С��100������");
	scanf_s("%d", &n);
	InitQueue(&Q, n);
	PrintQueue(Q);
	Qlength = QueueLength(Q);
	printf("���г�����:%5d", Qlength);
	printf("\n");
	printf("������Ҫ��ӵ�Ԫ�أ�");
	scanf_s("%d", &e);
	EnQueue(&Q, e);
	PrintQueue(Q);
	DeQueue(&Q);
	PrintQueue(Q);
	system("pause");
	return 0;
}