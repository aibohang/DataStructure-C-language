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
int LeafNodes(BiTree T)
{
	int numl, numr;
	if (T == NULL)//树空
	{
		//	printf("树空");
		return 0;
	}
	else if ((T->lchild == NULL) && (T->rchild == NULL))
	{
		//	printf("只有根结点");
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
		//printf("树空");
		return 0;
	}
	else if (T->lchild == NULL && T->rchild == NULL)
	{
		//printf("只有根结点");
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
	{//非叶子结点，交换左、右子女
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
	printf("输入二叉树中的数据元素：");
	CreateBiTree(&T);
	leafnode = LeafNodes(T);
	printf("此二叉树的叶子结点数是%d\n", leafnode);
	treedepth = Depth(T);
	printf("此二叉树的深度是%d\n", treedepth);
	ExchangeTree(&T);
	printf("交换左右子树后的先序序列是：");
	PreOrderTraverse(T, PrintElement);
	printf("\n");
	system("pause");
	return 0;
}