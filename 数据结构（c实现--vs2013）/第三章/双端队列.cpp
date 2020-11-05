#include<stdio.h>
/*将双端队列的存储结构定义和各个函数定义放到这里*/
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
int EnQueueHead(DoubleQueue *Q, DataType x)   /*插入x到队头。若队满则插入失败，返回0，否则返回1*/
{
	if ((Q->rear + 1) == Q->front)
	{
		printf("上溢错误，插入失败\n");
		return 0;
	}
	Q->data[Q->front] = x;                                                 /*将x值赋给front所指的位置*/
	Q->front = Q->front - 1 ;                                     /*先让front减1*/
	
	return 1;
}
int EnQueueTail(DoubleQueue *Q, DataType x)
{
	if ((Q->rear+1)==Q->front)
	{
		printf("下溢错误，插入失败\n");
		return 0;
	}
	Q->rear = (Q->rear + 1)%DoubleQueueSize;
	Q->data[Q->rear] = x;
	
	return 1;

}
int DeQueueHead(DoubleQueue *Q, DataType *ptr)//&x)       /*删去队头元素，其值通过x返回。若队空则删除失败，返回0，否则返回1*/
{
	if (Q->front == Q->rear)
		return 0;
	Q->front = (Q->front + 1)%DoubleQueueSize;                   /*front值加1*/
	*ptr = Q->data[Q->front];                   /*将front所指位置的值赋给x*/
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
	DoubleQueue Q;                     /*定义结构体变量Q为循环队列类型*/
	InitQueue(&Q);                   /*初始化循环队列Q*/
	printf("对5执行队头插入操作：");       /*插入队头元素5*/
	EnQueueHead(&Q, 5);
	printf("\n");
	printf("对6执行队头插入操作：");      /*插入队头元素6*/
	EnQueueHead(&Q, 6);
	printf("\n");
	printf("对8执行队尾插入操作：");     /*插入队尾元素8*/
	EnQueueTail(&Q, 8);
	printf("\n");
	printf("对9执行队尾插入操作：");      /*插入队尾元素9*/
	EnQueueTail(&Q,9);
	printf("\n");
	if (GetHead(&Q, &x) == 1)
		printf("当前队头元素为：%d\n", x);              /*输出当前队头元素6*/
	if (DeQueueHead(&Q, &x) == 1)
		printf("执行一次队头出队操作，出队元素是：%d\n ", x);    /*输出出队元素6*/
	if (GetHead(&Q, &x) == 1)                            /*输出当前队头元素5*/
		printf("当前队头元素为：%d\n", x);
	if (GetTail(&Q, &x) == 1)
		printf("当前队尾元素为：%d\n", x);              /*输出当前队尾元素9*/
	if (DeQueueTail(&Q, &x) == 1)
		printf("执行一次队尾出队操作，出队元素是：%d\n ", x);    /*输出出队尾元素9*/
	if (GetTail(&Q, &x) == 1)
		printf("当前队尾元素为：%d\n", x);             /*输出当前队尾元素8*/
	printf("请输入在队头插入的元素：");
	scanf("%d", &x);      
	EnQueueHead(&Q, x);                           /*插入队头元素*/
	printf("请输入在队尾插入的元素：");
	scanf("%d", &x);
	EnQueueTail(&Q, x);                           /*插入队头元素*/
	if (Empty(&Q) == 1)
		printf("队列为空\n");
	else
		printf("队列非空\n");               /*队列有3个元素，输出队列非空*/
	getchar(); getchar();
	return 0;
}
