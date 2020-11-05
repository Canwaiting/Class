#include <stdio.h>
/*将顺序栈的存储结构定义和各个函数定义放到这里*/
#define StackSize 100              /*假定栈元素最多100个*/
typedef int DataType;              /*定义栈元素的数据类型，假设为int型*/
typedef struct
{
	DataType data[StackSize];        /*存放栈元素的数组*/
	int top;                        /*栈顶位置，栈顶元素在数组中的下标*/
} SeqStack;
void InitStack(SeqStack *S)
{
	S->top = -1;
}
int Push(SeqStack *S, DataType x)
{
	if (S->top == StackSize - 1)
	{ 
		printf("上溢错误，插入失败\n");
		return 0; 
	}
	S->data[++S->top] = x;
	return 1;
}
int GetTop(SeqStack *S, DataType *ptr)
{
	if (S->top == -1) 
	{ 
		printf("下溢错误，取栈顶失败\n");
		return 0; 
	}
	*ptr = S->data[S->top]; return 1;
}
int Pop(SeqStack *S, DataType *ptr)
{
	if (S->top == -1)
	{ 
		printf("下溢错误，删除失败\n");
		return 0; 
	}
	*ptr = S->data[S->top--];
	return 1;
}
int Empty(SeqStack *S)
{
	if (S->top == -1) return 1;                    /*栈空则返回1*/
	else return 0;
}

int main()
{
	DataType x;
	SeqStack S;                          /*定义结构体变量S为顺序栈类型*/
	InitStack(&S);                                 /*初始化顺序栈S*/
	printf("对15和10执行入栈操作，");
	Push(&S, 15);
	Push(&S, 10);
	if (GetTop(&S, &x) == 1)
		printf("当前栈顶元素为：%d\n", x);             /*输出当前栈顶元素10*/
	if (Pop(&S, &x) == 1)
		printf("执行一次出栈操作，删除元素：%d\n ", x);    /*输出出栈元素10*/
	if (GetTop(&S, &x) == 1)
		printf("当前栈顶元素为：%d\n", x);             /*输出当前栈顶元素15*/
	printf("请输入待入栈元素：");
	scanf("%d", &x);
	Push(&S, x);
	if (Empty(&S) == 1)
		printf("栈为空\n");
	else
		printf("栈非空\n");                   /*栈有2个元素，输出栈非空*/
	getchar(); getchar();
	return 0;
}
