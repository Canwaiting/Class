#include<stdio.h>
int BinSearch1(int r[], int n, int k);
int BinSearch2(int r[], int low, int high, int k);

int main()
{
	int r[10] = {0, 7, 14, 18, 21, 23, 29, 31, 35, 38 };
	int k,i;
	printf("Ԫ������Ϊ��\n");
	for (i = 1; i < 10; i++)
		printf("%5d", r[i]);
	printf("\n������Ҫ���ҵ�Ԫ��ֵ��");
	scanf("%d", &k);
	if (BinSearch1(r, 9, k) == 0)
		printf("����ʧ�ܣ�\n");
	else
		printf("�ǵݹ鷽�����Ҹ�Ԫ������λ��Ϊ��%d\n", BinSearch1(r, 9, k));
	if (BinSearch2(r, 1, 9, k) == 0)
		printf("����ʧ�ܣ�\n");
	else
		printf("�ݹ鷽�����Ҹ�Ԫ������λ��Ϊ��%d\n", BinSearch2(r,1, 9, k));
	getchar(); getchar();
	return 0;
}

int BinSearch1(int r[], int n, int k)      /*���Ҽ��ϴ洢��r[1]~r[n]*/
{
	int mid, low = 1, high = n;           /*��ʼ����������[1, n]*/
	while (low <= high)                /*���������ʱ*/
	{
		mid = (low + high) / 2;
		if (k < r[mid])	high = mid - 1;
		else	if (k > r[mid]) low = mid + 1;
		else return mid;             /*���ҳɹ�������Ԫ�����*/
	}
	return 0;                         /*����ʧ�ܣ�����0*/
}

int BinSearch2(int r[], int low, int high, int k)
{
	int mid;
	if (low > high) return 0;                        /*�ݹ�ı߽�����*/
	else {
		mid = (low + high) / 2;
		if (k < r[mid]) return BinSearch2(r, low, mid - 1, k);
		else if (k > r[mid]) return BinSearch2(r, mid + 1, high, k);
		else return mid;                         /*���ҳɹ����������*/
	}
}
