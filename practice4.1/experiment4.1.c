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
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))//访问左子树
			if (Visit(T->data))//访问根结点
				if (InOrderTraverse(T->rchild, Visit))//访问右子树
					return OK;
		return ERROR;
	}
	else
		return OK;
}
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))//访问左子树
			if (PostOrderTraverse(T->rchild, Visit))//访问右子树
				if (Visit(T->data))//访问根结点
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int main()
{
	BiTree T;
	printf("输入二叉树中的数据元素：");
	CreateBiTree(&T);
	printf("先序遍历二叉树的序列是：");
	PreOrderTraverse(T, PrintElement);
	printf("\n");
	printf("中遍历二叉树的序列是：");
	InOrderTraverse(T, PrintElement);
	printf("\n");
	printf("后序遍历二叉树的序列是：");
	PostOrderTraverse(T, PrintElement);
	printf("\n");
	system("pause");
	return 0;
}