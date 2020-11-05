#include<stdio.h>
#include<malloc.h>
#define MaxSize 10                 /*图的最大顶点数*/
typedef char DataType;              /*定义图中顶点的数据类型，假设为char型*/
typedef struct EdgeNode              /*定义边表结点*/
{
	int adjvex;
	struct EdgeNode *next;
} EdgeNode;
typedef struct                      /*定义顶点表结点*/
{
	DataType vertex;
	int in;
	EdgeNode *first;
} VertexNode;
typedef struct                      /*定义邻接表存储结构*/
{
	VertexNode adjlist[MaxSize];      /*存放顶点表的数组*/
	int vertexNum, edgeNum;         /*图的顶点数和边数*/
} ALGraph;
void TopSort(ALGraph *G);
void CreatGraph(ALGraph *G,DataType a[],int n,int e);

int main()
{
	ALGraph G;
	int n, e;
	char a[6];
	printf("请输入顶点的个数：\n");
	scanf("%d", &n);
	printf("请输入边的条数：\n");
	scanf("%d", &e);
	printf("请输入顶点：\n");
	getchar();                        //用来接受换行符
	for (int i = 0; i < n; i++)
		scanf("%c", &a[i]);
	CreatGraph(&G,a,n,e);
	printf("拓扑序列为：\n");
	TopSort(&G);
	getchar(); getchar();
	return 0;
}

void CreatGraph(ALGraph *G,DataType a[],int n,int e)
{
	int i, j, k;
	EdgeNode *s = NULL;
	G->vertexNum=n;
	G->edgeNum=e;
	for (i = 0; i < G->vertexNum; i++)
	{
		G->adjlist[i].vertex=a[i];
	}
	printf("请输入顶点的入度：\n");
	fflush(stdin);
	for (i = 0; i < G->vertexNum; i++)
	{
		scanf("%d",&G->adjlist[i].in);
		
	}
	for (i = 0; i < G->vertexNum; i++)
	{
		G->adjlist[i].first = NULL;         /*初始化边表的头指针*/
	}
	
	printf("输入边所依附的顶点编号:\n");
	for (k = 0; k < G->edgeNum; k++)
	{
		scanf("%d %d", &i, &j);           /*输入边所依附的顶点编号*/
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = G->adjlist[i].first;        /*将s插入到第i个边表的表头*/
		G->adjlist[i].first = s;
	}
	
}

void TopSort(ALGraph *G)
{
	int i, j, k, count = 0;                    /*累加器count初始化*/
	int S[MaxSize], top = -1;                /*采用顺序栈并初始化*/
	EdgeNode *p = NULL;
	for (i = 0; i < G->vertexNum; i++)        /*扫描顶点表*/
	if (G->adjlist[i].in == 0)  S[++top] = i;  /*将入度为0的顶点压栈*/
	while (top != -1)                      /*当栈中还有入度为0的顶点时*/
	{
		j = S[top--];                     /*从栈中取出一个入度为0的顶点*/
		printf("%c ", G->adjlist[j].vertex);
		count++;
		p = G->adjlist[j].first;             /*工作指针p初始化*/
		while (p != NULL)               /*描顶点表，找出顶点j的所有出边*/
		{
			k = p->adjvex;
			G->adjlist[k].in--;
			if (G->adjlist[k].in == 0) S[++top] = k;    /*将入度为0的顶点入栈*/
			p = p->next;
		}
	}
	if (count < G->vertexNum)  printf("有回路");
}
