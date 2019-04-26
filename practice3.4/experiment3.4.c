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
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;
Status InitQueue(LinkQueue *Q, int n)
{//��һ����ͷ���ĵ�����ʵ��������
	printf("��������е�Ԫ�أ�");
	QNode*p;
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);//�洢����ʧ��
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
{//���ٶ���
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	QNode*p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)	exit(OVERFLOW);//�洢����ʧ��
	p->data = e;
	p->next = NULL;
	if (Q->rear == NULL)//������Ϊ�գ��½ڵ���Ƕ��׽�����Ƕ�β���
	{
		Q->front = Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;//��*p���������β����ʹrearָ����
	}
	return OK;
}
Status DeQueue(LinkQueue*Q)
{
	if (Q->front == Q->rear)
	{
		printf("����Ϊ��");
		return ERROR;
	}
	QNode*p;
	p = Q->front->next;//ָ���һ�����ݽ��
	Q->front->next = p->next;//�������ж�����ʱ
	if (Q->rear == p)
		Q->rear = Q->front;//����ͷԪ���Ƕ�����Ψһһ��Ԫ�أ�
										//��ɾ���ڵ��,�޸�βָ�룬ʹ��ָ��ͷ���					
	free(p);
	return OK;
}
Status PrintfQueue(LinkQueue Q)
{
	QNode *p;
	printf("����Ԫ����:");
	p = Q.front->next;//pָ���һ������Ԫ��
	if (Q.front == Q.rear)
	{
		printf("����Ϊ��");
		return ERROR;
	}
	while (p != Q.rear)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("%5d", p->data);//��ӡQ->rear��ָ�Ķ�βԪ��
	printf("\n");
	return OK;
}
int main()
{
	LinkQueue Q;
	QElemType e;
	int n;
	printf("���������Ԫ�صĸ���");
	scanf_s("%d", &n);
	InitQueue(&Q, n);
	PrintfQueue(Q);
	printf("�����������е�Ԫ��");
	scanf_s("%d", &e);
	EnQueue(&Q, e);
	printf("���������Ԫ��%d��", e);
	PrintfQueue(Q);
	printf("ɾ����ͷԪ�غ�");
	DeQueue(&Q);
	PrintfQueue(Q);
	system("pause");
	return 0;
}