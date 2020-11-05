#include<stdio.h>
void MergePass(int r[], int n, int h);
void MergeSort1(int r[], int s, int t);
void Merge(int r[], int s, int m, int t);

int main()
{
	int i;
	int r[9] = { 0, 8, 3, 2, 6, 7, 1, 5, 4 };
	printf("排序前的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	MergeSort1(r,1,8);
	printf("排序后的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void MergeSort1(int r[], int s, int t)
{
	int i, m;
	if (s == t) return;             /*待排序序列只有1个记录，递归结束*/
	m = (s + t) / 2;
	MergeSort1(r, s, m);          /*归并排序前半个子序列*/
	MergeSort1(r, m + 1, t);        /*归并排序后半个子序列*/
	Merge(r, s, m, t);            /*将两个已排序的子序列合并*/
}
void Merge(int r[], int s, int m, int t)
{
	int r1[9];                       /*数组r1作为合并的辅助空间*/
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j]) r1[k++] = r[i++];   /*取r[i]和r[j]中较小者放入r1[k]*/
		else r1[k++] = r[j++];
	}
	while (i <= m)                   /*对第一个子序列进行收尾处理*/
		r1[k++] = r[i++];
	while (j <= t)                    /*对第二个子序列进行收尾处理*/
		r1[k++] = r[j++];
	for (i = s; i <= t; i++)              /*将合并结果传回数组r*/
		r[i] = r1[i];
}
