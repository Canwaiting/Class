#include<stdio.h>
int SeqSearch(int r[], int n, int k);

int main( )
{
	int r[6] = { 0,5, 4, 3, 2, 1 },k,i;
	printf("Ԫ������Ϊ��\n");
	for (i = 1; i <= 5; i++)
	{
		printf("%d\t", r[i]);
	}
	printf("\n������Ҫ���ҵ�Ԫ�أ�");
	scanf("%d", &k);
	printf("Ҫ���ҵ�Ԫ������λ��Ϊ��%d\n", SeqSearch(r, 5, k));
	getchar(); getchar();
	return 0;
}

int SeqSearch(int r[], int n, int k)      /*���鼯�ϴ洢������r[1]~r[n]*/
{
	int i = n;                        /*������߶˿�ʼ�Ƚ�*/
	r[0] = k;                        /*�����ڱ�*/
	while (r[i] != k)                  /*�����ж��±�i�Ƿ�Խ��*/
		i--;
	return i;
}