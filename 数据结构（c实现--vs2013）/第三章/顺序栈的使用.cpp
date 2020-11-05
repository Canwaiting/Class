#include <stdio.h>
/*��˳��ջ�Ĵ洢�ṹ����͸�����������ŵ�����*/
#define StackSize 100              /*�ٶ�ջԪ�����100��*/
typedef int DataType;              /*����ջԪ�ص��������ͣ�����Ϊint��*/
typedef struct
{
	DataType data[StackSize];        /*���ջԪ�ص�����*/
	int top;                        /*ջ��λ�ã�ջ��Ԫ���������е��±�*/
} SeqStack;
void InitStack(SeqStack *S)
{
	S->top = -1;
}
int Push(SeqStack *S, DataType x)
{
	if (S->top == StackSize - 1)
	{ 
		printf("������󣬲���ʧ��\n");
		return 0; 
	}
	S->data[++S->top] = x;
	return 1;
}
int GetTop(SeqStack *S, DataType *ptr)
{
	if (S->top == -1) 
	{ 
		printf("�������ȡջ��ʧ��\n");
		return 0; 
	}
	*ptr = S->data[S->top]; return 1;
}
int Pop(SeqStack *S, DataType *ptr)
{
	if (S->top == -1)
	{ 
		printf("�������ɾ��ʧ��\n");
		return 0; 
	}
	*ptr = S->data[S->top--];
	return 1;
}
int Empty(SeqStack *S)
{
	if (S->top == -1) return 1;                    /*ջ���򷵻�1*/
	else return 0;
}

int main()
{
	DataType x;
	SeqStack S;                          /*����ṹ�����SΪ˳��ջ����*/
	InitStack(&S);                                 /*��ʼ��˳��ջS*/
	printf("��15��10ִ����ջ������");
	Push(&S, 15);
	Push(&S, 10);
	if (GetTop(&S, &x) == 1)
		printf("��ǰջ��Ԫ��Ϊ��%d\n", x);             /*�����ǰջ��Ԫ��10*/
	if (Pop(&S, &x) == 1)
		printf("ִ��һ�γ�ջ������ɾ��Ԫ�أ�%d\n ", x);    /*�����ջԪ��10*/
	if (GetTop(&S, &x) == 1)
		printf("��ǰջ��Ԫ��Ϊ��%d\n", x);             /*�����ǰջ��Ԫ��15*/
	printf("���������ջԪ�أ�");
	scanf("%d", &x);
	Push(&S, x);
	if (Empty(&S) == 1)
		printf("ջΪ��\n");
	else
		printf("ջ�ǿ�\n");                   /*ջ��2��Ԫ�أ����ջ�ǿ�*/
	getchar(); getchar();
	return 0;
}
