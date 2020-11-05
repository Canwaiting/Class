#include<stdio.h>
void InsertSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 12, 15, 9, 20, 6, 31, 24 };
	printf("排序前元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	InsertSort(r, 7);
	printf("排序后元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void InsertSort(int r[], int n)          /*r[0]用作暂存单元和监视哨*/
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];                     /*暂存待插记录，设置哨兵*/
		for (j = i - 1; r[0] < r[j]; j--)       /*寻找插入位置*/
			r[j + 1] = r[j];
		r[j + 1] = r[0];
	}
}
