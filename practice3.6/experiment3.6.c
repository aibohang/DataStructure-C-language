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
Status Pop(SqStack *S) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR;
	if (S->top == S->base)
	{
		printf("栈空");
		return ERROR;
	}
	return *--S->top;//--S->top;	e=*S->top;
}
SElemType GetTop(SqStack *S) {
	//若栈不空，则删除S的栈顶元素，并返回OK，否则返回ERRER
	if (S->top = S->base)
	{
		//	printf("栈空");
		return ERROR;
	}
	return *(S->top - 1);//取栈顶元素
}
Status StackEmpty(SqStack *S) {
	if (S->top == S->base)
	{
		//printf("栈空");
		return TRUE;
	}
	else
	{
		//	printf("栈非空");
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
	while (c != '@' && !StackEmpty(S)) { //c不等于中心对称的标记'@'同时S栈还不能是空的
		x = Pop(S);
		if (c == x)
			c = getchar();
		else {
			printf("not match\n");
			return ERROR;
		}
	}
	if (c == '#'&&StackEmpty(S))//为了解决前半部分确实匹配上了，但是"@"后边的部分超过了前边部分的长度
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
	printf("请输入字符序列，对称中心是'@'，以'#'结束！\n");
	Match(&S);
	system("pause");
	return 0;
}