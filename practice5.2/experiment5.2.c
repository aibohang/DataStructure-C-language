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

typedef struct ArcNode { //�������Ͷ���
	int adjvex;//����λ�ñ��
	struct ArcNode *nextarc;//ָ����һ�����ָ��
	InfoType *info;//�û������Ϣ��ָ��
} ArcNode;
/* �����*/
typedef struct VNode { //ͷ��㼰�������Ͷ���
	VertexType data;//������Ϣ
	ArcNode *firstarc;//ָ���һ����
} VNode, AdjList[MAX_VERTEX_NUM];
/*ͼ�ṹ*/
typedef struct {
	AdjList vertices;//ͷ�������
	int vexnum;//ͼ��ǰ������
	int arcnum;//ͼ��ǰ����
} ALGraph;

typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status QueueEmpty(SqQueue Q)//���пշ���1�����շ���0
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
{//ͷ�巨����ͼ���ڽӱ�ṹ
	printf("����ͼ�Ķ������ͱ���:");
	scanf_s("%d %d", &G->vexnum, &G->arcnum);
	getchar(); //���ܻس� 
	printf("����ͼ�и�������ֵ\n");
	for (int i = 1; i <= G->vexnum; i++)
	{//���붥����Ϣ���������
		printf("�������%d���������Ϣ:", i);
		scanf_s("%c", &G->vertices[i].data, 1);
		getchar();//���ջس�
		G->vertices[i].firstarc = NULL;//���߱���Ϊ�ձ�
	}
	for (int i = 1; i <= G->arcnum; i++)
	{//������<s,d><d,s>����Ϣ
		int s, d;
		ArcNode*p, *q;
		printf("�����%d�����й����Ķ�������:", i);
		scanf_s("%d %d", &s, &d);
		getchar();//���ܻس�
		p = (ArcNode*)malloc(sizeof(ArcNode));//�ߵ�ָ�� 
		q = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = d;			q->adjvex = s;
		p->nextarc = G->vertices[s].firstarc;		G->vertices[s].firstarc = p;//<d,s>������������
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
		if (!visited[w->adjvex])  DFS(G, w->adjvex);  //��v����δ���ʵ��ڽӶ���w����DFS
}

void DFSTraverse(ALGraph G)
{
	int v;
	VisitFunc = Print;   //ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
	for (v = 1; v <= G.vexnum; ++v)  visited[v] = FALSE;
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v]) DFS(G, v);//��ÿ��δ�����ʵĶ������DFS
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
	InitQueue(&Q);//��ʼ��
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v])//vû�б�����
		{
			visited[v] = TRUE;
			Visit(v, G);
			EnQueue(&Q, v);//�����
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &u);
				w = G.vertices[u].firstarc;
				for (w = G.vertices[u].firstarc; w; w = w->nextarc)
					if (!visited[w->adjvex])//wΪu����δ���ʵ��ڽӶ���
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
	printf("������ȱ����������ǣ�");
	DFSTraverse(G);
	printf("������ȱ����������ǣ�");
	BFSTraverse(G, Print);
	system("pause");
	return 0;
}