#include<stdio.h>
void MergePass(int r[], int n, int h);
void MergeSort1(int r[], int s, int t);
void Merge(int r[], int s, int m, int t);

int main()
{
	int i;
	int r[9] = { 0, 8, 3, 2, 6, 7, 1, 5, 4 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	MergeSort1(r,1,8);
	printf("������Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void MergeSort1(int r[], int s, int t)
{
	int i, m;
	if (s == t) return;             /*����������ֻ��1����¼���ݹ����*/
	m = (s + t) / 2;
	MergeSort1(r, s, m);          /*�鲢����ǰ���������*/
	MergeSort1(r, m + 1, t);        /*�鲢�������������*/
	Merge(r, s, m, t);            /*������������������кϲ�*/
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
