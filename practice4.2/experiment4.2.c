#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW 0
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
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
int LeafNodes(BiTree T)
{
	int numl, numr;
	if (T == NULL)//����
	{
		//	printf("����");
		return 0;
	}
	else if ((T->lchild == NULL) && (T->rchild == NULL))
	{
		//	printf("ֻ�и����");
		return 1;
	}
	else
	{
		numl = LeafNodes(T->lchild);
		numr = LeafNodes(T->rchild);
		return numl + numr;
	}
}
int Depth(BiTree T)
{
	int depthl, depthr;
	if (T == NULL)
	{
		//printf("����");
		return 0;
	}
	else if (T->lchild == NULL && T->rchild == NULL)
	{
		//printf("ֻ�и����");
		return 1;
	}
	else
	{
		depthl = Depth(T->lchild);
		depthr = Depth(T->rchild);
	}
	return (depthl > depthr ? depthl : depthr) + 1;
}
Status ExchangeTree(BiTree *T)
{
	BiTree p;
	if ((*T)->lchild || (*T)->rchild)
	{//��Ҷ�ӽ�㣬����������Ů
		p = (*T)->lchild;
		(*T)->lchild = (*T)->rchild;
		(*T)->rchild = p;
		ExchangeTree(&(*T)->lchild);
		ExchangeTree(&(*T)->rchild);
	}
	return OK;
}
int main()
{
	BiTree T;
	int leafnode, treedepth;
	printf("����������е�����Ԫ�أ�");
	CreateBiTree(&T);
	leafnode = LeafNodes(T);
	printf("�˶�������Ҷ�ӽ������%d\n", leafnode);
	treedepth = Depth(T);
	printf("�˶������������%d\n", treedepth);
	ExchangeTree(&T);
	printf("������������������������ǣ�");
	PreOrderTraverse(T, PrintElement);
	printf("\n");
	system("pause");
	return 0;
}