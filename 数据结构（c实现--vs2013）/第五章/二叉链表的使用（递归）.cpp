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
	BiNode *q = NULL, *Q[MaxSize];        /*采用顺序队列*/
	int front = -1,rear=-1;                     /*初始化顺序队列*/
	if (root == NULL) return;                /*二叉树为空，算法结束*/
	Q[++rear] = root;                       /*根指针入队*/
	while (front != rear)                     /*当队列非空时*/
	{
		q = Q[++front];                       /*出队*/
		printf("%c", q->data);                 /*访问结点，为char型*/
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
	printf("该二叉树的根结点是：%c\n", root->data);
	printf("\n该二叉树的前序遍历序列是：");
	PreOrder(root);
	printf("\n该二叉树的中序遍历序列是：");
	InOrder(root);
	printf("\n该二叉树的后序遍历序列是：");
	PostOrder(root);
	printf("\n该二叉树的层序遍历序列是：");
	LeverOrder(root);
	DestroyBiTree(root);
	getchar(); getchar();
	return 0;
}