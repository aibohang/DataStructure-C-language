#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define MAXQSIZE 100//�����г���
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, QElemType, *BiTree;
typedef struct {
	QElemType *base;//��ʼ���Ķ�̬����洢�ռ�
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
				//���ǲ�����������ָ�룬ֻ������ָʾλ��
}SqQueue;
Status InitQueue(SqQueue* Q)
{//����һ���ն���Q
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);//�洢����ʧ��
	Q->front = Q->rear = 0;
	return OK;
}
int QueueLength(SqQueue  Q)
{//����Q��Ԫ�صĸ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status QueueEmpty(SqQueue Q)
{
	{
		if (Q.rear == Q.front)
			return OK;
		else return ERROR;
	}
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
Status DeQueue(SqQueue*Q, QElemType *e)
{//������
	if (Q->front == Q->rear)
	{
		printf("��ǰ����Ϊ��");
		return ERROR;
	}
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}
Status CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf_s("%c", &ch);
	if (ch == '#') *T = NULL;//����
	else
	{
		if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))//���ٽ��ռ�
		{
			printf("�ڴ����ʧ��");
			exit(OVERFLOW);
		}
		(*T)->data = ch;//������ֵ
		CreateBiTree(&(*T)->lchild);//����������	ע�⣺���ݵ������������ĵ�ַ
		CreateBiTree(&(*T)->rchild);//����������
	}
	return OK;
}
Status PrintElement(TElemType e)
{//���Ԫ��e��ֵ
	printf("%c", e);
	return OK;
}
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))//���ʸ����
			if (PreOrderTraverse(T->lchild, Visit))//����������
				if (PreOrderTraverse(T->rchild, Visit))//����������
					return OK;
		return ERROR;
	}
	else
		return OK;
}
Status SeqTraverse(BiTree T)
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, *T);
	BiTree root = T;
	while (!QueueEmpty(Q))
	{
		DeQueue(&Q, root);
		printf("%c", root->data);
		if (root->lchild)
			EnQueue(&Q, *root->lchild);
		if (root->rchild)
			EnQueue(&Q, *root->rchild);
	}
	return OK;
}
int main()
{
	BiTree T;
	printf("����������е�����Ԫ�أ�");
	CreateBiTree(&T);
	printf("��������������������ǣ�");
	PreOrderTraverse(T, PrintElement);
	printf("\n");
	printf("��������������������ǣ�");
	SeqTraverse(T);
	printf("\n");
	system("pause");
	return 0;
}
