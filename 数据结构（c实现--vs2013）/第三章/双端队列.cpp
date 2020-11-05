#include<stdio.h>
/*��˫�˶��еĴ洢�ṹ����͸�����������ŵ�����*/
#define DoubleQueueSize 100
typedef int DataType;
typedef struct
{
	DataType data[DoubleQueueSize];
	int front, rear;
}DoubleQueue;

void InitQueue(DoubleQueue *Q)
{
	Q->front = Q->rear = - 1;
}
int EnQueueHead(DoubleQueue *Q, DataType x)   /*����x����ͷ�������������ʧ�ܣ�����0�����򷵻�1*/
{
	if ((Q->rear + 1) == Q->front)
	{
		printf("������󣬲���ʧ��\n");
		return 0;
	}
	Q->data[Q->front] = x;                                                 /*��xֵ����front��ָ��λ��*/
	Q->front = Q->front - 1 ;                                     /*����front��1*/
	
	return 1;
}
int EnQueueTail(DoubleQueue *Q, DataType x)
{
	if ((Q->rear+1)==Q->front)
	{
		printf("������󣬲���ʧ��\n");
		return 0;
	}
	Q->rear = (Q->rear + 1)%DoubleQueueSize;
	Q->data[Q->rear] = x;
	
	return 1;

}
int DeQueueHead(DoubleQueue *Q, DataType *ptr)//&x)       /*ɾȥ��ͷԪ�أ���ֵͨ��x���ء����ӿ���ɾ��ʧ�ܣ�����0�����򷵻�1*/
{
	if (Q->front == Q->rear)
		return 0;
	Q->front = (Q->front + 1)%DoubleQueueSize;                   /*frontֵ��1*/
	*ptr = Q->data[Q->front];                   /*��front��ָλ�õ�ֵ����x*/
	return 1;
}
int DeQueueTail(DoubleQueue *Q, DataType *ptr)
{
	if (Q->front == Q->rear)
		return 0;
	*ptr = Q->data[Q->rear];
	Q->rear = Q->rear - 1;
	return 1;
}
int GetHead(DoubleQueue *Q, DataType *ptr)
{
	if (Q->front == Q->rear)
		return 0;
	*ptr = Q->data[(Q->front+1)%DoubleQueueSize];
	return 1;
}
int GetTail(DoubleQueue *Q, DataType *ptr)
{
	if (Q->front == Q->rear)
		return 0;
	*ptr = Q->data[Q->rear];
	return 1;
}
int Empty(DoubleQueue *Q)
{
	if (Q->rear == Q->front)
		return 1;
	else
		return 0;
}


int main()
{
	DataType x;
	DoubleQueue Q;                     /*����ṹ�����QΪѭ����������*/
	InitQueue(&Q);                   /*��ʼ��ѭ������Q*/
	printf("��5ִ�ж�ͷ���������");       /*�����ͷԪ��5*/
	EnQueueHead(&Q, 5);
	printf("\n");
	printf("��6ִ�ж�ͷ���������");      /*�����ͷԪ��6*/
	EnQueueHead(&Q, 6);
	printf("\n");
	printf("��8ִ�ж�β���������");     /*�����βԪ��8*/
	EnQueueTail(&Q, 8);
	printf("\n");
	printf("��9ִ�ж�β���������");      /*�����βԪ��9*/
	EnQueueTail(&Q,9);
	printf("\n");
	if (GetHead(&Q, &x) == 1)
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);              /*�����ǰ��ͷԪ��6*/
	if (DeQueueHead(&Q, &x) == 1)
		printf("ִ��һ�ζ�ͷ���Ӳ���������Ԫ���ǣ�%d\n ", x);    /*�������Ԫ��6*/
	if (GetHead(&Q, &x) == 1)                            /*�����ǰ��ͷԪ��5*/
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);
	if (GetTail(&Q, &x) == 1)
		printf("��ǰ��βԪ��Ϊ��%d\n", x);              /*�����ǰ��βԪ��9*/
	if (DeQueueTail(&Q, &x) == 1)
		printf("ִ��һ�ζ�β���Ӳ���������Ԫ���ǣ�%d\n ", x);    /*�������βԪ��9*/
	if (GetTail(&Q, &x) == 1)
		printf("��ǰ��βԪ��Ϊ��%d\n", x);             /*�����ǰ��βԪ��8*/
	printf("�������ڶ�ͷ�����Ԫ�أ�");
	scanf("%d", &x);      
	EnQueueHead(&Q, x);                           /*�����ͷԪ��*/
	printf("�������ڶ�β�����Ԫ�أ�");
	scanf("%d", &x);
	EnQueueTail(&Q, x);                           /*�����ͷԪ��*/
	if (Empty(&Q) == 1)
		printf("����Ϊ��\n");
	else
		printf("���зǿ�\n");               /*������3��Ԫ�أ�������зǿ�*/
	getchar(); getchar();
	return 0;
}
