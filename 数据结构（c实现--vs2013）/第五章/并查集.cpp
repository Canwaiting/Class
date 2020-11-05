#include <stdio.h>
#include <malloc.h>
typedef struct
{
	char element;                  /*假设集合元素为字符*/
	int parent;                     /*该元素的双亲在数组中的下标*/
} ElemType;
int Find(ElemType S[], int k);
void Find(ElemType S[], int k1, int k2);
int FindSubscript(ElemType S[],int n, char ch);
void DivElem(ElemType S[], int n);

int main()
{
	ElemType S[6] = { { 'a', -1 }, { 'b', 0 }, { 'c', 0 }, {'d',-1}, {'e',3}, {'f',-1} };
	int i, k;
	char k1, k2;
	printf("目前集合的元素是：\n");
	DivElem(S,6);
	printf("\n请输入要合并的两个元素：\n");
	scanf("%c %c", &k1, &k2);
	if (Find(S, FindSubscript(S, 6, k1)) == Find(S, FindSubscript(S, 6, k2)))
		printf("这两个元素在同一个集合中！\n");
	else
	{
		Find(S, FindSubscript(S, 6, k1), FindSubscript(S, 6, k2));
		printf("\n目前个集合元素为：\n");
		DivElem(S, 6);
	}
		
	getchar(); getchar();
	return 0;
	
}
void DivElem(ElemType S[],int n)
{
	int i,l,j=0,k,elem[6];
	for (i = 0; i < n; i++)
	{
		if (S[i].parent == -1)
			elem[j++] = i;
	}
	for (i = 0; i < j; i++)
	{
		printf("{%c ",S[elem[i]].element);
		for (k = 0; k < n; k++)
		{
			if (S[k].parent == elem[i])
			{
				printf("%c ", S[k].element);
				for (l = 0; l < n; l++)
					if (S[l].parent == k && S[l].parent != S[k].parent)
						printf("%c ", S[l].element);
			}
				
		}
		
		printf("}");
		
	}
}
int FindSubscript(ElemType S[],int n, char ch)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (S[i].element == ch)
			return i;
	}
	return 0;
}
int Find(ElemType S[], int k)        /*k是待查元素在数组中的下标*/
{
	while (S[k].parent != -1)
		k = S[k].parent;
	return k;
}

void Find(ElemType S[], int k1, int k2)     /*合并k1和k2两个元素所在树*/
{
	int vex1 = Find(S, k1);
	int vex2 = Find(S, k2);
	if (vex1 != vex2) S[vex2].parent = vex1;
}
