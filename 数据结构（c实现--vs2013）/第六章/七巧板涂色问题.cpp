#include<stdio.h>
#include<stdlib.h>
#define N 7

int main()
{
	int i, j;
	char board[N] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int edge[N][N] = { { 0, 1, 0, 0, 1, 1, 0 }, { 1, 0, 1, 1, 0, 0, 0 }, { 0, 1, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 1, 0, 1 }, { 1, 0, 0, 1, 0, 1, 1 }, { 1, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 1, 1, 0, 0 } };
	int color[N] = { 0 };
	for (i = 0; i < N;)
	{
		color[i]++;
		if (color[i]>4)
		{
			color[i] = 0;
			i = i - 1;
			continue;
		}
		for (j = 0; j < i; j++)
		{
			if ((edge[i][j] == 1) && (color[i] == color[j]))
				break;
		}
		if (j ==i)
			i = i + 1;
	}
	for (i = 0; i < N; i++)
		printf("%cÍ¿ÑÕÉ«%d\n", board[i], color[i]);
	system("pause");
	return 0;
}