#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
typedef int Status;
typedef int KeyType;
typedef int ElemType;
typedef struct BiTNode {
	KeyType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p) {
	//二叉排序树查找算法

	//在根指针T所指二叉排序树中递归的查找其关键字等于key的数据元素，若查找成功
	//则根指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上访问的
	//最后一个结点并返回TRUE，指针f指向T的双亲，其初始调用值为NULL
	if (!T) {
		*p = f;
		return FALSE;
	}//查找不成功
	else if (key == T->data) {
		*p = T;
		return TRUE;
	}//查找成功
	else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);//在左子树中继续查找
	else
		return SearchBST(T->rchild, key, T, p);//在右子树中继续查找
}

Status InsertBST(BiTree *T, ElemType e)
{
	BiTree p, s;
	if (!SearchBST(*T, e, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s;     // 被插结点* s 为新的根结点     
		}
		else if (e < p->data)
		{
			p->lchild = s;  // 被插结点* s 为左孩子   
		}
		else
		{
			p->rchild = s;  // 被插结点* s 为右孩子    
		}
		return TRUE;
	}
	else
	{
		return FALSE;   // 树中已有关键字相同的结点，不再插入   
	}
}

Status Delete(BiTree *p)
{//从二叉排序树中删除结点p ，并重接他的左或者右子树
	BiTree q, s;
	if (!(*p)->rchild)
	{//右子树为空则只需重接他的左或者右子树
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)//左子树为空，重接右子树
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else//左右子树都不空 
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		} //转左，然后向右走到尽头 
		(*p)->data = s->data;//s指向被删结点的“前驱” 
		if (q != *p)
			q->rchild = s->lchild;//重接*p的右子树 
		else
			q->lchild = s->lchild;//重接*p的左子树 
		free(s);
	}
	return OK;
}

Status DeleteBST(BiTree *T, KeyType key) {
	//若二叉排序树上存在关键字等于key的元素，删除该数据元素结点
//并返回true,否则返回FALSE
	if (!*T)
		return FALSE;//不存在关键字等于key的元素
	else {
		if (key == (*T)->data)
			return  Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else  return DeleteBST(&(*T)->rchild, key);
	}
}

Status PrintElement(ElemType e)
{//输出元素e的值
	printf("%4d", e);
	return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType e))
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

int main()
{
	int e, length;
	BiTree T, f, p;
	T = NULL;
	f = NULL;
	printf("输入要构造的二叉排序树的长度：");
	scanf_s("%d", &length);
	printf("输入元素：");
	while (length--)
	{
		scanf_s("%d", &e);
		InsertBST(&T, e);
	}
	printf("二叉排序树的中序遍历结果是:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	printf("输入要查找的元素：");
	scanf_s("%d", &e);
	if (SearchBST(T, e, f, &p))
		printf("该元素在此二叉排序树中\n");
	else
		printf("该元素不在此二叉排序树中\n");

	printf("输入要插入的元素：");
	scanf_s("%d", &e);
	InsertBST(&T, e);
	printf("插入元素后二叉排序树的中序遍历结果是:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	printf("输入要删除的元素:");
	scanf_s("%d", &e);
	DeleteBST(&T, e);
	printf("插入元素后二叉排序树的中序遍历结果是:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	system("pause");
	return 0;
}




