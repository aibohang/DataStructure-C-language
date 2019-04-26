#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
#define maxsize 100
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERFLOW 0
#define STACK_INIT_SIZE 100
#define MAXQSIZE 100
typedef int QElemType;
typedef char VertexType;
typedef int Status;
typedef int InfoType;

typedef struct ArcNode { //表结点类型定义
	int adjvex;//顶点位置编号
	struct ArcNode *nextarc;//指向下一表结点的指针
	InfoType *info;//该弧相关信息的指针
} ArcNode;
/* 顶点表*/
typedef struct VNode { //头结点及数组类型定义
	VertexType data;//顶点信息
	ArcNode *firstarc;//指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];
/*图结构*/
typedef struct {
	AdjList vertices;//头结点数组
	int vexnum;//图当前顶点数
	int arcnum;//图当前弧数
} ALGraph;

typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status QueueEmpty(SqQueue Q)//队列空返回1，不空返回0
{
	if (Q.rear == Q.front)
		return OK;
	else return ERROR;
}
Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base) return OVERFLOW;
	Q->front = Q->rear = 0;
	return OK;
}

int QueneLength(SqQueue Q)
{
	return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front) return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear) return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;

}

void CreateUDG(ALGraph *G)
{//头插法建立图的邻接表结构
	printf("输入图的顶点数和边数:");
	scanf_s("%d %d", &G->vexnum, &G->arcnum);
	getchar(); //接受回车 
	printf("输入图中各个结点的值\n");
	for (int i = 1; i <= G->vexnum; i++)
	{//读入顶点信息，建顶点表
		printf("请输入第%d个顶点的信息:", i);
		scanf_s("%c", &G->vertices[i].data, 1);
		getchar();//接收回车
		G->vertices[i].firstarc = NULL;//将边表置为空表
	}
	for (int i = 1; i <= G->arcnum; i++)
	{//建立边<s,d><d,s>的信息
		int s, d;
		ArcNode*p, *q;
		printf("输入第%d条边有关联的顶点的序号:", i);
		scanf_s("%d %d", &s, &d);
		getchar();//接受回车
		p = (ArcNode*)malloc(sizeof(ArcNode));//边的指针 
		q = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = d;			q->adjvex = s;
		p->nextarc = G->vertices[s].firstarc;		G->vertices[s].firstarc = p;//<d,s>，逆向建立链表
		q->nextarc = G->vertices[d].firstarc;		G->vertices[d].firstarc = q;//<s,d>
	}
}

void PrintGraph(ALGraph G)
{
	int i;
	for (i = 1; i <= G.vexnum; i++)
	{
		printf("%d->", i);
		while (1)
		{
			if (G.vertices[i].firstarc == NULL)
			{
				printf("^");
				break;
			}
			printf("%d->", G.vertices[i].firstarc->adjvex);
			G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
		}
		printf("\n");
	}
}


typedef int Boolean;
Boolean visited[maxsize];

Status(*VisitFunc)(int v, ALGraph G);

Status Print(int i, ALGraph G)
{
	printf("%2c", G.vertices[i].data);
	return OK;
}

void DFS(ALGraph G, int v)
{

	ArcNode *w;
	visited[v] = TRUE;
	VisitFunc(v, G);
	for (w = G.vertices[v].firstarc; w; w = w->nextarc)
		if (!visited[w->adjvex])  DFS(G, w->adjvex);  //对v的尚未访问的邻接顶点w调用DFS
}

void DFSTraverse(ALGraph G)
{
	int v;
	VisitFunc = Print;   //使用全局变量VisitFunc，使DFS不必设函数指针参数
	for (v = 1; v <= G.vexnum; ++v)  visited[v] = FALSE;
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v]) DFS(G, v);//对每个未被访问的顶点调用DFS
	printf("\n");
}

void BFSTraverse(ALGraph G, Status(*Visit)(int v, ALGraph))
{
	int u, v;
	ArcNode *w;
	Visit = Print;
	for (v = 1; v <= G.vexnum; ++v)
		visited[v] = FALSE;
	SqQueue Q;
	InitQueue(&Q);//初始化
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v])//v没有被访问
		{
			visited[v] = TRUE;
			Visit(v, G);
			EnQueue(&Q, v);//入队列
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &u);
				w = G.vertices[u].firstarc;
				for (w = G.vertices[u].firstarc; w; w = w->nextarc)
					if (!visited[w->adjvex])//w为u的尚未访问的邻接顶点
					{
						visited[w->adjvex] = TRUE;
						Visit(w->adjvex, G);
						EnQueue(&Q, w->adjvex);
					}
			}
		}
	printf("\n");
}

int main()
{
	ALGraph G;
	CreateUDG(&G);
	PrintGraph(G);
	printf("深度优先遍历的序列是：");
	DFSTraverse(G);
	printf("广度优先遍历的序列是：");
	BFSTraverse(G, Print);
	system("pause");
	return 0;
}