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
	//���������������㷨

	//�ڸ�ָ��T��ָ�����������еݹ�Ĳ�����ؼ��ֵ���key������Ԫ�أ������ҳɹ�
	//���ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·���Ϸ��ʵ�
	//���һ����㲢����TRUE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
	if (!T) {
		*p = f;
		return FALSE;
	}//���Ҳ��ɹ�
	else if (key == T->data) {
		*p = T;
		return TRUE;
	}//���ҳɹ�
	else if (key < T->data)
		return SearchBST(T->lchild, key, T, p);//���������м�������
	else
		return SearchBST(T->rchild, key, T, p);//���������м�������
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
			*T = s;     // ������* s Ϊ�µĸ����     
		}
		else if (e < p->data)
		{
			p->lchild = s;  // ������* s Ϊ����   
		}
		else
		{
			p->rchild = s;  // ������* s Ϊ�Һ���    
		}
		return TRUE;
	}
	else
	{
		return FALSE;   // �������йؼ�����ͬ�Ľ�㣬���ٲ���   
	}
}

Status Delete(BiTree *p)
{//�Ӷ�����������ɾ�����p �����ؽ����������������
	BiTree q, s;
	if (!(*p)->rchild)
	{//������Ϊ����ֻ���ؽ����������������
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)//������Ϊ�գ��ؽ�������
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else//�������������� 
	{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		} //ת��Ȼ�������ߵ���ͷ 
		(*p)->data = s->data;//sָ��ɾ���ġ�ǰ���� 
		if (q != *p)
			q->rchild = s->lchild;//�ؽ�*p�������� 
		else
			q->lchild = s->lchild;//�ؽ�*p�������� 
		free(s);
	}
	return OK;
}

Status DeleteBST(BiTree *T, KeyType key) {
	//�������������ϴ��ڹؼ��ֵ���key��Ԫ�أ�ɾ��������Ԫ�ؽ��
//������true,���򷵻�FALSE
	if (!*T)
		return FALSE;//�����ڹؼ��ֵ���key��Ԫ��
	else {
		if (key == (*T)->data)
			return  Delete(T);
		else if (key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else  return DeleteBST(&(*T)->rchild, key);
	}
}

Status PrintElement(ElemType e)
{//���Ԫ��e��ֵ
	printf("%4d", e);
	return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType e))
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

int main()
{
	int e, length;
	BiTree T, f, p;
	T = NULL;
	f = NULL;
	printf("����Ҫ����Ķ����������ĳ��ȣ�");
	scanf_s("%d", &length);
	printf("����Ԫ�أ�");
	while (length--)
	{
		scanf_s("%d", &e);
		InsertBST(&T, e);
	}
	printf("������������������������:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	printf("����Ҫ���ҵ�Ԫ�أ�");
	scanf_s("%d", &e);
	if (SearchBST(T, e, f, &p))
		printf("��Ԫ���ڴ˶�����������\n");
	else
		printf("��Ԫ�ز��ڴ˶�����������\n");

	printf("����Ҫ�����Ԫ�أ�");
	scanf_s("%d", &e);
	InsertBST(&T, e);
	printf("����Ԫ�غ������������������������:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	printf("����Ҫɾ����Ԫ��:");
	scanf_s("%d", &e);
	DeleteBST(&T, e);
	printf("����Ԫ�غ������������������������:");
	InOrderTraverse(T, PrintElement);
	printf("\n");

	system("pause");
	return 0;
}




