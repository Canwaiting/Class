#include<stdio.h>
int Partition(int r[], int first, int end);
void QuickSort(int r[], int first, int end);

int main()
{
	int i;
	int r[7] = { 23, 13, 35, 6, 19, 50, 28 };
	printf("排序前的元素为：\n");
	for (i = 0; i < 7; i++)
		printf("%d ", r[i]);
	QuickSort(r,0,6);
	printf("\n排序后的元素为：\n");
	for (i = 0; i < 7; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
int Partition(int r[], int first, int end)
{
	int i = first, j = end, temp;             /*初始化一次划分的区间*/
	while (i < j)
	{
		while (i < j && r[i] <= r[j]) j--;     /*右侧扫描*/
		if (i < j) {
			temp = r[i]; r[i] = r[j]; r[j] = temp;   /*将较小记录交换到前面*/
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;    /*左侧扫描*/
		if (i < j) {
			temp = r[i]; r[i] = r[j]; r[j] = temp;   /*将较大记录交换到后面*/
			j--;
		}
	}
	return i;                           /*i为轴值记录的最终位置*/
}
void QuickSort(int r[], int first, int end)
{
	if (first >= end) return;               /*区间长度为1，递归结束*/
	else {
		int pivot = Partition(r, first, end);     /*一次划分*/
		QuickSort(r, first, pivot - 1);          /*对左侧子序列进行快速排序*/
		QuickSort(r, pivot + 1, end);         /*对右侧子序列进行快速排序*/
	}
}
