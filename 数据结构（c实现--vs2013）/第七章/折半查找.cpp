#include<stdio.h>
int BinSearch1(int r[], int n, int k);
int BinSearch2(int r[], int low, int high, int k);

int main()
{
	int r[10] = {0, 7, 14, 18, 21, 23, 29, 31, 35, 38 };
	int k,i;
	printf("元素序列为：\n");
	for (i = 1; i < 10; i++)
		printf("%5d", r[i]);
	printf("\n请输入要查找的元素值：");
	scanf("%d", &k);
	if (BinSearch1(r, 9, k) == 0)
		printf("查找失败！\n");
	else
		printf("非递归方法查找该元素所在位置为：%d\n", BinSearch1(r, 9, k));
	if (BinSearch2(r, 1, 9, k) == 0)
		printf("查找失败！\n");
	else
		printf("递归方法查找该元素所在位置为：%d\n", BinSearch2(r,1, 9, k));
	getchar(); getchar();
	return 0;
}

int BinSearch1(int r[], int n, int k)      /*查找集合存储在r[1]~r[n]*/
{
	int mid, low = 1, high = n;           /*初始查找区间是[1, n]*/
	while (low <= high)                /*当区间存在时*/
	{
		mid = (low + high) / 2;
		if (k < r[mid])	high = mid - 1;
		else	if (k > r[mid]) low = mid + 1;
		else return mid;             /*查找成功，返回元素序号*/
	}
	return 0;                         /*查找失败，返回0*/
}

int BinSearch2(int r[], int low, int high, int k)
{
	int mid;
	if (low > high) return 0;                        /*递归的边界条件*/
	else {
		mid = (low + high) / 2;
		if (k < r[mid]) return BinSearch2(r, low, mid - 1, k);
		else if (k > r[mid]) return BinSearch2(r, mid + 1, high, k);
		else return mid;                         /*查找成功，返回序号*/
	}
}
