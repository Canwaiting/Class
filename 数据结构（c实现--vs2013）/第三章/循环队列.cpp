#include <stdio.h>
/*将循环队列的存储结构定义和各个函数定义放到这里*/
#define QueueSize 100            /*定义数组的最大长度*/
typedef int DataType;             /*定义队列元素的数据类型，假设为int型*/
typedef struct
{
	DataType data[QueueSize];      /*存放队列元素的数组*/
	int front, rear;                 /*下标，队头元素和队尾元素的位置*/
} CirQueue;
void InitQueue(CirQueue *Q)
{
	Q->front = Q->rear = QueueSize - 1;
}
int EnQueue(CirQueue *Q, DataType x)
{
	if ((Q->rear + 1) % QueueSize == Q->front) {
		printf("上溢错误，插入失败\n"); return 0;
	}
	Q->rear = (Q->rear + 1) % QueueSize;      /*队尾位置在循环意义下加1*/
	Q->data[Q->rear] = x;                   /*在队尾处插入元素*/
	return 1;
}
int GetHead(CirQueue *Q, DataType *ptr)
{
	int i;
	if (Q->rear == Q->front) { printf("下溢错误，取队头失败\n"); return 0; }
	i = (Q->front + 1) % QueueSize;                /*注意不改变队头位置*/
	*ptr = Q->data[i]; return 1;
}
int DeQueue(CirQueue *Q, DataType *ptr)
{
	if (Q->rear == Q->front) { printf("下溢错误，删除失败\n"); return 0; }
	Q->front = (Q->front + 1) % QueueSize;    /*队头位置在循环意义下加1*/
	*ptr = Q->data[Q->front];                /*读取出队前的队头元素*/
	return 1;
}
int Empty(CirQueue *Q)
{
	if (Q->rear == Q->front) return 1;              /*队列为空返回1*/
	else return 0;
}


int main()
{
	DataType x;
	CirQueue Q;                     /*定义结构体变量Q为循环队列类型*/
	InitQueue(&Q);                   /*初始化循环队列Q*/
	printf("对5和8执行入队操作，");
	EnQueue(&Q, 5);
	EnQueue(&Q, 8);
	if (GetHead(&Q, &x) == 1)
		printf("当前队头元素为：%d\n", x);              /*输出当前队头元素5*/
	if (DeQueue(&Q, &x) == 1)
		printf("执行一次出队操作，出队元素是：%d\n ", x);    /*输出出队元素5*/
	if (GetHead(&Q, &x) == 1)
		printf("当前队头元素为：%d\n", x);              /*输出当前队头元素8*/
	printf("请输入入队元素：");
	scanf("%d", &x);
	EnQueue(&Q, x);
	if (Empty(&Q) == 1)
		printf("队列为空\n");
	else
		printf("队列非空\n");               /*队列有2个元素，输出队列非空*/
	getchar(); getchar();
	return 0;
}
