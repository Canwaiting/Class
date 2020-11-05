#include<stdio.h>
#include<math.h>
#define N 100
int x[N] = { -1 };
void Queen(int n);
int Place(int k);
void PrintQueen(int n);

int main()
{
	int n;
	printf("请输入皇后的个数（n>=4）:");
	scanf("%d", &n);
	Queen(n);
	getchar();getchar();
	return 0;
}
void Queen(int n)
{
	int k = 0, num = 0;
	while (k >= 0)
	{
		x[k]++;
		while (x[k] < n&&Place(k) == 1)
			x[k]++;
		if (x[k] < n&&k == n - 1)
		{
			printf("第%d个解是：", ++num);
			PrintQueen(n);
		}
		else if (x[k] < n&&k < n - 1)
			k = k + 1;
		else
			x[k--] = -1;
	}
}

int Place(int k)
{
	for (int i = 0; i < k;i++)
	if (x[i] == x[k] || abs(i - k) == abs(x[i] - x[k]))
		return 1;
	return 0;
}
void PrintQueen(int n)
{
	for (int i = 0; i < n; i++)
		printf("%5d", x[i] + 1);
	printf("\n");
}