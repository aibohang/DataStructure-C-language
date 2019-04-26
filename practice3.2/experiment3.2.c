#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
typedef int Status;
typedef int SElemType;
typedef struct linknode {
	SElemType data;//������
	struct linknode*next;//ָ����
}LiStack;
LiStack*  InitStack(int n)
{
	LiStack *S;
	LiStack*p;
	S = (LiStack*)malloc(sizeof(LiStack));
	S->next = NULL;
	printf("����ջ��Ԫ�أ�");
	for (int i = n; i > 0; i--)
	{
		p = (LiStack*)malloc(sizeof(LiStack));//�����½ڵ�
		scanf_s("%d", &p->data);//����Ԫ��ֵ
		p->next = S->next;
		S->next = p;//���뵽��ͷ
	}
	return S;
}
Status Push(LiStack*S, SElemType e)
{
	LiStack*p;
	p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;//�½�Ԫ��e��Ӧ�Ľ��p
	p->next = S->next;//����p�����Ϊ��ʼ���
	S->next = p;
	return OK;
}
Status Pop(LiStack*S)
{
	LiStack *p;
	SElemType e;
	if (S->next == NULL)
		return FALSE;
	p = S->next;//pָ��ʼ���
	e = p->data;
	S->next = p->next;//ɾ��*P���
	free(p);//�ͷ�*p���
	return OK;
}
Status GetTop(LiStack*S)
{
	SElemType e;
	if (S->next == NULL)//ջ�յ����
		return FALSE;
	e = S->next->data;
	printf("%d", e);
	return OK;
}
void PrintLiStack(LiStack *S)
{
	LiStack *p;
	p = S->next;
	while (p != NULL)
	{
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LiStack *S;
	SElemType e;
	int n;
	printf("������ջ�е�����Ԫ�ظ�����");
	scanf_s("%d", &n);
	S = InitStack(n);
	printf("ջ�е�����Ԫ���ǣ�");
	PrintLiStack(S);
	printf("ջ��Ԫ���ǣ�");
	GetTop(S);
	printf("\n");
	printf("������Ҫ��ջ��Ԫ�أ�");
	scanf_s("%d", &e);
	Push(S, e);
	printf("��ջ��ջ��Ԫ���ǣ�");
	PrintLiStack(S);
	Pop(S);
	printf("��ջ��ջ��Ԫ���ǣ�");
	PrintLiStack(S);
	system("pause");
	return 0;
}