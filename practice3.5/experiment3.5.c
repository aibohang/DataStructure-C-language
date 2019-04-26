#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;
Status InitStack(SqStack *S) {
	//����һ����ջ����ջ��ָ��ָʾ
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//ջ�������ռ����
	if (!S->base)
		exit(OVERFLOW);//�洢����ʧ��
	S->top = S->base;//��ջ����ʼ��ջ��ָ��
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack *S, SElemType e) {
	//����Ԫ��e��Ϊ�µ�ջ��
	if (S->top - S->base >= S->stacksize) {
		//ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top = e;
	S->top++;
	return OK;
}
SElemType Pop(SqStack *S) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR;
	if (S->top == S->base)
	{
		printf("ջ��");
		return ERROR;
	}
	return *--S->top;
}
SElemType GetTop(SqStack *S) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ�������OK,���򷵻�ERRER
	if (S->top == S->base)
	{
		printf("ջ��");
		return OK;
	}
	return *(S->top - 1);//ȡջ��Ԫ��
}
Status StackEmpty(SqStack *S)
{
	if (S->top == S->base)
	{
		//	printf("ջ��");
		return TRUE;
	}
	else
	{
		//	printf("ջ�ǿ�");
		return FALSE;
	}
}
Status BracketsMatch(SqStack *S)
{
	char c, x;
	c = getchar();
	while (c != '#')
	{
		if (c == '(' || c == '[' || c == '{')
			Push(S, c);//������յ����������žͰ����ͽ�ջ�� 
		if (c == ')' || c == ']' || c == '}')
		{
			if (StackEmpty(S))
			{
				printf("not match!\n");
				return ERROR;
			}//  ���1��������������ȫ��������:}])
			x = Pop(S);
			if (!((x == '('&&c == ')') || (x == '['&&c == ']') || (x == '{'&&c == '}')))
			{
				printf("not match!\n");
				return ERROR;
			}//���2�����⵽���������Ų������ڴ���:[)		
		}//if������
		c = getchar();
	}//whileѭ������ 
	if (StackEmpty(S))
	{
		printf("match!\n");
		return OK;
	}
	else
	{
		printf("not match!\n");
		return ERROR;//���3��ֱ����������Ҳû�е������ڴ������� :([]#
	}
}//BracketsMatch�������� 
int main()
{
	SqStack S;
	InitStack(&S);
	printf("����������(��#��Ϊ������)��");
	BracketsMatch(&S);
	system("pause");
	return 0;
}