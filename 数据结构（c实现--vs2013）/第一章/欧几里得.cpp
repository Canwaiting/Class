#include<stdio.h>
int ComFactor(int m, int n);

int main()
{
	printf("���Լ���ǣ�%d\n", ComFactor(35, 25));
	getchar();
	return 0;
}

int ComFactor(int m, int n)
{
	int r = m%n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m%n;
	}
	return n;
}