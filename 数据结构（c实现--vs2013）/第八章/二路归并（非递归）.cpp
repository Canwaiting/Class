#include<stdio.h>
void MergePass(int r[], int n, int h);
void MergeSort2(int r[], int n);
void Merge(int r[], int s, int m, int t);

int main()
{
	int i;
	int r[9] = { 0, 8, 3, 2, 6, 7, 1, 5, 4 };
	printf("排序前的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	MergeSort2(r, 8);
	printf("排序后的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
void MergePass(int r[], int n, int h)  /*待排序记录存储在r[1]~r[n]中*/
{
	int i = 1, k;
	while (i <= n - 2 * h + 1)     /*待归并记录至少有两个长度为h的子序列*/
	{
		Merge(r, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	if (i < n - h + 1) Merge(r, i, i + h - 1, n);    /*子序列有一个长度小于h*/
}
void MergeSort2(int r[], int n)            /*待排序记录存储在r[1]~r[n]中*/
{
	int h = 1;                            /*初始时子序列长度为1*/
	while (h < n)
	{
		MergePass(r, n, h);         /*待排序序列从数组r中传到r1中*/
		h = 2 * h;
	}
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
