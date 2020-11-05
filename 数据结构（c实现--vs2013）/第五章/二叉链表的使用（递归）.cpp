#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char DataType;
typedef struct BiNode
{
	DataType data;
	struct BiNode *lchild, *rchild;
}BiNode;
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
	if (root == NULL)
		return;
	else
	{
		printf("%c", root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void InOrder(BiNode *root)
{
	if (root == NULL)
		return;
	else
	{
		InOrder(root->lchild);
		printf("%c", root->data);
		InOrder(root->rchild);
	}
}
void PostOrder(BiNode *root)
{
	if (root == NULL)
		return;
	else
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		printf("%c", root->data);
	}
}

void LeverOrder(BiNode *root)
{
	BiNode *q = NULL, *Q[MaxSize];        /*����˳�����*/
	int front = -1,rear=-1;                     /*��ʼ��˳�����*/
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