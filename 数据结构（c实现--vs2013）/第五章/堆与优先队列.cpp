#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100             /*�������ȶ������99��Ԫ��*/
typedef int DataType;             /*�������ȶ��е��������ͣ�����Ϊint��*/
typedef struct
{
	DataType data[MaxSize];
	int rear;                      /*���ȶ��еĶ�βλ��*/
} PriQueue;
/*void InitQueue(PriQueue *Q)
{
Q->rear == MaxSize - 1;
Q->rear == 0;
}*/
int  EnQueue(PriQueue *Q, DataType x)
{
	int i, temp;
	if (Q->rear == MaxSize - 1) { printf("����"); return 0; }
	i = Q->rear++;                  /*i�����²���Ԫ���������е��±�*/
	Q->data[i] = x;
	while (i / 2 > 0 && Q->data[i / 2] < x)
	{
		temp = Q->data[i]; Q->data[i] = Q->data[i / 2]; Q->data[i / 2] = temp;
		i = i / 2;                      /*�²���Ԫ�ص�λ��*/
	}
	for (i = 1; i < 10; i++)
	{
		printf("%d\t", Q->data[i]);
	}
	return 1;
}
DataType DeQueue(PriQueue *Q, DataType *ptr)
{
	int i, j, x, temp;
	if (Q->rear == 0) { printf("����"); return 0; }
	*ptr = Q->data[1];
	Q->data[1] = Q->data[Q->rear--];
	i = 1; j = 2 * i;                  /*i�Ǳ������Ľ�㣬j��i������*/
	while (j <= Q->rear)             /*����Ҫ���е�Ҷ��*/
	{
		if (j < Q->rear && Q->data[j] < Q->data[j + 1]) j++;
		if (Q->data[i] > Q->data[j]) break;    /*�����������Һ����еĽϴ���*/
		else {
			temp = Q->data[i]; Q->data[i] = Q->data[j]; Q->data[j] = temp;
			i = j; j = 2 * i;              /*���������λ��ԭ�����j��λ��*/
		}
	}
	return 1;
}
int main()
{
	int data[9] = { 0,50, 40, 45, 36, 32, 18, 22, 30 };
	int i;
	DataType x;
	PriQueue Q;
	Q.rear = 1;
	for (i = 1; i < 9; i++)
	{
		
		Q.data[i] = data[i];
		Q.rear++;
	}
	printf("����ѵ�����:");
	for (i = 1; i < 9; i++)
		printf("%d\t", data[i]);
	printf("\n�������ݺ��¶ѵ�������:");
	EnQueue(&Q, 45);
	getchar();
	//	DeQueue(&Q,)
	//	printf("���ӵ�����",EnQueue(&Q));
	return 0;
}