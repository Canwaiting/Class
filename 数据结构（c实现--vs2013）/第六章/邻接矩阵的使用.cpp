#include<stdio.h>
//#include<stdlib.h>
#define MaxSize 10
typedef char DataType;
int visited[MaxSize] = { 0 };
typedef struct
{
	DataType vertex[MaxSize];
	int edge[MaxSize][MaxSize];
	int vertexNum, edgeNum;
}MGraph;
void CreatGraph(MGraph *G, DataType a[], int n, int e)
{
	int i, j, k;
	G->vertexNum = n;
	G->edgeNum = e;
	for (i = 0; i < G->vertexNum; i++)
		G->vertex[i] = a[i];
	for (i = 0; i < G->vertexNum;i++)
	for (j = 0; j < G->vertexNum; j++)
		G->edge[i][j] = 0;
	for (k = 0; k < G->edgeNum; k++)
	{
		scanf("%d%d", &i, &j);
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
}
void DFTraverse(MGraph *G, int v)
{
	printf("%c", G->vertex[v]);
	visited[v] = 1;
	for (int j = 0; j < G->vertexNum;j++)
	if (G->edge[v][j] == 1 && visited[j] == 0)
		DFTraverse(G, j);
}
void BFTraverse(MGraph *G, int v)
{
	int i, j, Q[MaxSize];
	int rear;
	int front =  rear = -1;
	printf("%c", G->vertex[v]);
	visited[v] = 1;
	Q[++rear] = v;  
	while (front != rear)
	{
		i = Q[++front];
		for (j = 0; j < G->vertexNum;j++)
		if (G->edge[i][j] == 1 && visited[j] == 0)
		{
			printf("%c", G->vertex[j]);
			visited[j] = 1; 
			Q[++rear] = j;
		}
	}
}
int main()
{
	int i;
	char ch[] = { 'A', 'B', 'C', 'D', 'E' };
	MGraph MG;
	CreatGraph(&MG, ch, 5, 6);
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	printf("深度优先遍历序列是：");
	DFTraverse(&MG, 0);
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	printf("广度优先遍历序列是：");
	BFTraverse(&MG, 0);
	getchar(); getchar();
	return 0;
}
