#include<stdio.h>
void HeapSort(int r[], int n);
void Sift(int r[], int k, int m);

int main()
{
	int i;
	int r[9] = { 0, 36, 30, 18, 40, 32, 45, 22, 50 };
	printf("排序前的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	HeapSort(r, 8);
	printf("排序后的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void HeapSort(int r[], int n)     /* r[0]为交换的临时单元*/
{
	int i;
	for (i = n / 2; i >= 1; i--)       /*初始建堆，从最后一个分支结点至根结点*/
		Sift(r, i, n) ;
	for (i = 1; i < n; i++)
	{
		r[0] = r[1]; r[1] = r[n-i+1]; r[n-i+1] = r[0];   /*交换r[1]和r[n-i+1]*/
	    Sift(r, 1, n - i);                          /*对r[1]~r[n-i]重建堆*/
}
}
void Sift(int r[], int k, int m)
{
	int i, j, temp;
	i = k; j = 2 * i;                  /*i是被筛选结点，j是结点i的左孩子*/
	while (j <= m)                 /*筛选还没有进行到叶子*/
	{
		if (j < m && r[j] < r[j + 1]) j++;  /*比较i的左右孩子，j指向较大者*/
		if (r[i] > r[j]) break;           /*根结点大于左右孩子中的较大者*/
		else {
			temp = r[i]; r[i] = r[j]; r[j] = temp;     /*将根结点与结点j交换*/
			i = j; j = 2 * i;              /*被筛结点位于原来结点j的位置*/
		}
	}
}
