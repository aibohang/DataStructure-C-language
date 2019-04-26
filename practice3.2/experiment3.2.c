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
	SElemType data;//数据域
	struct linknode*next;//指针域
}LiStack;
LiStack*  InitStack(int n)
{
	LiStack *S;
	LiStack*p;
	S = (LiStack*)malloc(sizeof(LiStack));
	S->next = NULL;
	printf("输入栈中元素：");
	for (int i = n; i > 0; i--)
	{
		p = (LiStack*)malloc(sizeof(LiStack));//生成新节点
		scanf_s("%d", &p->data);//输入元素值
		p->next = S->next;
		S->next = p;//插入到表头
	}
	return S;
}
Status Push(LiStack*S, SElemType e)
{
	LiStack*p;
	p = (LiStack*)malloc(sizeof(LiStack));
	p->data = e;//新建元素e对应的结点p
	p->next = S->next;//插入p结点作为开始结点
	S->next = p;
	return OK;
}
Status Pop(LiStack*S)
{
	LiStack *p;
	SElemType e;
	if (S->next == NULL)
		return FALSE;
	p = S->next;//p指向开始结点
	e = p->data;
	S->next = p->next;//删除*P结点
	free(p);//释放*p结点
	return OK;
}
Status GetTop(LiStack*S)
{
	SElemType e;
	if (S->next == NULL)//栈空的情况
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
	printf("请输入栈中的数据元素个数：");
	scanf_s("%d", &n);
	S = InitStack(n);
	printf("栈中的数据元素是：");
	PrintLiStack(S);
	printf("栈顶元素是：");
	GetTop(S);
	printf("\n");
	printf("请输入要入栈的元素：");
	scanf_s("%d", &e);
	Push(S, e);
	printf("入栈后栈中元素是：");
	PrintLiStack(S);
	Pop(S);
	printf("出栈后栈中元素是：");
	PrintLiStack(S);
	system("pause");
	return 0;
}