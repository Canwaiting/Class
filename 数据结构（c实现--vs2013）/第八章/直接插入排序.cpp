#include<stdio.h>
void InsertSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 12, 15, 9, 20, 6, 31, 24 };
	printf("����ǰԪ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	InsertSort(r, 7);
	printf("�����Ԫ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void InsertSort(int r[], int n)          /*r[0]�����ݴ浥Ԫ�ͼ�����*/
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];                     /*�ݴ�����¼�������ڱ�*/
		for (j = i - 1; r[0] < r[j]; j--)       /*Ѱ�Ҳ���λ��*/
			r[j + 1] = r[j];
		r[j + 1] = r[0];
	}
}
