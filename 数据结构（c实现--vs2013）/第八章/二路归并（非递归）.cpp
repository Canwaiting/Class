#include<stdio.h>
void MergePass(int r[], int n, int h);
void MergeSort2(int r[], int n);
void Merge(int r[], int s, int m, int t);

int main()
{
	int i;
	int r[9] = { 0, 8, 3, 2, 6, 7, 1, 5, 4 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	MergeSort2(r, 8);
	printf("������Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
void MergePass(int r[], int n, int h)  /*�������¼�洢��r[1]~r[n]��*/
{
	int i = 1, k;
	while (i <= n - 2 * h + 1)     /*���鲢��¼��������������Ϊh��������*/
	{
		Merge(r, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	if (i < n - h + 1) Merge(r, i, i + h - 1, n);    /*��������һ������С��h*/
}
void MergeSort2(int r[], int n)            /*�������¼�洢��r[1]~r[n]��*/
{
	int h = 1;                            /*��ʼʱ�����г���Ϊ1*/
	while (h < n)
	{
		MergePass(r, n, h);         /*���������д�����r�д���r1��*/
		h = 2 * h;
	}
}
void Merge(int r[], int s, int m, int t)
{
	int r1[9];                       /*����r1��Ϊ�ϲ��ĸ����ռ�*/
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j]) r1[k++] = r[i++];   /*ȡr[i]��r[j]�н�С�߷���r1[k]*/
		else r1[k++] = r[j++];
	}
	while (i <= m)                   /*�Ե�һ�������н�����β����*/
		r1[k++] = r[i++];
	while (j <= t)                    /*�Եڶ��������н�����β����*/
		r1[k++] = r[j++];
	for (i = s; i <= t; i++)              /*���ϲ������������r*/
		r[i] = r1[i];
}
