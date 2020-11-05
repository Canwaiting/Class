#include <stdio.h>
/*��ѭ�����еĴ洢�ṹ����͸�����������ŵ�����*/
#define QueueSize 100            /*�����������󳤶�*/
typedef int DataType;             /*�������Ԫ�ص��������ͣ�����Ϊint��*/
typedef struct
{
	DataType data[QueueSize];      /*��Ŷ���Ԫ�ص�����*/
	int front, rear;                 /*�±꣬��ͷԪ�غͶ�βԪ�ص�λ��*/
} CirQueue;
void InitQueue(CirQueue *Q)
{
	Q->front = Q->rear = QueueSize - 1;
}
int EnQueue(CirQueue *Q, DataType x)
{
	if ((Q->rear + 1) % QueueSize == Q->front) {
		printf("������󣬲���ʧ��\n"); return 0;
	}
	Q->rear = (Q->rear + 1) % QueueSize;      /*��βλ����ѭ�������¼�1*/
	Q->data[Q->rear] = x;                   /*�ڶ�β������Ԫ��*/
	return 1;
}
int GetHead(CirQueue *Q, DataType *ptr)
{
	int i;
	if (Q->rear == Q->front) { printf("�������ȡ��ͷʧ��\n"); return 0; }
	i = (Q->front + 1) % QueueSize;                /*ע�ⲻ�ı��ͷλ��*/
	*ptr = Q->data[i]; return 1;
}
int DeQueue(CirQueue *Q, DataType *ptr)
{
	if (Q->rear == Q->front) { printf("�������ɾ��ʧ��\n"); return 0; }
	Q->front = (Q->front + 1) % QueueSize;    /*��ͷλ����ѭ�������¼�1*/
	*ptr = Q->data[Q->front];                /*��ȡ����ǰ�Ķ�ͷԪ��*/
	return 1;
}
int Empty(CirQueue *Q)
{
	if (Q->rear == Q->front) return 1;              /*����Ϊ�շ���1*/
	else return 0;
}


int main()
{
	DataType x;
	CirQueue Q;                     /*����ṹ�����QΪѭ����������*/
	InitQueue(&Q);                   /*��ʼ��ѭ������Q*/
	printf("��5��8ִ����Ӳ�����");
	EnQueue(&Q, 5);
	EnQueue(&Q, 8);
	if (GetHead(&Q, &x) == 1)
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);              /*�����ǰ��ͷԪ��5*/
	if (DeQueue(&Q, &x) == 1)
		printf("ִ��һ�γ��Ӳ���������Ԫ���ǣ�%d\n ", x);    /*�������Ԫ��5*/
	if (GetHead(&Q, &x) == 1)
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);              /*�����ǰ��ͷԪ��8*/
	printf("���������Ԫ�أ�");
	scanf("%d", &x);
	EnQueue(&Q, x);
	if (Empty(&Q) == 1)
		printf("����Ϊ��\n");
	else
		printf("���зǿ�\n");               /*������2��Ԫ�أ�������зǿ�*/
	getchar(); getchar();
	return 0;
}
