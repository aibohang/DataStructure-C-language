#include<stdio.h>
#include<stdlib.h>
#define FALSE 0 
#define ERROR 0
#define OK 1
#define OVERFLOW 0
#define STACK_INIT_SIZE 100//存储空间初始分配增量
#define STACKINCREMRNT 10//存储空间分配增量
typedef int SElemType;
typedef int Status;
typedef struct {
	SElemType *base;//在栈构造和销毁之后，base的值为NULL
								//栈低指针，始终指向存储空间基址
	SElemType *top;//栈顶指针，指向栈顶元素的下一个位置
	int stacksize;//当前已分配的存储空间，以元素为单位。
						//数组存储空间的长度。
}SqStack;
Status InitStack(SqStack *S, int n)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		exit(OVERFLOW);//存储分配失败
	S->top = S->base;
	S->stacksize = STACKINCREMRNT;
	printf("输入栈中元素：");
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
		printf("栈中无元素");
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
{//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stacksize)
	{//栈满，追加存储空间
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMRNT) * sizeof(SElemType));
		if (!S->base)
			exit(OVERFLOW);//存储分配失败
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMRNT;
	}
	*S->top = e;
	S->top++;
	return OK;
}
SElemType Pop(SqStack *S)
{//出栈
	SElemType e;
	if (S->top == S->base)
		return ERROR;
	--S->top;
	e = *S->top;
	return e;
}
Status GetTop(SqStack S)
{//若栈不空,则用e返回S的栈顶元素,并返回OK;否则返回ERROR
	SElemType e;
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	printf("%d", e);//显示栈顶元素
	return OK;
}
int main()
{
	SqStack S;
	SElemType e;
	int n;
	printf("输入你要建立的栈中元素的个数:");
	scanf_s("%d", &n);
	InitStack(&S, n);
	printf("栈中元素是：");
	Show(S);
	printf("栈顶元素是:");
	GetTop(S);
	printf("\n");
	printf("请输入你要入栈的元素:");
	scanf_s("%d", &e);
	Push(&S, e);
	printf("入栈后:");
	Show(S);
	Pop(&S);
	printf("出栈后:");
	Show(S);
	system("pause");
	return 0;
}