#include<stdio.h>
void SelectSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 49, 27, 65, 97, 76, 13, 38 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	SelectSort(r, 7);
	printf("������Ԫ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void SelectSort(int r[], int n)        /*r[0]������������ʱ��Ԫ*/
{
	int i, j, index;
	for (i = 1; i < n; i++)  	       /*����n-1�˼�ѡ������*/
	{
		index = i;
		for (j = i + 1; j <= n; j++)        /*����������ѡȡ��С��¼*/
		if (r[j] < r[index]) index = j;
		if (index != i) {
			r[0] = r[i]; r[i] = r[index]; r[index] = r[0];
		}
	}
}
