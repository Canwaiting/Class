#include <stdio.h>                               
#define N 5                                     /*假设图中有5个顶点*/
const int MaxValue = 100;                         /* MaxValue表示∞*/
char vertex[N] = { 'A', 'B', 'C', 'D', 'E' };                  /*存放顶点的一维数组*/
int edge[N][N] = { { 0, 13, MaxValue, 4, MaxValue },      /*存放边的二维数组*/
{ 13, 0, 15, MaxValue, 5 },
{ MaxValue, MaxValue, 0, 12, MaxValue },
{ 4, MaxValue, 12, 0, MaxValue },
{ MaxValue, MaxValue, 6, 3, 0 } };
int dist[N][N] = { 0 };                  /*存储任意两个顶点的最短路径长度*/
void Floyd();                               /*函数声明，Floyd算法*/
int Center();                                /*函数声明，求中心点*/

int main()
{
	int minPoint;                           /*存储中心点的下标*/
	Floyd();           /*调用Floyd算法求任意两个顶点之间的最短路径*/
	minPoint = Center();                    /*调用函数Center求中心点*/
	printf("应该设在%c点\n", vertex[minPoint]);
	getchar(); getchar();
	return 0;
}
void Floyd()               /* Floyd算法求任意两个顶点之间的最短路径*/
{
	int i, j, k;
	for (i = 0; i < N; i++)                  /*初始化矩阵dist*/
	for (j = 0; j < N; j++)
	{
		dist[i][j] = edge[i][j];
	}
	for (k = 0; k < N; k++)                /*进行N次迭代*/
	for (i = 0; i < N; i++)               /*顶点i和j之间是否经过顶点k*/
	for (j = 0; j < N; j++)
	if (dist[i][k] + dist[k][j] < dist[i][j])
		dist[i][j] = dist[i][k] + dist[k][j];
}
int Center()                          /*求图的中心点，返回中心点的下标*/
{
	int wayCost, minCost = MaxValue;
	int i, k, index;
	for (k = 0; k < N; k++)                     /*依次求每个顶点的往返代价*/
	{
		wayCost = 0;                         /*往返代价初始化为0*/
		for (i = 0; i < N; i++)             /*顶点i到其他顶点的路径长度之和*/
			wayCost = wayCost + dist[i][k];
		for (i = 0; i < N; i++)             /*其他顶点到顶点i的路径长度之和*/
			wayCost = wayCost + dist[k][i];
		if (wayCost < minCost)
		{
			minCost = wayCost;
			index = k;                        /*顶点k为当前的中心点*/
		}
	}
	return index;                              /*返回中心点的下标*/
}
