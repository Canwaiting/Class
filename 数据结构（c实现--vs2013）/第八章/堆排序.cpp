#include<stdio.h>
void HeapSort(int r[], int n);
void Sift(int r[], int k, int m);

int main()
{
	int i;
	int r[9] = { 0, 36, 30, 18, 40, 32, 45, 22, 50 };
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	printf("\n");
	HeapSort(r, 8);
	printf("������Ԫ��Ϊ��\n");
	for (i = 1; i < 9; i++)
		printf("%d ", r[i]);
	getchar();
	return 0;
}
void HeapSort(int r[], int n)     /* r[0]Ϊ��������ʱ��Ԫ*/
{
	int i;
	for (i = n / 2; i >= 1; i--)       /*��ʼ���ѣ������һ����֧����������*/
		Sift(r, i, n) ;
	for (i = 1; i < n; i++)
	{
		r[0] = r[1]; r[1] = r[n-i+1]; r[n-i+1] = r[0];   /*����r[1]��r[n-i+1]*/
	    Sift(r, 1, n - i);                          /*��r[1]~r[n-i]�ؽ���*/
}
}
void Sift(int r[], int k, int m)
{
	int i, j, temp;
	i = k; j = 2 * i;                  /*i�Ǳ�ɸѡ��㣬j�ǽ��i������*/
	while (j <= m)                 /*ɸѡ��û�н��е�Ҷ��*/
	{
		if (j < m && r[j] < r[j + 1]) j++;  /*�Ƚ�i�����Һ��ӣ�jָ��ϴ���*/
		if (r[i] > r[j]) break;           /*�����������Һ����еĽϴ���*/
		else {
			temp = r[i]; r[i] = r[j]; r[j] = temp;     /*�����������j����*/
			i = j; j = 2 * i;              /*��ɸ���λ��ԭ�����j��λ��*/
		}
	}
}
