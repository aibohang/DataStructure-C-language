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
/*
Status EqualTwoTree(BiTree T1, BiTree T2)
{//��������ж����ö������Ƿ����
	Status flag;
	if (T1 == NULL && T2 == NULL)
		flag = TRUE;//��������Ϊ��
	else if (T1 == NULL || T2 == NULL)
		flag = FALSE;//��������һ����Ϊ��
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
	printf("���������T1�е�����Ԫ�أ�");
	CreateBiTree(&T1);
	getchar();
	printf("�������������T1�������ǣ�");
	PreOrderTraverse(T1, PrintElement);
	printf("\n");
	printf("���������T2�е�����Ԫ�أ�");
	CreateBiTree(&T2);
	printf("�������������T2�������ǣ�");
	PreOrderTraverse(T2, PrintElement);
	printf("\n");
	if (EqualTwoTree(T1, T2))
		printf("���������\n");
	else
		printf("�����������\n");
	system("pause");
	return 0;
}