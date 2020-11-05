#include<stdio.h>
#include<malloc.h>
typedef int DataType;          /*定义线性表的数据类型，假设为int型*/
typedef struct Node            /*定义单链表的结点类型*/
{
	DataType data;
	struct Node *next;
} Node;
Node *RadixSort(Node *first, int d);
Node *CreatList(DataType a[], int n);

int main()
{
	int i;
	Node *first = NULL,*p;
	int a[9] = { 61, 98, 12, 15, 20, 24, 31, 23, 35 };
	first=CreatList(a, 9);
	p = first;
	printf("排序前的元素为：\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	first=RadixSort(first, 2);
	printf("排序后的元素为：\n");
	p = first;
	for (i = 1; i < 10; i++)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	getchar();
	return 0;
}
Node *CreatList(DataType a[], int n)
{
	Node *s = NULL, *r = NULL;
	Node *first = (Node *)malloc(sizeof(Node));    /*生成头结点*/
	r = first;                                  /*尾指针初始化*/
	for (int i = 0; i < n; i++)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = a[i];                    /*为每个数组元素建立一个结点*/
		r->next = s; r = s;                 /*将结点s插入到终端结点之后*/
	}
	r->next = NULL;        /*单链表建立完毕，将终端结点的指针域置空*/
	s = first; first = first->next;
	free(s);
	return first;
}

Node  *RadixSort(Node *first, int d)               /*d是记录的最大位数*/
{
	Node *front[10], *rear[10], *tail;      /*tail用于首尾相接时指向队尾*/
	int i, j, k, base = 1;                  /*base是被除数*/
	for (i = 1; i <= d; i++)               /*进行d趟基数排序*/
	{
		for (j = 0; j < 10; j++)
			front[j] = rear[j] = NULL;        /*清空每一个队列*/
		while (first != NULL)                /*分配，将记录分配到队列中*/
		{
			k = (first->data / base) % 10;
			if (front[k] == NULL) front[k] = rear[k] = first;
			else rear[k] = rear[k]->next = first;
			first = first->next;
		}
		for (j = 0; j < 10; j++)                 /*收集，将队列首尾相接*/
		{
			if (front[j] == NULL) continue;
			if (first == NULL) first = front[j];
			else tail->next = front[j];
			tail = rear[j];
		}
		tail->next = NULL;                  /*收集后单练表加尾标志*/
		base = base * 10;
		
	}
	return first;
}
