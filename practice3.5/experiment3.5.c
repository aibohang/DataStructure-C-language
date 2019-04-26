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
	//构造一个空栈，该栈由指针指示
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//栈的连续空间分配
	if (!S->base)
		exit(OVERFLOW);//存储分配失败
	S->top = S->base;//空栈，初始化栈顶指针
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack *S, SElemType e) {
	//插入元素e作为新的栈顶
	if (S->top - S->base >= S->stacksize) {
		//栈满，追加存储空间
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
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR;
	if (S->top == S->base)
	{
		printf("栈空");
		return ERROR;
	}
	return *--S->top;
}
SElemType GetTop(SqStack *S) {
	//若栈不空，则删除S的栈顶元素，并返回OK,否则返回ERRER
	if (S->top == S->base)
	{
		printf("栈空");
		return OK;
	}
	return *(S->top - 1);//取栈顶元素
}
Status StackEmpty(SqStack *S)
{
	if (S->top == S->base)
	{
		//	printf("栈空");
		return TRUE;
	}
	else
	{
		//	printf("栈非空");
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
			Push(S, c);//如果接收到的是右括号就把他送进栈中 
		if (c == ')' || c == ']' || c == '}')
		{
			if (StackEmpty(S))
			{
				printf("not match!\n");
				return ERROR;
			}//  情况1：避免出现输入的全是右括号:}])
			x = Pop(S);
			if (!((x == '('&&c == ')') || (x == '['&&c == ']') || (x == '{'&&c == '}')))
			{
				printf("not match!\n");
				return ERROR;
			}//情况2：避免到来的右括号不是所期待的:[)		
		}//if语句结束
		c = getchar();
	}//while循环结束 
	if (StackEmpty(S))
	{
		printf("match!\n");
		return OK;
	}
	else
	{
		printf("not match!\n");
		return ERROR;//情况3：直到最后结束，也没有到来所期待的括号 :([]#
	}
}//BracketsMatch函数结束 
int main()
{
	SqStack S;
	InitStack(&S);
	printf("请输入括号(以#作为结束符)：");
	BracketsMatch(&S);
	system("pause");
	return 0;
}