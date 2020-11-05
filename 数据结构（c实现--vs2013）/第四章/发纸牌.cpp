#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<malloc.h>
char *str1[4] = { "梅花", "黑桃", "红桃", "方块" };
char *str2[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
char *card[13];
void SendCards(int n);
void PrintCards(int n);

int main()
{
	int n;
	printf("请输入发牌张数：");
	scanf("%d", &n);
	SendCards(n);
	PrintCards(n);
	getchar(); getchar();
	return 0;
}
void SendCards(int n)
{
	int i, j, k, sign[4][13] = { 0 };
	srand(time(NULL));
	for (k = 0; k < n;)
	{
		i = rand() % 4;
		j = rand() % 13;
		if (sign[i][j] == 1)
			continue;
		else
		{
			card[k] = (char*)malloc(6);
			strcpy(card[k], str1[i]);
			strcat(card[k], str2[j]);
			sign[i][j] = 1;
			k++;
		}
	}
}
void PrintCards(int n)
{
	for (int k = 0; k < n; k++)
		printf("%-10s", card[k]);
	printf("\n");
}