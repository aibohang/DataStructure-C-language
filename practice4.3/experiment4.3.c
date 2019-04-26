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
/*
Status EqualTwoTree(BiTree T1, BiTree T2)
{//先序遍历判断两棵二叉树是否相等
	Status flag;
	if (T1 == NULL && T2 == NULL)
		flag = TRUE;//两棵树都为空
	else if (T1 == NULL || T2 == NULL)
		flag = FALSE;//两棵树有一棵树为空
	else
	{
		if (T1->data == T2->data)      flag = TRUE;
		else { flag = FALSE;  return flag; }
		if (flag)
		{
			EqualTwoTree(T1->lchild, T2->lchild);
			EqualTwoTree(T1->rchild, T2->rchild);
		}
	}
	return flag;
}
*/
Status EqualTwoTree(BiTree T1, BiTree T2)
{
	if (T1 == NULL && T2 == NULL)
		return TRUE;
	if (T1 != NULL && T2 != NULL && T1->data&&T2->data&&EqualTwoTree(T1->lchild, T2->lchild) && EqualTwoTree(T1->rchild, T2->rchild))
		return FALSE;
	return FALSE;
}
int main()
{
	BiTree T1, T2;
	printf("输入二叉树T1中的数据元素：");
	CreateBiTree(&T1);
	getchar();
	printf("先序遍历二叉树T1的序列是：");
	PreOrderTraverse(T1, PrintElement);
	printf("\n");
	printf("输入二叉树T2中的数据元素：");
	CreateBiTree(&T2);
	printf("先序遍历二叉树T2的序列是：");
	PreOrderTraverse(T2, PrintElement);
	printf("\n");
	if (EqualTwoTree(T1, T2))
		printf("两棵树相等\n");
	else
		printf("两棵树不相等\n");
	system("pause");
	return 0;
}