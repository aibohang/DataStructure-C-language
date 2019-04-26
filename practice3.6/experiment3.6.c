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
Status Pop(SqStack *S) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR;
	if (S->top == S->base)
	{
		printf("ջ��");
		return ERROR;
	}
	return *--S->top;//--S->top;	e=*S->top;
}
SElemType GetTop(SqStack *S) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ�������OK�����򷵻�ERRER
	if (S->top = S->base)
	{
		//	printf("ջ��");
		return ERROR;
	}
	return *(S->top - 1);//ȡջ��Ԫ��
}
Status StackEmpty(SqStack *S) {
	if (S->top == S->base)
	{
		//printf("ջ��");
		return TRUE;
	}
	else
	{
		//	printf("ջ�ǿ�");
		return FALSE;
	}
}
Status Match(SqStack *S) {
	char c, x;
	c = getchar();
	while (c != '@') {
		Push(S, c);
		c = getchar();
	}
	c = getchar();
	while (c != '@' && !StackEmpty(S)) { //c���������ĶԳƵı��'@'ͬʱSջ�������ǿյ�
		x = Pop(S);
		if (c == x)
			c = getchar();
		else {
			printf("not match\n");
			return ERROR;
		}
	}
	if (c == '#'&&StackEmpty(S))//Ϊ�˽��ǰ�벿��ȷʵƥ�����ˣ�����"@"��ߵĲ��ֳ�����ǰ�߲��ֵĳ���
	{
		printf("match!\n");
		return OK;
	}
	else
	{
		printf("not match\n");
		return ERROR;
	}
}
int main()
{
	SqStack S;
	InitStack(&S);
	printf("�������ַ����У��Գ�������'@'����'#'������\n");
	Match(&S);
	system("pause");
	return 0;
}