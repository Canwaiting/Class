#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char DataType;
typedef struct BiNode
{
	DataType data;
	struct BiNode *lchild, *rchild;
}BiNode;
typedef struct
{
	BiNode *ptr;
	int flag;
} ElemType;

BiNode *CreatBiTree(BiNode *root)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		root = NULL;
	else
	{
		root = (BiNode*)malloc(sizeof(BiNode));
		root->data = ch;
		root->lchild = CreatBiTree(root->lchild);
		root->rchild = CreatBiTree(root->rchild);
	}
	return root;
}
void PreOrder(BiNode *root)
{
	BiNode *S[MaxSize], *bt = root;   /*����˳��ջ������ָ��bt��ʼ��*/
	int top = -1;                    /*��ʼ��˳��ջ*/
	while (bt != NULL || top != -1)    /*�������������������˳�ѭ��*/
	{
		while (bt != NULL)
		{
			printf("%c", bt->data);
			S[++top] = bt;             /*����ָ��bt��ջ*/
			bt = bt->lchild;
		}
		if (top != -1) {               /*ջ�ǿ�*/
			bt = S[top--];
			bt = bt->rchild;
		}
	}
}
void PostOrder(BiNode *root)
{
	ElemType S[MaxSize];                 /*����˳��ջ*/
	int top = 0;                          /*��ʼ��˳��ջ*/
	BiNode *bt = root;                    /*����ָ��bt��ʼ��*/
	do
	{
		while (bt!= NULL)
		{
			top++;
			S[top].ptr = bt; S[top].flag = 1;      /*root��ͬ��־flag��ջ*/
			bt = bt->lchild;
		}
		while (top != -1 && S[top].flag == 2)   /*ע����ѭ��������������ջ*/
		{
			bt = S[top--].ptr;
			printf("%c", bt->data);
		}
		if (top != -1) {
			S[top].flag = 2;
			bt = S[top].ptr->rchild;
		}
	}while (top != -1);           /*�������������������˳�ѭ��*/
}
void InOrder(BiNode *root)
{
	BiNode *S[MaxSize], *bt = root;   /*����˳��ջ������ָ��bt��ʼ��*/
	int top = -1;                    /*��ʼ��˳��ջ*/
	while (bt != NULL || top != -1)    /*�������������������˳�ѭ��*/
	{
		while (bt != NULL)
		{

			S[++top] = bt;             /*����ָ��bt��ջ*/
			bt = bt->lchild;
		}
		if (top != -1) {               /*ջ�ǿ�*/
			bt = S[top--];
			printf("%c", bt->data);
			bt = bt->rchild;
		}
	}
}
void LeverOrder(BiNode *root)
{
	BiNode *q = NULL, *Q[MaxSize];        /*����˳�����*/
	int front = -1, rear = -1;                     /*��ʼ��˳�����*/
	if (root == NULL) return;                /*������Ϊ�գ��㷨����*/
	Q[++rear] = root;                       /*��ָ�����*/
	while (front != rear)                     /*�����зǿ�ʱ*/
	{
		q = Q[++front];                       /*����*/
		printf("%c", q->data);                 /*���ʽ�㣬Ϊchar��*/
		if (q->lchild != NULL)  Q[++rear] = q->lchild;
		if (q->rchild != NULL)  Q[++rear] = q->rchild;
	}
}
void DestroyBiTree(BiNode *root)
{
	if (root == NULL)
		return;
	DestroyBiTree(root->lchild);
	DestroyBiTree(root->rchild);
	free(root);
}
int main()
{
	BiNode *root = NULL;
	root = CreatBiTree(root);
	printf("�ö������ĸ�����ǣ�%c\n", root->data);
	printf("\n�ö�������ǰ����������ǣ�");
	PreOrder(root);
	printf("\n�ö�������������������ǣ�");
	InOrder(root);
	printf("\n�ö������ĺ�����������ǣ�");
	PostOrder(root);
	printf("\n�ö������Ĳ�����������ǣ�");
	LeverOrder(root);
	DestroyBiTree(root);
	getchar(); getchar();
	return 0;
}