#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define MAXQSIZE 100//最大队列长度
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree, *QElemType;
typedef struct {
	QElemType *base;//初始化的动态分配存储空间
	int front;//头指针，若队列不空，指向队列头元素
	int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
				//他们并不是真正的指针，只是用于指示位置
}SqQueue;
Status InitQueue(SqQueue* Q)
{//构造一个空队列Q
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);//存储分配失败
	Q->front = Q->rear = 0;
	return OK;
}
int QueueLength(SqQueue  Q)
{//返回Q中元素的个数，即队列的长度
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
{//插入元素e作为Q的新的队列元素
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		//if后边不要带 ; 很坑虽然能运行程序，
		//但会直接进入下一个语句，退出EnQueue()函数
	{
		//	printf("当前队列已满");
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue*Q, QElemType *e)
{//出队列
	if (Q->front == Q->rear)
	{
		//	printf("当前队列为空");
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
	if (ch == '#') *T = NULL;//空树
	else
	{
		if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))//开辟结点空间
		{
			printf("内存分配失败");
			exit(OVERFLOW);
		}
		(*T)->data = ch;//数据域赋值
		CreateBiTree(&(*T)->lchild);//创建左子树	注意：传递的是左子树结点的地址
		CreateBiTree(&(*T)->rchild);//创建右子树
	}
	return OK;
}
Status PrintElement(TElemType e)
{//输出元素e的值
	printf("%c", e);
	return OK;
}
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))//访问根结点
			if (PreOrderTraverse(T->lchild, Visit))//访问左子树
				if (PreOrderTraverse(T->rchild, Visit))//访问右子树
					return OK;
		return ERROR;
	}
	else
		return OK;
}
Status IsCompleteBiTree(BiTree T) {
	if (!T)return TRUE;             // 若为一个空树，则直接结束
	int flag = 0;               //设立一个flag，若某结点有左右孩子则为0;若某一个空了，则为1
	SqQueue Q;
	BiTree* e;
	e = (BiTree *)malloc(sizeof(BiTree));
	InitQueue(&Q);
	EnQueue(&Q, T);             //将根结点入队列
	while (DeQueue(&Q, e)) {     //当队列不空时
		if (!(*e)) {             //若当前元素为空，则flag = 1，直接进行下一个循环
			flag = 1;
			continue;
		}
		else if (flag) {        //若当前元素不为空，且flag == 1，则证明该树不为完全二叉树
			return FALSE;
		}
		else {
			EnQueue(&Q, (*e)->lchild);
			EnQueue(&Q, (*e)->rchild);
		}
	}
	//printf("\n");
	return TRUE;
}
int main()
{
	BiTree T;
	printf("输入二叉树中的数据元素：");
	CreateBiTree(&T);
	printf("先序遍历二叉树的序列是：");
	PreOrderTraverse(T, PrintElement);
	printf("\n");
	if (IsCompleteBiTree(T))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");
	system("pause");
	return 0;
}