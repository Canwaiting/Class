#include<stdio.h>
void ShellSort(int r[], int n);

int main()
{
	int i;
	int r[8] = { 0, 12, 15, 9, 20, 6, 31, 24 };
	printf("����ǰԪ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	printf("\n");
	ShellSort(r, 7);
	printf("�����Ԫ��Ϊ��\n");
	for (i = 1; i < 8; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void ShellSort(int r[], int n)           /*r[0]�����ݴ浥Ԫ*/
{
	int d, i, j;
	for (d = n / 2; d >= 1; d = d / 2)         /*������Ϊd����ֱ�Ӳ�������*/
	{
		for (i = d + 1; i <= n; i++)
		{
			r[0] = r[i];                    /*�ݴ�������¼*/
			for (j = i - d; j > 0 && r[0] < r[j]; j = j - d)
				r[j + d] = r[j];               /*��¼����d��λ��*/
			r[j + d] = r[0];
		}
	}
}
