#include <stdio.h>
#include <malloc.h>
/*将单链表的结点结构定义和链栈的各个函数定义放到这里*/
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;
Node *InitStack( )
{
	Node *top = NULL;
	top = (Node *)malloc(sizeof(Node));
	top->next = NULL;
	return top;
}
void Push(Node *top, DataType x)
{
	Node *s = NULL;
	s = (Node *)malloc(sizeof(Node));          /*申请一个结点s*/
	s->data = x;
	s->next = top->next;
	top->next = s;                          /*将结点s插在栈顶*/
}
int GetTop(Node *top, DataType *ptr)
{
	if (top->next == NULL) { printf("下溢错误，取栈顶失败\n"); return 0; }
	*ptr = top->next->data; return 1;
}
int Pop(Node *top, DataType *ptr)
{
	Node *p = top->next;
	if (p == NULL) { printf("下溢错误，删除失败\n"); return 0; }
	*ptr = p->data;                              /*存储栈顶元素*/
	top->next = p->next;                               /*将栈顶结点摘链*/
	free(p);
	return 1;
}
int Empty(Node *top)
{
	if (top->next == NULL) return 1;                     /*栈空则返回1*/
	else return 0;
}
void DestroyStack(Node *top)
{
	Node *p = top;
	while (top != NULL)               /*依次释放链栈的每一个结点*/
	{
		top = top->next;
		free(p);
		p = top;
	}
}

int main()
{
	DataType x;
	Node *top = NULL;                 /*定义链栈的栈顶指针并初始化*/
	top = InitStack( );                                 /*初始化链栈*/
	printf("对15和10执行入栈操作，");
	Push(top, 15);
	Push(top, 10);
	if (GetTop(top, &x) == 1)
		printf("当前栈顶元素为：%d\n", x);            /*输出当前栈顶元素10*/
	if (Pop(top, &x) == 1)
		printf("执行一次出栈操作，删除元素：%d\n ", x);    /*输出出栈元素10*/
	if (GetTop(top, &x) == 1)
		printf("当前栈顶元素为：%d\n", x);           /*输出当前栈顶元素15*/
	printf("请输入待插入元素：");
	scanf("%d", &x);
	Push(top, x);
	if (Empty(top) == 1)
		printf("栈为空\n");
	else
		printf("栈非空\n");                  /*栈有2个元素，输出栈非空*/
	DestroyStack(top);
	getchar(); getchar();
	return 0;
}
