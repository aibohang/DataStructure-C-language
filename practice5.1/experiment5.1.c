#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define INFINITY 1000	//���ֵ
#define MAX_VERTEX_NUM 20   //��󶥵���
#define STACK_INIT_SIZE 100
#define MAXQSIZE 100
typedef int  QElemType;
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
typedef enum { DG, DN, UDG, UDN } GraphKind;//{����ͼ��������������ͼ��������}
typedef int Status;
typedef int VRType;
typedef int InfoType;
typedef char VertexType;//��������
typedef struct ArcCell {
	VRType adj;//VRType�����ϵ���ͣ�������Ȩͼ��0,1��ʾ��ȷ�
						//�Դ�Ȩͼ����ΪȨֵ����
	InfoType *info;//��ʾ�û������Ϣָ��
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���,����Ȩֵ
	int vexnum;//ͼ�ĵ�ǰ������
	int arcnum;//ͼ�Ļ���
	GraphKind kind;//ͼ�������־
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
	printf("����ͼ�Ľڵ������ܱ���:");
	scanf_s("%d %d", &G->vexnum, &G->arcnum);
	getchar();//��������ڵ������������
	for (i = 0; i < G->vexnum; i++) {
		printf("�������%d���������Ϣ��", i + 1);
		scanf_s("%c", &G->vexs[i], 1);
		getchar();//��Ϊ������ǵ����ַ���Ҫ����ÿ��������֮��Ļس���
	}
	for (i = 0; i < G->vexnum; i++)
		for (j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ͼ��%d���ߵ���������͸ñߵ�Ȩֵ��", k + 1);
		scanf_s("%c %c %d", &v1, 1, &v2, 1, &w);
		getchar();//����ÿ��������֮�����Ļس���
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
	return OK;
}
Status PrintGraph(MGraph G) {
	int i, j;
	printf("\nͼ�Ķ���Ϊ��");
	for (i = 0; i < G.vexnum; i++)
		printf("%c", G.vexs[i]);
	printf("\nͼ���ڽӾ���\n");
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
Boolean visited[MAX_VERTEX_NUM];//���ʱ�־����
int FirstAdjVex(MGraph G, int v)
{//��v�ĵ�һ���ڽӵ�
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[v][i].adj != 0)
			return i;
	return 0;
}
int NextAdjVex(MGraph G, int v, int w)
{//��v�������w����һ���ڽӵ�
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
{//��ͼ��������ȱ���
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;//���������ʼ�������ж��㶼��δ����״̬
	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
			DFS(G, v);//����δ���ʵĶ������DFS,������ͨͼ,ֻ��ִ��һ��
	}
}
void BFSTraverse(MGraph G)
{
	int v, w;
	SqQueue Q;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = FALSE;
	InitQueue(&Q);//�ÿյĸ�������Q
	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{//v��δ����
			visited[v] = TRUE;
			printf("%2c", G.vexs[v]);
			EnQueue(&Q, v);//v�����
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &v);//��ͷԪ�س��Ӳ���Ϊu

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
					{//wΪu����δ���ʵ��ڽӶ���
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
	printf("ͼ��������ȱ���������:");
	DFSTraverse(G);
	printf("\n");
	printf("ͼ�Ĺ�����ȱ���������:");
	BFSTraverse(G); 
	printf("\n");
	system("pause");
	return 0;
}
