#include <stdio.h>
#include <malloc.h>
typedef struct
{
	char element;                  /*���輯��Ԫ��Ϊ�ַ�*/
	int parent;                     /*��Ԫ�ص�˫���������е��±�*/
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
	printf("Ŀǰ���ϵ�Ԫ���ǣ�\n");
	DivElem(S,6);
	printf("\n������Ҫ�ϲ�������Ԫ�أ�\n");
	scanf("%c %c", &k1, &k2);
	if (Find(S, FindSubscript(S, 6, k1)) == Find(S, FindSubscript(S, 6, k2)))
		printf("������Ԫ����ͬһ�������У�\n");
	else
	{
		Find(S, FindSubscript(S, 6, k1), FindSubscript(S, 6, k2));
		printf("\nĿǰ������Ԫ��Ϊ��\n");
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
int Find(ElemType S[], int k)        /*k�Ǵ���Ԫ���������е��±�*/
{
	while (S[k].parent != -1)
		k = S[k].parent;
	return k;
}

void Find(ElemType S[], int k1, int k2)     /*�ϲ�k1��k2����Ԫ��������*/
{
	int vex1 = Find(S, k1);
	int vex2 = Find(S, k2);
	if (vex1 != vex2) S[vex2].parent = vex1;
}
