#include <stdio.h>                               
#define N 5                                     /*����ͼ����5������*/
const int MaxValue = 100;                         /* MaxValue��ʾ��*/
char vertex[N] = { 'A', 'B', 'C', 'D', 'E' };                  /*��Ŷ����һά����*/
int edge[N][N] = { { 0, 13, MaxValue, 4, MaxValue },      /*��űߵĶ�ά����*/
{ 13, 0, 15, MaxValue, 5 },
{ MaxValue, MaxValue, 0, 12, MaxValue },
{ 4, MaxValue, 12, 0, MaxValue },
{ MaxValue, MaxValue, 6, 3, 0 } };
int dist[N][N] = { 0 };                  /*�洢����������������·������*/
void Floyd();                               /*����������Floyd�㷨*/
int Center();                                /*���������������ĵ�*/

int main()
{
	int minPoint;                           /*�洢���ĵ���±�*/
	Floyd();           /*����Floyd�㷨��������������֮������·��*/
	minPoint = Center();                    /*���ú���Center�����ĵ�*/
	printf("Ӧ������%c��\n", vertex[minPoint]);
	getchar(); getchar();
	return 0;
}
void Floyd()               /* Floyd�㷨��������������֮������·��*/
{
	int i, j, k;
	for (i = 0; i < N; i++)                  /*��ʼ������dist*/
	for (j = 0; j < N; j++)
	{
		dist[i][j] = edge[i][j];
	}
	for (k = 0; k < N; k++)                /*����N�ε���*/
	for (i = 0; i < N; i++)               /*����i��j֮���Ƿ񾭹�����k*/
	for (j = 0; j < N; j++)
	if (dist[i][k] + dist[k][j] < dist[i][j])
		dist[i][j] = dist[i][k] + dist[k][j];
}
int Center()                          /*��ͼ�����ĵ㣬�������ĵ���±�*/
{
	int wayCost, minCost = MaxValue;
	int i, k, index;
	for (k = 0; k < N; k++)                     /*������ÿ���������������*/
	{
		wayCost = 0;                         /*�������۳�ʼ��Ϊ0*/
		for (i = 0; i < N; i++)             /*����i�����������·������֮��*/
			wayCost = wayCost + dist[i][k];
		for (i = 0; i < N; i++)             /*�������㵽����i��·������֮��*/
			wayCost = wayCost + dist[k][i];
		if (wayCost < minCost)
		{
			minCost = wayCost;
			index = k;                        /*����kΪ��ǰ�����ĵ�*/
		}
	}
	return index;                              /*�������ĵ���±�*/
}
