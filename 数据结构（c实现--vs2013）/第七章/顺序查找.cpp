#include<stdio.h>
int SeqSearch(int r[], int n, int k);

int main( )
{
	int r[6] = { 0,5, 4, 3, 2, 1 },k,i;
	printf("元素序列为：\n");
	for (i = 1; i <= 5; i++)
	{
		printf("%d\t", r[i]);
	}
	printf("\n请输入要查找的元素：");
	scanf("%d", &k);
	printf("要查找的元素所在位置为：%d\n", SeqSearch(r, 5, k));
	getchar(); getchar();
	return 0;
}

int SeqSearch(int r[], int n, int k)      /*待查集合存储在数组r[1]~r[n]*/
{
	int i = n;                        /*从数组高端开始比较*/
	r[0] = k;                        /*设置哨兵*/
	while (r[i] != k)                  /*不用判断下标i是否越界*/
		i--;
	return i;
}