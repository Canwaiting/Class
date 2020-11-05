#include<stdio.h>
#include<malloc.h>
#define MaxSize 10                 /*ͼ����󶥵���*/
typedef char DataType;              /*����ͼ�ж�����������ͣ�����Ϊchar��*/
typedef struct EdgeNode              /*����߱���*/
{
	int adjvex;
	struct EdgeNode *next;
} EdgeNode;
typedef struct                      /*���嶥�����*/
{
	DataType vertex;
	int in;
	EdgeNode *first;
} VertexNode;
typedef struct                      /*�����ڽӱ�洢�ṹ*/
{
	VertexNode adjlist[MaxSize];      /*��Ŷ���������*/
	int vertexNum, edgeNum;         /*ͼ�Ķ������ͱ���*/
} ALGraph;
void TopSort(ALGraph *G);
void CreatGraph(ALGraph *G,DataType a[],int n,int e);

int main()
{
	ALGraph G;
	int n, e;
	char a[6];
	printf("�����붥��ĸ�����\n");
	scanf("%d", &n);
	printf("������ߵ�������\n");
	scanf("%d", &e);
	printf("�����붥�㣺\n");
	getchar();                        //�������ܻ��з�
	for (int i = 0; i < n; i++)
		scanf("%c", &a[i]);
	CreatGraph(&G,a,n,e);
	printf("��������Ϊ��\n");
	TopSort(&G);
	getchar(); getchar();
	return 0;
}

void CreatGraph(ALGraph *G,DataType a[],int n,int e)
{
	int i, j, k;
	EdgeNode *s = NULL;
	G->vertexNum=n;
	G->edgeNum=e;
	for (i = 0; i < G->vertexNum; i++)
	{
		G->adjlist[i].vertex=a[i];
	}
	printf("�����붥�����ȣ�\n");
	fflush(stdin);
	for (i = 0; i < G->vertexNum; i++)
	{
		scanf("%d",&G->adjlist[i].in);
		
	}
	for (i = 0; i < G->vertexNum; i++)
	{
		G->adjlist[i].first = NULL;         /*��ʼ���߱��ͷָ��*/
	}
	
	printf("������������Ķ�����:\n");
	for (k = 0; k < G->edgeNum; k++)
	{
		scanf("%d %d", &i, &j);           /*������������Ķ�����*/
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = G->adjlist[i].first;        /*��s���뵽��i���߱�ı�ͷ*/
		G->adjlist[i].first = s;
	}
	
}

void TopSort(ALGraph *G)
{
	int i, j, k, count = 0;                    /*�ۼ���count��ʼ��*/
	int S[MaxSize], top = -1;                /*����˳��ջ����ʼ��*/
	EdgeNode *p = NULL;
	for (i = 0; i < G->vertexNum; i++)        /*ɨ�趥���*/
	if (G->adjlist[i].in == 0)  S[++top] = i;  /*�����Ϊ0�Ķ���ѹջ*/
	while (top != -1)                      /*��ջ�л������Ϊ0�Ķ���ʱ*/
	{
		j = S[top--];                     /*��ջ��ȡ��һ�����Ϊ0�Ķ���*/
		printf("%c ", G->adjlist[j].vertex);
		count++;
		p = G->adjlist[j].first;             /*����ָ��p��ʼ��*/
		while (p != NULL)               /*�趥����ҳ�����j�����г���*/
		{
			k = p->adjvex;
			G->adjlist[k].in--;
			if (G->adjlist[k].in == 0) S[++top] = k;    /*�����Ϊ0�Ķ�����ջ*/
			p = p->next;
		}
	}
	if (count < G->vertexNum)  printf("�л�·");
}
