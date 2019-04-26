#include<stdio.h>
#include<stdlib.h>
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ��������
#define STACKINCREMRNT 10//�洢�ռ��������
typedef int SElemType;
typedef int Status;
typedef struct {
	SElemType *base;//��ջ���������֮��base��ֵΪNULL
								//ջ��ָ�룬ʼ��ָ��洢�ռ��ַ
	SElemType *top;//ջ��ָ�룬ָ��ջ��Ԫ�ص���һ��λ��
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ��
						//����洢�ռ�ĳ��ȡ�
}SqStack;
Status InitStack(SqStack *S, int n)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		exit(OVERFLOW);//�洢����ʧ��
	S->top = S->base;
	S->stacksize = STACKINCREMRNT;
	printf("����ջ��Ԫ�أ�");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &*S->top);
		S->top++;
	}
	return OK;
}
Status Show(SqStack S)
{
	if (S.top == S.base)
	{
		printf("ջ����Ԫ��");
		return ERROR;
	}
	SElemType*p;
	p = S.top;
	while (p > S.base)
	{
		p--;
		printf("%5d", *p);
	}
	printf("\n");
}
Status Push(SqStack *S, SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S->top - S->base >= S->stacksize)
	{//ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMRNT) * sizeof(SElemType));
		if (!S->base)
			exit(OVERFLOW);//�洢����ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMRNT;
	}
	*S->top = e;
	S->top++;
	return OK;
}
SElemType Pop(SqStack *S)
{//��ջ
	SElemType e;
	if (S->top == S->base)
		return ERROR;
	--S->top;
	e = *S->top;
	return e;
}
Status GetTop(SqStack S)
{//��ջ����,����e����S��ջ��Ԫ��,������OK;���򷵻�ERROR
	SElemType e;
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	printf("%d", e);//��ʾջ��Ԫ��
	return OK;
}
int main()
{
	SqStack S;
	SElemType e;
	int n;
	printf("������Ҫ������ջ��Ԫ�صĸ���:");
	scanf_s("%d", &n);
	InitStack(&S, n);
	printf("ջ��Ԫ���ǣ�");
	Show(S);
	printf("ջ��Ԫ����:");
	GetTop(S);
	printf("\n");
	printf("��������Ҫ��ջ��Ԫ��:");
	scanf_s("%d", &e);
	Push(&S, e);
	printf("��ջ��:");
	Show(S);
	Pop(&S);
	printf("��ջ��:");
	Show(S);
	system("pause");
	return 0;
}