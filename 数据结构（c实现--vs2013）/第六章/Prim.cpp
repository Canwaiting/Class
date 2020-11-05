#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10                   /*����ͼ����ඥ�����*/
typedef char DataType;                /*ͼ�ж�����������ͣ�����Ϊchar��*/
typedef struct                        /*�����ڽӾ���洢�ṹ*/
{
	DataType vertex[MaxSize];           /*��Ŷ����һά����*/
	int edge[MaxSize][MaxSize];          /*��űߵĶ�ά����*/
	int vertexNum, edgeNum;             /*ͼ�Ķ������ͱ���*/
} MGraph;
int MinEdge(int lowcost[MaxSize], int vertexNum);
void Prim(MGraph *G, int v);
void CreatGraph(MGraph *G);

void Prim(MGraph *G, int v)               /*����Ӷ���v����*/
{
	int i, j, k;
	int adjvex[MaxSize], lowcost[MaxSize];
	for (i = 0; i < G->vertexNum; i++)         /*��ʼ����������shortEdge*/
	{
		lowcost[i] = G->edge[v][i];
		adjvex[i] = v;
	}
	lowcost[v] = 0;                         /*������v���뼯��U*/
	for (k = 1; k < G->vertexNum; k++)         /*����n-1��*/
	{
		j = MinEdge(lowcost, G->vertexNum);    /*Ѱ����̱ߵ��ڽӵ�j*/
		printf("(%d, %d)%d ", adjvex[j], j, lowcost[j]);
		lowcost[j] = 0;                        /*������j���뼯��U*/
		for (i = 0; i < G->vertexNum; i++)        /*��������shortEdge[n]*/
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
	printf("���������Ķ���ĸ���:");
	scanf("%d", &G->vertexNum);
	printf("���������Ķ���:");
	for (i = 0; i < G->vertexNum; i++)
		scanf("%c", &G->vertex[i]);

	printf("���������ıߵ�����:");
	fflush(stdin);
	scanf("%d", &G->edgeNum);

	//	printf("\n������Ȩ��:");
	for (i = 0; i < G->vertexNum; i++)
	for (j = 0; j < G->vertexNum; j++)
		G->edge[i][j] = a[i][j];

}
int main()
{
	MGraph  G;
	CreatGraph(&G);
	printf("\n��С��������:");
	Prim(&G, 0);
	getchar(); getchar();
	return 0;
}
