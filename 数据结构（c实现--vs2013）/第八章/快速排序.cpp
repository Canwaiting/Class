#include<stdio.h>
int Partition(int r[], int first, int end);
void QuickSort(int r[], int first, int end);

int main()
{
	int i;
	int r[7] = { 23, 13, 35, 6, 19, 50, 28 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 0; i < 7; i++)
		printf("%d ", r[i]);
	QuickSort(r,0,6);
	printf("\n������Ԫ��Ϊ��\n");
	for (i = 0; i < 7; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;

}
int Partition(int r[], int first, int end)
{
	int i = first, j = end, temp;             /*��ʼ��һ�λ��ֵ�����*/
	while (i < j)
	{
		while (i < j && r[i] <= r[j]) j--;     /*�Ҳ�ɨ��*/
		if (i < j) {
			temp = r[i]; r[i] = r[j]; r[j] = temp;   /*����С��¼������ǰ��*/
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;    /*���ɨ��*/
		if (i < j) {
			temp = r[i]; r[i] = r[j]; r[j] = temp;   /*���ϴ��¼����������*/
			j--;
		}
	}
	return i;                           /*iΪ��ֵ��¼������λ��*/
}
void QuickSort(int r[], int first, int end)
{
	if (first >= end) return;               /*���䳤��Ϊ1���ݹ����*/
	else {
		int pivot = Partition(r, first, end);     /*һ�λ���*/
		QuickSort(r, first, pivot - 1);          /*����������н��п�������*/
		QuickSort(r, pivot + 1, end);         /*���Ҳ������н��п�������*/
	}
}
