#include <stdio.h>
#include <malloc.h>
/*�������еĴ洢�ṹ����͸�����������ŵ�����*/
typedef int DataType;               /*�������Ԫ�ص��������ͣ�����Ϊint��*/
typedef struct Node                 /*���������еĽ��ṹ*/
{
	DataType data;
	struct Node *next;
} Node;
typedef struct                       /*����������*/
{
	Node *front, *rear;
} LinkQueue;
void InitQueue(LinkQueue *Q)
{
	Node *s = (Node *)malloc(sizeof(Node)); s->next = NULL;
	Q->front = Q->rear = s;            /*��ͷָ��Ͷ�βָ���ָ��ͷ���*/
}
void EnQueue(LinkQueue *Q, DataType x)
{
	Node *s = (Node *)malloc(sizeof(Node));
	s->data = x; s->next = NULL;        /*����һ��������Ϊx�Ľ��s*/
	Q->rear->next = s; Q->rear = s;       /*�����s���뵽��β*/
}
int GetHead(LinkQueue *Q, DataType *ptr)
{
	Node *p = NULL;
	if (Q->rear == Q->front) { printf("�������ȡ��ͷʧ��\n"); return 0; }
	p = Q->front->next;
	*ptr = p->data; return 1;
}
int DeQueue(LinkQueue *Q, DataType *ptr)
{
	Node *p;
	if (Q->rear == Q->front) { printf("�������ɾ��ʧ��\n"); return 0; }
	p = Q->front->next; *ptr = p->data;        /*�洢��ͷԪ��*/
	Q->front->next = p->next;               /*����ͷԪ�����ڽ��ժ��*/
	if (p->next == NULL)                  /*�жϳ���ǰ���г����Ƿ�Ϊ1*/
		Q->rear = Q->front;
	free(p); return 1;
}
int Empty(LinkQueue *Q)
{
	if (Q->rear == Q->front) return 1;              /*����Ϊ�շ���1*/
	else return 0;
}
void DestroyQueue(LinkQueue *Q)
{
	Node *p = Q->front, *ptrtemp;
	while (p != NULL)                     /*�����ͷ������еĽ��*/
	{
		ptrtemp = p->next;
		free(p);
		p = ptrtemp;
	}
}

int main()
{
	DataType x;
	LinkQueue Q;                   /*����ṹ�����QΪ����������*/
	InitQueue(&Q);                  /*��ʼ��������Q*/
	printf("��5��8ִ����Ӳ�����");
	EnQueue(&Q, 5);
	EnQueue(&Q, 8);
	if (GetHead(&Q, &x) == 1)
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);              /*�����ǰ��ͷԪ��5*/
	if (DeQueue(&Q, &x) == 1)
		printf("ִ��һ�γ��Ӳ���������Ԫ���ǣ�%d\n ", x);   /*�������Ԫ��5*/
	if (GetHead(&Q, &x) == 1)
		printf("��ǰ��ͷԪ��Ϊ��%d\n", x);             /*�����ǰ��ͷԪ��8*/
	printf("���������Ԫ�أ�");
	scanf("%d", &x);
	EnQueue(&Q, 5);
	if (Empty(&Q) == 1)
		printf("����Ϊ��\n");
	else
		printf("���зǿ�\n");             /*������2��Ԫ�أ�������зǿ�*/
	DestroyQueue(&Q);
	getchar(); getchar();
	return 0;
}
