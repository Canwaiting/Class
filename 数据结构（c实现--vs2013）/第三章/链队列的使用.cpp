#include <stdio.h>
#include <malloc.h>
/*将链队列的存储结构定义和各个函数定义放到这里*/
typedef int DataType;               /*定义队列元素的数据类型，假设为int型*/
typedef struct Node                 /*定义链队列的结点结构*/
{
	DataType data;
	struct Node *next;
} Node;
typedef struct                       /*定义链队列*/
{
	Node *front, *rear;
} LinkQueue;
void InitQueue(LinkQueue *Q)
{
	Node *s = (Node *)malloc(sizeof(Node)); s->next = NULL;
	Q->front = Q->rear = s;            /*队头指针和队尾指针均指向头结点*/
}
void EnQueue(LinkQueue *Q, DataType x)
{
	Node *s = (Node *)malloc(sizeof(Node));
	s->data = x; s->next = NULL;        /*申请一个数据域为x的结点s*/
	Q->rear->next = s; Q->rear = s;       /*将结点s插入到队尾*/
}
int GetHead(LinkQueue *Q, DataType *ptr)
{
	Node *p = NULL;
	if (Q->rear == Q->front) { printf("下溢错误，取队头失败\n"); return 0; }
	p = Q->front->next;
	*ptr = p->data; return 1;
}
int DeQueue(LinkQueue *Q, DataType *ptr)
{
	Node *p;
	if (Q->rear == Q->front) { printf("下溢错误，删除失败\n"); return 0; }
	p = Q->front->next; *ptr = p->data;        /*存储队头元素*/
	Q->front->next = p->next;               /*将队头元素所在结点摘链*/
	if (p->next == NULL)                  /*判断出队前队列长度是否为1*/
		Q->rear = Q->front;
	free(p); return 1;
}
int Empty(LinkQueue *Q)
{
	if (Q->rear == Q->front) return 1;              /*队列为空返回1*/
	else return 0;
}
void DestroyQueue(LinkQueue *Q)
{
	Node *p = Q->front, *ptrtemp;
	while (p != NULL)                     /*依次释放链队列的结点*/
	{
		ptrtemp = p->next;
		free(p);
		p = ptrtemp;
	}
}

int main()
{
	DataType x;
	LinkQueue Q;                   /*定义结构体变量Q为链队列类型*/
	InitQueue(&Q);                  /*初始化链队列Q*/
	printf("对5和8执行入队操作，");
	EnQueue(&Q, 5);
	EnQueue(&Q, 8);
	if (GetHead(&Q, &x) == 1)
		printf("当前队头元素为：%d\n", x);              /*输出当前队头元素5*/
	if (DeQueue(&Q, &x) == 1)
		printf("执行一次出队操作，出队元素是：%d\n ", x);   /*输出出队元素5*/
	if (GetHead(&Q, &x) == 1)
		printf("当前队头元素为：%d\n", x);             /*输出当前队头元素8*/
	printf("请输入入队元素：");
	scanf("%d", &x);
	EnQueue(&Q, 5);
	if (Empty(&Q) == 1)
		printf("队列为空\n");
	else
		printf("队列非空\n");             /*队列有2个元素，输出队列非空*/
	DestroyQueue(&Q);
	getchar(); getchar();
	return 0;
}
