#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int coef, exp;
	struct Node *next;
}Node;
Node *AddPolynomial(Node *A, Node*B);
Node *Creat();
void Print(Node *first);

int main()
{
	Node *A = NULL, *B = NULL;
	A = Creat();
	Print(A);
	B = Creat();
	Print(B);
	A = AddPolynomial(A, B);
	printf("结果是： ");
	Print(A);
	getchar(); getchar();
	return 0;
}

Node *Creat()
{
	Node *first = NULL, *r = NULL, *s = NULL;
	int coef, exp;
	first = (Node*)malloc(sizeof(Node));
	r = first;
	printf("请输入系数和指数：");
	scanf("%d%d", &coef, &exp);
	while (coef != 0)
	{
		s = (Node *)malloc(sizeof(Node));
		s->coef = coef;
		s->exp = exp;
		r->next = s;
		r = s;
		printf("请输入系数和指数： ");
		scanf("%d%d", &coef, &exp);
	}
	r->next = NULL;
	return first;
}
Node *AddPolynomial(Node *A, Node*B)
{
	Node *pre = A, *p = pre->next;
	Node *qre = B, *q = qre->next;
	Node *qtemp = NULL;
	while (p != NULL&&q != NULL)
	{
		if (p->exp < q->exp)
		{
			pre = p;
			p = p->next;
		}
		else if (p->exp>q->exp)
		{
			qtemp = q->next;
			pre->next = q;
			q->next = p;
			q = qtemp;
		}
		else
		{
			p->coef = p->coef + q->coef;
			if (p->coef == 0)
			{
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else
			{
				pre = p;
				p = p->next;
			}
			qre->next = q->next;
			free(q);
			q = qre->next;
		}
	}
	if (q != NULL)
		pre->next = q;
	free(B);
	return A;
}
void Print(Node *first)
{
	Node *p = first->next;
	if (p != NULL)
		printf("%dx%d", p->coef, p->exp);
	p = p->next;
	while (p != NULL)
	{
		if (p->coef > 0)
			printf("+%dx%d", p->coef, p->exp);
		else
			printf("%dx%d", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");
}