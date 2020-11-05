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
	BiNode *S[MaxSize], *bt = root;   /*定义顺序栈，工作指针bt初始化*/
	int top = -1;                    /*初始化顺序栈*/
	while (bt != NULL || top != -1)    /*两个条件都不成立才退出循环*/
	{
		while (bt != NULL)
		{
			printf("%c", bt->data);
			S[++top] = bt;             /*将根指针bt入栈*/
			bt = bt->lchild;
		}
		if (top != -1) {               /*栈非空*/
			bt = S[top--];
			bt = bt->rchild;
		}
	}
}
void PostOrder(BiNode *root)
{
	ElemType S[MaxSize];                 /*定义顺序栈*/
	int top = 0;                          /*初始化顺序栈*/
	BiNode *bt = root;                    /*工作指针bt初始化*/
	do
	{
		while (bt!= NULL)
		{
			top++;
			S[top].ptr = bt; S[top].flag = 1;      /*root连同标志flag入栈*/
			bt = bt->lchild;
		}
		while (top != -1 && S[top].flag == 2)   /*注意是循环，可能连续出栈*/
		{
			bt = S[top--].ptr;
			printf("%c", bt->data);
		}
		if (top != -1) {
			S[top].flag = 2;
			bt = S[top].ptr->rchild;
		}
	}while (top != -1);           /*两个条件都不成立才退出循环*/
}
void InOrder(BiNode *root)
{
	BiNode *S[MaxSize], *bt = root;   /*定义顺序栈，工作指针bt初始化*/
	int top = -1;                    /*初始化顺序栈*/
	while (bt != NULL || top != -1)    /*两个条件都不成立才退出循环*/
	{
		while (bt != NULL)
		{

			S[++top] = bt;             /*将根指针bt入栈*/
			bt = bt->lchild;
		}
		if (top != -1) {               /*栈非空*/
			bt = S[top--];
			printf("%c", bt->data);
			bt = bt->rchild;
		}
	}
}
void LeverOrder(BiNode *root)
{
	BiNode *q = NULL, *Q[MaxSize];        /*采用顺序队列*/
	int front = -1, rear = -1;                     /*初始化顺序队列*/
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