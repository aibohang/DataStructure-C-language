#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define INFINITY 1000	//最大值
#define MAX_VERTEX_NUM 20   //最大顶点数
#define STACK_INIT_SIZE 100
#define MAXQSIZE 100
typedef int  QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
typedef enum { DG, DN, UDG, UDN } GraphKind;//{有向图，有向网，无向图，无向网}
typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef char VertexType;//数据类型
typedef struct ArcCell {
	VRType adj;//VRType顶点关系类型，对于无权图用0,1表示相等否
						//对带权图，则为权值类型
	InfoType *info;//表示该弧相关信息指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵,各边权值
	int vexnum;//图的当前顶点数
	int arcnum;//图的弧数
	GraphKind kind;//图的种类标志
} MGraph;
Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}
Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		return OVERFLOW;
	Q->front = Q->rear = 0;
	return OK;
}
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)  return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}
int LocateVex(MGraph *G, VertexType v)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vexs[i] == v)
			return i;
	}
	return -1;
}
Status CreateUND(MGraph *G)
{
	int i, j, k;
	VertexType v1, v2;
	VRType w;
	printf("输入图的节点数和总边数:");
	scanf_s("%d %d", &G->vexnum, &G->arcnum);
	getchar();//接收输入节点数，边数后的
	for (i = 0; i < G->vexnum; i++) {
		printf("请输入第%d个顶点的信息：", i + 1);
		scanf_s("%c", &G->vexs[i], 1);
		getchar();//因为输入的是单个字符，要接收每次输入完之后的回车键
	}
	for (i = 0; i < G->vexnum; i++)
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("输入图第%d条边的两个顶点和该边的权值：", k + 1);
		scanf_s("%c %c %d", &v1, 1, &v2, 1, &w);
		getchar();//接收每次输入完之后键入的回车键
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
	return OK;
}
Status PrintGraph(MGraph G) {
	int i, j;
	printf("\n图的顶点为：");
	for (i = 0; i < G.vexnum; i++)
		printf("%c", G.vexs[i]);
	printf("\n图的邻接矩阵\n");
	printf("\t");
	for (i = 0; i < G.vexnum; i++)
		printf("\t%8c", G.vexs[i]);
	for (i = 0; i < G.vexnum; i++) {
		printf("\n\n%8c", G.vexs[i]);
		for (j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j].adj == INFINITY)
				printf("\t%8s", "00");
			else
				printf("\t%8d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
	return OK;
}
typedef int Boolean;
Boolean visited[MAX_VERTEX_NUM];//访问标志数组
int FirstAdjVex(MGraph G, int v)
{//求v的第一个邻接点
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[v][i].adj != 0)
			return i;
	return 0;
}
int NextAdjVex(MGraph G, int v, int w)
{//求v的相对于w的下一个邻接点
	int k;
	for (k = w + 1; k < G.vexnum; k++)
		if (G.arcs[v][k].adj != 0)
			return k;
	return 0;
}
void DFS(MGraph G, int v)
{
	int w;
	visited[v] = TRUE;
	printf("%2c", G.vexs[v]);
	for (w = FirstAdjVex(G, v); w > 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])
			DFS(G, w);
	}
}
void DFSTraverse(MGraph G)
{//对图做深度优先遍历
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;//访问数组初始化，所有顶点都是未访问状态
	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
			DFS(G, v);//对尚未访问的顶点调用DFS,若是连通图,只会执行一次
	}
}
void BFSTraverse(MGraph G)
{
	int v, w;
	SqQueue Q;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;
	InitQueue(&Q);//置空的辅助队列Q
	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{//v尚未访问
			visited[v] = TRUE;
			printf("%2c", G.vexs[v]);
			EnQueue(&Q, v);//v入队列
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &v);//队头元素出队并置为u

				for (w = 0; w < G.vexnum; ++w)
				{
					if (!visited[w] && G.arcs[v][w].adj != INFINITY)
					{
						visited[w] = TRUE;
						printf("%2c", G.vexs[w]);
						EnQueue(&Q, w);
					}
				}
				/*
				for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
				{
					if (!visited[w] && G.arcs[v][w].adj != INFINITY)
					{//w为u的尚未访问的邻接顶点
						visited[w] = TRUE;
						printf("%2c", G.vexs[w]);
						EnQueue(&Q, w);
					}
				}
				*/
			}
		}
	}
}
int main()
{
	MGraph G;
	CreateUND(&G);
	PrintGraph(G);
	printf("图的深度优先遍历序列是:");
	DFSTraverse(G);
	printf("\n");
	printf("图的广度优先遍历序列是:");
	BFSTraverse(G); 
	printf("\n");
	system("pause");
	return 0;
}
