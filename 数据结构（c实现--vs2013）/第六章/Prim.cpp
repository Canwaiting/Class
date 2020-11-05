#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10                   /*假设图中最多顶点个数*/
typedef char DataType;                /*图中顶点的数据类型，假设为char型*/
typedef struct                        /*定义邻接矩阵存储结构*/
{
	DataType vertex[MaxSize];           /*存放顶点的一维数组*/
	int edge[MaxSize][MaxSize];          /*存放边的二维数组*/
	int vertexNum, edgeNum;             /*图的顶点数和边数*/
} MGraph;
int MinEdge(int lowcost[MaxSize], int vertexNum);
void Prim(MGraph *G, int v);
void CreatGraph(MGraph *G);

void Prim(MGraph *G, int v)               /*假设从顶点v出发*/
{
	int i, j, k;
	int adjvex[MaxSize], lowcost[MaxSize];
	for (i = 0; i < G->vertexNum; i++)         /*初始化辅助数组shortEdge*/
	{
		lowcost[i] = G->edge[v][i];
		adjvex[i] = v;
	}
	lowcost[v] = 0;                         /*将顶点v加入集合U*/
	for (k = 1; k < G->vertexNum; k++)         /*迭代n-1次*/
	{
		j = MinEdge(lowcost, G->vertexNum);    /*寻找最短边的邻接点j*/
		printf("(%d, %d)%d ", adjvex[j], j, lowcost[j]);
		lowcost[j] = 0;                        /*将顶点j加入集合U*/
		for (i = 0; i < G->vertexNum; i++)        /*调整数组shortEdge[n]*/
		if (G->edge[i][j] < lowcost[i])
		{
			lowcost[i] = G->edge[i][j];
			adjvex[i] = j;
		}
	}
}
int MinEdge(int lowcost[MaxSize], int vertexNum)
{
	int min = 100000000;
	int temp = 0, k;
	for (k = 0; k <vertexNum; k++)
	{
		if (lowcost[k] < min && lowcost[k] != 0)
		{
			min = lowcost[k];
			temp = k;
		}
	}
	return temp;
}
void CreatGraph(MGraph *G)
{
	int i, j;
	int a[6][6] = { { 0, 34, 46, 10000, 10000, 19 }, { 34, 0, 10000, 10000, 12, 10000 },
	{ 46, 1000, 0, 17, 10000, 25 }, { 10000, 10000, 17, 0, 38, 25 }, { 10000, 12, 10000, 38, 0, 26 },
	{ 19, 10000, 25, 25, 26, 0 } };
	printf("请输入树的顶点的个数:");
	scanf("%d", &G->vertexNum);
	printf("请输入树的顶点:");
	for (i = 0; i < G->vertexNum; i++)
		scanf("%c", &G->vertex[i]);

	printf("请输入树的边的条数:");
	fflush(stdin);
	scanf("%d", &G->edgeNum);

	//	printf("\n请输入权重:");
	for (i = 0; i < G->vertexNum; i++)
	for (j = 0; j < G->vertexNum; j++)
		G->edge[i][j] = a[i][j];

}
int main()
{
	MGraph  G;
	CreatGraph(&G);
	printf("\n最小生成树是:");
	Prim(&G, 0);
	getchar(); getchar();
	return 0;
}
