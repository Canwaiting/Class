#include<stdio.h>
void BubbleSort(int r[], int n);

int main()
{
	int i;
	int r[9] = {0, 50, 13, 55, 97, 27, 38, 49, 65 };
	printf("排序前的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	BubbleSort(r, 8);
	printf("\n排序后的元素为：\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
void BubbleSort(int r[], int n)       /*r[0]用作交换的临时单元*/
{
	int j, exchange, bound;
	exchange = n;                  /*第一趟起泡排序的区间是r[1]~r[n]*/
	while (exchange != 0)            /*当上一趟排序有记录交换时*/
	{
		bound = exchange; exchange = 0;
		for (j = 0; j < bound; j++)       /*一趟起泡排序的区间是r[1]~r[bound]*/
		if (r[j] > r[j + 1]) {
			r[0] = r[j]; r[j] = r[j + 1]; r[j + 1] = r[0];
			exchange = j;          /*记载每一次记录交换的位置*/
		}
	}
}
