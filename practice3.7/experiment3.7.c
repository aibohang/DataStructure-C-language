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
	int front;//ָ����еĵ�һ��Ԫ��
	int rear;//ָ����е����һ��Ԫ�ص���һ��Ԫ��
} SqQueue;
Status InitQueue(SqQueue *Q) {
	//����һ���ն���Q
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));//
	if (!Q->base)
		exit(OVERFLOW);//�洢����ʧ��
	Q->front = Q->rear = 0;//��ʼ��ͷָ�룬βָ��
	return OK;
}
Status EnQueue(SqQueue *Q, QElemType e) {
	//����Ԫ��e��ΪQ���µĶ�βԪ��
	if ((Q->rear + 1) % MAXQSIZE == Q->front)//������
		return ERROR;
	Q->base[Q->rear] = e;//���������е���������ͷָ��ָ���Ǹ�λ�ã���ʵ������һ��������ָ�룬ֻ������Ϊ�˷��㱣��Ԫ��
	Q->rear = (Q->rear + 1) % MAXQSIZE;//βָ����ǰ�ƶ�һλ
	return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e) {
	//�����в��գ���ɾ��Q �Ķ�ͷԪ�أ���e������ֵ��������OK���򷵻�ERROR
	if (Q->front == Q->rear)//������
		return ERROR;
	*e = Q->base[Q->front];//������ʱ����ͷԪ���ȳ�ȥ
	Q->front = (Q->front + 1) % MAXQSIZE;//ͷָ����ǰ�ƶ�һλ	
	return OK;
}
Status DeQueue_rear(SqQueue *Q, QElemType *e) {
	//�����в��գ���ɾ��Q �Ķ�βԪ�أ���e������ֵ��������OK���򷵻�ERROR
	if (Q->front == Q->rear)//������ 
		return ERROR;
	Q->rear = (Q->rear - 1) % MAXQSIZE;//��βָ������ָ�����һ��Ԫ�ص���һ��Ԫ�ص�λ�ã������ɾ��βԪ��ʱҪ�Ȱ�ָ����ǰ�ƶ�һλ 
	*e = Q->base[Q->rear];//Ȼ��ȡ�����Ԫ�� 
	return OK;
}
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}
int QueueLength(SqQueue Q) {
	//����Q��Ԫ�صĸ����������еĳ���
	return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status Match(char*a) {
	char c, b;
	char*p; //�����ַ�ָ�����p 
	p = a;//���ַ���������׵�ַ����p 
	SqQueue Q;//�������Q 
	InitQueue(&Q);//��ʼ������Q 
	while (*p != '@') {//p��ǰ��ָ��Ԫ��ֵ���ǶԳ������ַ� �ı�� 
		EnQueue(&Q, *p);//��p��ָ���ַ������� 
		p++;//pָ��ָ����һ���ַ� 
	}
	p++;//�����Գ����ı�־@��������������	
	while (*p != '#') { //p��ǰ��ָ���ַ����Ƕ�β����
		EnQueue(&Q, *p);//���������� 
		p++;// pָ����� 
	}
	while (QueueLength(Q) != 0)
	{//ѭ������������Ϊ���в��ǿյģ��Ӷ�β��ͷ�ֱ�ɾ���ַ����бȽ�	
		if (!DeQueue(&Q, &b))//ȡ����ͷԪ�أ�ͬʱ����Ƿ���ȡ�ɹ� 
			return OVERFLOW;
		if (!DeQueue_rear(&Q, &c))//ȡ����βԪ�أ�ͬʱ����Ƿ���ȡ�ɹ�
			return OVERFLOW;
		//�ӳ���Ϊ�㣬ȡ��ͷԪ�غͶ�βԪ�رȽ�
		if (b != c) //���������һ�Զ�ͷ���β�ַ���ƥ�䣬��֤������ַ����������ĶԳƵ� 
		{
			printf("�������ĶԳ��ַ�����!\n");
			return FALSE;
		}
	}
	if (Q.rear == Q.front)//���Ӷ�ͷ��βɾ���ַ�������ָ������ʱ��˵������֮ǰ���ַ����ɹ�ƥ������ 
		printf("�����ĶԳ��ַ����У�");
	return OK;
}
int main() {
	char a[100];//�����ַ����� 
	printf("������Ҫ������ַ�����,��#��Ϊ������־��\n");
	gets(a);//�����ַ��� 
	Match(a);//��������ʵ�Σ���������Ԫ�صĵ�ַ���ݸ��β� 
	system("pause");
	return 0;
}