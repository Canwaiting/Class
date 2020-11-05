#include<stdio.h>
#include<malloc.h>
typedef int DataType;          /*�������Ա���������ͣ�����Ϊint��*/
typedef struct Node            /*���嵥����Ľ������*/
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
	printf("����ǰ��Ԫ��Ϊ��\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	first=RadixSort(first, 2);
	printf("������Ԫ��Ϊ��\n");
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
	Node *first = (Node *)malloc(sizeof(Node));    /*����ͷ���*/
	r = first;                                  /*βָ���ʼ��*/
	for (int i = 0; i < n; i++)
	{
		s = (Node *)malloc(sizeof(Node));
		s->data = a[i];                    /*Ϊÿ������Ԫ�ؽ���һ�����*/
		r->next = s; r = s;                 /*�����s���뵽�ն˽��֮��*/
	}
	r->next = NULL;        /*����������ϣ����ն˽���ָ�����ÿ�*/
	s = first; first = first->next;
	free(s);
	return first;
}

Node  *RadixSort(Node *first, int d)               /*d�Ǽ�¼�����λ��*/
{
	Node *front[10], *rear[10], *tail;      /*tail������β���ʱָ���β*/
	int i, j, k, base = 1;                  /*base�Ǳ�����*/
	for (i = 1; i <= d; i++)               /*����d�˻�������*/
	{
		for (j = 0; j < 10; j++)
			front[j] = rear[j] = NULL;        /*���ÿһ������*/
		while (first != NULL)                /*���䣬����¼���䵽������*/
		{
			k = (first->data / base) % 10;
			if (front[k] == NULL) front[k] = rear[k] = first;
			else rear[k] = rear[k]->next = first;
			first = first->next;
		}
		for (j = 0; j < 10; j++)                 /*�ռ�����������β���*/
		{
			if (front[j] == NULL) continue;
			if (first == NULL) first = front[j];
			else tail->next = front[j];
			tail = rear[j];
		}
		tail->next = NULL;                  /*�ռ��������β��־*/
		base = base * 10;
		
	}
	return first;
}
