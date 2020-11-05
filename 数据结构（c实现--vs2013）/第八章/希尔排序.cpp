#include<stdio.h>
void ShellSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 12, 15, 9, 20, 6, 31, 24 };
	printf("排序前元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	ShellSort(r, 7);
	printf("排序后元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void ShellSort(int r[], int n)           /*r[0]用作暂存单元*/
{
	int d, i, j;
	for (d = n / 2; d >= 1; d = d / 2)         /*以增量为d进行直接插入排序*/
	{
		for (i = d + 1; i <= n; i++)
		{
			r[0] = r[i];                    /*暂存待插入记录*/
			for (j = i - d; j > 0 && r[0] < r[j]; j = j - d)
				r[j + d] = r[j];               /*记录后移d个位置*/
			r[j + d] = r[0];
		}
	}
}
