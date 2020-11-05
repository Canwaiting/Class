#include <stdio.h>
#include <malloc.h>
/*��������Ľ��ṹ����͸�����������ŵ�����*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int DataType;          /*�������Ա���������ͣ�����Ϊint��*/
typedef struct Node            /*���嵥����Ľ������*/
{
	DataType data;
	struct Node *next;
} Node;



Node *CreatList(DataType a[], int n)
{
	Node *s = NULL;
	Node *first = (Node *)malloc(sizeof(Node));
	first->next = NULL;                             /*��ʼ��ͷ���*/
	for (int i = 0; i < n; i++)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = a[i];                      /*Ϊÿ������Ԫ�ؽ���һ�����*/
		s->next = first->next; first->next = s;    /*�����s���뵽ͷ���֮��*/
	}
	return first;
}
void PrintList(Node *first)
{
	Node *p = first->next;            /*����ָ��p��ʼ��*/
	while (p != NULL)
	{
		printf("%d ", p->data);         /*������������򣬼���Ϊint��*/
		p = p->next;                 /*����ָ��p���ƣ�ע�ⲻ��д��p++*/
	}
	printf("\n");
}
int Length(Node *first)
{
	Node *p = first->next;          /*����ָ��p��ʼ��*/
	int count = 0;                 /*�ۼ���count��ʼ��*/
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

int Insert(Node *first, int i, DataType x)
{
	Node *s = NULL, *p = first;       /*����ָ��p��ʼ��Ϊָ��ͷ���*/
	int count = 0;
	while (p != NULL && count < i - 1)          /*���ҵ�i-1�����*/
	{
		p = p->next;                           /*����ָ��p����*/
		count++;
	}
	if (p == NULL) { printf("λ�ô��󣬲���ʧ��\n"); return 0; }
	else {
		s = (Node *)malloc(sizeof(Node));
		s->data = x;                       /*����һ�����s��������Ϊx*/
		s->next = p->next; p->next = s;       /*�����s���뵽���p֮��*/
		return 1;
	}
}

int Locate(Node *first, DataType x)
{
	Node *p = first->next;                /*����ָ��p��ʼ��*/
	int count = 1;                       /*�ۼ���count��ʼ��*/
	while (p != NULL)
	{
		if (p->data == x) return count;       /*���ҳɹ��������������������*/
		p = p->next;
		count++;
	}
	return 0;                           /*�˳�ѭ����������ʧ��*/
}
int Delete(Node *first, int i, DataType *ptr)
{
	Node *p = first, *q = NULL;          /*����ָ��pҪָ��ͷ���*/
	int count = 0;
	DataType x;
	while (p != NULL && count < i - 1)    /*���ҵ�i-1�����*/
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL) {  /* p����p�ĺ�̽�㲻����*/
		printf("λ�ô���ɾ��ʧ��\n "); return 0;
	}
	else {
		q = p->next; *ptr = q->data;        /*�洢��ɾ���ͱ�ɾԪ��ֵ*/
		p->next = q->next;               /*ժ��*/
		free(q); return 1;
	}
}
void DestroyList(Node *first)
{
	Node *p = first;
	while (first != NULL)          /*�����ͷ�ÿһ����㣬����ͷ���*/
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
	printf("��ǰ���Ա������Ϊ��");
	PrintList(first);                       /*�����ǰ����1 2 3 4 5*/
	Insert(first, 2, 8);                     /*�ڵ�2��λ�ò���ֵΪ8�Ľ��*/
	printf("ִ�в������������Ϊ��");
	PrintList(first);                      /*������������1 8 2 3 4 5*/
	printf("��ǰ������ĳ���Ϊ��%d\n", Length(first));      /*�����������6*/
	printf("��������ҵ�Ԫ��ֵ��");
	scanf("%d", &x);
	i = Locate(first, x);
	if(i!=0)
		printf("Ԫ��%d��Ԫ��λ��Ϊ��%d\n", x, i);
	else
		printf("��������û��Ԫ��%d\n", x);
	printf("������Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &i);
	if (Delete(first, i, &x) == 1) {                        /*ɾ����i��Ԫ��*/
		printf("ɾ����Ԫ��ֵ��%d��ִ��ɾ������������Ϊ��", x);
		PrintList(first);                                 /*���ɾ��������*/
	}
	else printf("ɾ������ʧ��\n");
	DestroyList(first);                                 /*�ͷŵ�����*/
	getchar(); getchar();
	return 0;
}
