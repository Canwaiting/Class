#include<stdio.h>
#include<stdlib.h>
int EulerCircuit(int mat[4][4], int n);


int main()
{
	int mat[4][4] = { { 0, 1, 2, 2 }, { 1, 0, 1, 1 }, { 2, 1, 0, 0 }, { 2, 1, 0, 0 } };
	int num = EulerCircuit(mat, 4);
	if (num >= 2)
		printf("有%d个地方通奇数桥，不存在欧拉回路\n", num);
	else
		printf("存在欧拉回路\n");
	getchar();
	return 0;
}

int EulerCircuit(int mat[4][4], int n)
{
	int i, j, degree, count = 0;
	for (i = 0; i < n; i++)
	{
		degree = 0;
		for (j = 0; j < n; j++)
			degree = degree + mat[i][j];
		if (degree % 2 != 0)
			count++;
	}
	return count;
}