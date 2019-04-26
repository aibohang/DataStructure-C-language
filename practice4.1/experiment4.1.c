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
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))//����������
			if (Visit(T->data))//���ʸ����
				if (InOrderTraverse(T->rchild, Visit))//����������
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
		if (PostOrderTraverse(T->lchild, Visit))//����������
			if (PostOrderTraverse(T->rchild, Visit))//����������
				if (Visit(T->data))//���ʸ����
					return OK;
		return ERROR;
	}
	else
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
	printf("�б����������������ǣ�");
	InOrderTraverse(T, PrintElement);
	printf("\n");
	printf("��������������������ǣ�");
	PostOrderTraverse(T, PrintElement);
	printf("\n");
	system("pause");
	return 0;
}