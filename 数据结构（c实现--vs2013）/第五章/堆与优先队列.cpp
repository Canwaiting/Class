#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100             /*假设优先队列最多99个元素*/
typedef int DataType;             /*定义优先队列的数据类型，假设为int型*/
typedef struct
{
	DataType data[MaxSize];
	int rear;                      /*优先队列的队尾位置*/
} PriQueue;
/*void InitQueue(PriQueue *Q)
{
Q->rear == MaxSize - 1;
Q->rear == 0;
}*/
int  EnQueue(PriQueue *Q, DataType x)
{
	int i, temp;
	if (Q->rear == MaxSize - 1) { printf("上溢"); return 0; }
	i = Q->rear++;                  /*i记载新插入元素在数组中的下标*/
	Q->data[i] = x;
	while (i / 2 > 0 && Q->data[i / 2] < x)
	{
		temp = Q->data[i]; Q->data[i] = Q->data[i / 2]; Q->data[i / 2] = temp;
		i = i / 2;                      /*新插入元素的位置*/
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
	if (Q->rear == 0) { printf("下溢"); return 0; }
	*ptr = Q->data[1];
	Q->data[1] = Q->data[Q->rear--];
	i = 1; j = 2 * i;                  /*i是被调整的结点，j是i的左孩子*/
	while (j <= Q->rear)             /*调整要进行到叶子*/
	{
		if (j < Q->rear && Q->data[j] < Q->data[j + 1]) j++;
		if (Q->data[i] > Q->data[j]) break;    /*根结点大于左右孩子中的较大者*/
		else {
			temp = Q->data[i]; Q->data[i] = Q->data[j]; Q->data[j] = temp;
			i = j; j = 2 * i;              /*被调整结点位于原来结点j的位置*/
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
	printf("输出堆的序列:");
	for (i = 1; i < 9; i++)
		printf("%d\t", data[i]);
	printf("\n插入数据后新堆的序列是:");
	EnQueue(&Q, 45);
	getchar();
	//	DeQueue(&Q,)
	//	printf("最大队的序列",EnQueue(&Q));
	return 0;
}