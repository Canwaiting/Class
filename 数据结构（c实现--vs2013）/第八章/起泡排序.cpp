#include<stdio.h>
void BubbleSort(int r[], int n);

int main()
{
	int i;
	int r[9] = {0, 50, 13, 55, 97, 27, 38, 49, 65 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	BubbleSort(r, 8);
	printf("\n������Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
void BubbleSort(int r[], int n)       /*r[0]������������ʱ��Ԫ*/
{
	int j, exchange, bound;
	exchange = n;                  /*��һ�����������������r[1]~r[n]*/
	while (exchange != 0)            /*����һ�������м�¼����ʱ*/
	{
		bound = exchange; exchange = 0;
		for (j = 0; j < bound; j++)       /*һ�����������������r[1]~r[bound]*/
		if (r[j] > r[j + 1]) {
			r[0] = r[j]; r[j] = r[j + 1]; r[j + 1] = r[0];
			exchange = j;          /*����ÿһ�μ�¼������λ��*/
		}
	}
}
