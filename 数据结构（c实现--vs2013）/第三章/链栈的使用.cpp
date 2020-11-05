#include <stdio.h>
#include <malloc.h>
/*��������Ľ��ṹ�������ջ�ĸ�����������ŵ�����*/
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
	s = (Node *)malloc(sizeof(Node));          /*����һ�����s*/
	s->data = x;
	s->next = top->next;
	top->next = s;                          /*�����s����ջ��*/
}
int GetTop(Node *top, DataType *ptr)
{
	if (top->next == NULL) { printf("�������ȡջ��ʧ��\n"); return 0; }
	*ptr = top->next->data; return 1;
}
int Pop(Node *top, DataType *ptr)
{
	Node *p = top->next;
	if (p == NULL) { printf("�������ɾ��ʧ��\n"); return 0; }
	*ptr = p->data;                              /*�洢ջ��Ԫ��*/
	top->next = p->next;                               /*��ջ�����ժ��*/
	free(p);
	return 1;
}
int Empty(Node *top)
{
	if (top->next == NULL) return 1;                     /*ջ���򷵻�1*/
	else return 0;
}
void DestroyStack(Node *top)
{
	Node *p = top;
	while (top != NULL)               /*�����ͷ���ջ��ÿһ�����*/
	{
		top = top->next;
		free(p);
		p = top;
	}
}

int main()
{
	DataType x;
	Node *top = NULL;                 /*������ջ��ջ��ָ�벢��ʼ��*/
	top = InitStack( );                                 /*��ʼ����ջ*/
	printf("��15��10ִ����ջ������");
	Push(top, 15);
	Push(top, 10);
	if (GetTop(top, &x) == 1)
		printf("��ǰջ��Ԫ��Ϊ��%d\n", x);            /*�����ǰջ��Ԫ��10*/
	if (Pop(top, &x) == 1)
		printf("ִ��һ�γ�ջ������ɾ��Ԫ�أ�%d\n ", x);    /*�����ջԪ��10*/
	if (GetTop(top, &x) == 1)
		printf("��ǰջ��Ԫ��Ϊ��%d\n", x);           /*�����ǰջ��Ԫ��15*/
	printf("�����������Ԫ�أ�");
	scanf("%d", &x);
	Push(top, x);
	if (Empty(top) == 1)
		printf("ջΪ��\n");
	else
		printf("ջ�ǿ�\n");                  /*ջ��2��Ԫ�أ����ջ�ǿ�*/
	DestroyStack(top);
	getchar(); getchar();
	return 0;
}
