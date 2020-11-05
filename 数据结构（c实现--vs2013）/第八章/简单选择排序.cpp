#include<stdio.h>
void SelectSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 49, 27, 65, 97, 76, 13, 38 };
	printf("排序前的元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	SelectSort(r, 7);
	printf("排序后的元素为：\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void SelectSort(int r[], int n)        /*r[0]用作交换的临时单元*/
{
	int i, j, index;
	for (i = 1; i < n; i++)  	       /*进行n-1趟简单选择排序*/
	{
		index = i;
		for (j = i + 1; j <= n; j++)        /*在无序区中选取最小记录*/
		if (r[j] < r[index]) index = j;
		if (index != i) {
			r[0] = r[i]; r[i] = r[index]; r[index] = r[0];
		}
	}
}
