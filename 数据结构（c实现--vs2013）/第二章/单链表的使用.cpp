#include <stdio.h>
#include <malloc.h>
/*将单链表的结点结构定义和各个函数定义放到这里*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;          /*定义线性表的数据类型，假设为int型*/
typedef struct Node            /*定义单链表的结点类型*/
{
	DataType data;
	struct Node *next;
} Node;



Node *CreatList(DataType a[], int n)
{
	Node *s = NULL;
	Node *first = (Node *)malloc(sizeof(Node));
	first->next = NULL;                             /*初始化头结点*/
	for (int i = 0; i < n; i++)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = a[i];                      /*为每个数组元素建立一个结点*/
		s->next = first->next; first->next = s;    /*将结点s插入到头结点之后*/
	}
	return first;
}
void PrintList(Node *first)
{
	Node *p = first->next;            /*工作指针p初始化*/
	while (p != NULL)
	{
		printf("%d ", p->data);         /*输出结点的数据域，假设为int型*/
		p = p->next;                 /*工作指针p后移，注意不能写作p++*/
	}
	printf("\n");
}
int Length(Node *first)
{
	Node *p = first->next;          /*工作指针p初始化*/
	int count = 0;                 /*累加器count初始化*/
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

int Insert(Node *first, int i, DataType x)
{
	Node *s = NULL, *p = first;       /*工作指针p初始化为指向头结点*/
	int count = 0;
	while (p != NULL && count < i - 1)          /*查找第i-1个结点*/
	{
		p = p->next;                           /*工作指针p后移*/
		count++;
	}
	if (p == NULL) { printf("位置错误，插入失败\n"); return 0; }
	else {
		s = (Node *)malloc(sizeof(Node));
		s->data = x;                       /*申请一个结点s，数据域为x*/
		s->next = p->next; p->next = s;       /*将结点s插入到结点p之后*/
		return 1;
	}
}

int Locate(Node *first, DataType x)
{
	Node *p = first->next;                /*工作指针p初始化*/
	int count = 1;                       /*累加器count初始化*/
	while (p != NULL)
	{
		if (p->data == x) return count;       /*查找成功，结束函数并返回序号*/
		p = p->next;
		count++;
	}
	return 0;                           /*退出循环表明查找失败*/
}
int Delete(Node *first, int i, DataType *ptr)
{
	Node *p = first, *q = NULL;          /*工作指针p要指向头结点*/
	int count = 0;
	DataType x;
	while (p != NULL && count < i - 1)    /*查找第i-1个结点*/
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL) {  /* p结点或p的后继结点不存在*/
		printf("位置错误，删除失败\n "); return 0;
	}
	else {
		q = p->next; *ptr = q->data;        /*存储被删结点和被删元素值*/
		p->next = q->next;               /*摘链*/
		free(q); return 1;
	}
}
void DestroyList(Node *first)
{
	Node *p = first;
	while (first != NULL)          /*依次释放每一个结点，包括头结点*/
	{
		first = first->next;
		free(p);
		p = first;
	}
}

int main()
{
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	Node *first = NULL;
	first = CreatList(r, 5);
	printf("当前线性表的数据为：");
	PrintList(first);                       /*输出当前链表1 2 3 4 5*/
	Insert(first, 2, 8);                     /*在第2个位置插入值为8的结点*/
	printf("执行插入操作后数据为：");
	PrintList(first);                      /*输出插入后链表1 8 2 3 4 5*/
	printf("当前单链表的长度为：%d\n", Length(first));      /*输出单链表长度6*/
	printf("请输入查找的元素值：");
	scanf("%d", &x);
	i = Locate(first, x);
	if(i!=0)
		printf("元素%d的元素位置为：%d\n", x, i);
	else
		printf("单链表中没有元素%d\n", x);
	printf("请输入要删除第几个元素：");
	scanf("%d", &i);
	if (Delete(first, i, &x) == 1) {                        /*删除第i个元素*/
		printf("删除的元素值是%d，执行删除操作后数据为：", x);
		PrintList(first);                                 /*输出删除后链表*/
	}
	else printf("删除操作失败\n");
	DestroyList(first);                                 /*释放单链表*/
	getchar(); getchar();
	return 0;
}
