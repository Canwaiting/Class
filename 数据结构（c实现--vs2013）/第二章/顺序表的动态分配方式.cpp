#include <stdio.h> 
#include <stdlib.h> 
/*��˳���Ĵ洢�ṹ����͸�����������ŵ�����*/
const int InitSize = 10;        /*˳���ĳ�ʼ����*/
const int IncreSize = 10;        /*˳���洢�ռ�ÿ����չ�ĳ���*/
typedef int DataType;          /*�������Ա���������ͣ�����Ϊint��*/
typedef struct
{
	DataType *data;           /*��̬��������ռ���׵�ַ*/
	int maxSize;              /*��ǰ����ռ����󳤶�*/
	int length;                /*���Ա�ĳ���*/
}SeqList;

void CreatList(SeqList *L, DataType a[], int n)
{
	L->data = (DataType *)malloc(InitSize * sizeof(DataType));
	L->maxSize = InitSize;
	while (n > L->maxSize)               /*���볤�ȴ���n�Ĵ洢�ռ�*/
	{
		L->maxSize = L->maxSize + IncreSize;
		L->data = (DataType *)realloc(L->data, L->maxSize * sizeof(DataType));
	}
	for (int i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
}
void PrintList(SeqList *L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);       /*������Ա��Ԫ��ֵ������Ϊint��*/
	printf("\n");
}
int Insert(SeqList *L, int i, DataType x)
{
	if (i < 1 || i > L->length + 1) { printf("λ��"); return 0; }
	if (L->length >= L->maxSize) {            /*�������磬����洢�ռ�*/
		L->maxSize = L->maxSize + IncreSize;
		L->data = (DataType *)realloc(L->data, L->maxSize * sizeof(DataType));
	}
	for (int j = L->length; j >= i; j--)             /*j��ʾԪ�����*/
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = x;
	L->length++;
	return 1;
}

int Length(SeqList *L)
{
	return L->length;
}
int Locate(SeqList *L, DataType x)
{
	for (int i = 0; i < L->length; i++)
	if (L->data[i] == x) return i + 1;           /*�������*/
	return 0;                               /*�˳�ѭ����˵������ʧ��*/
}
int Get(SeqList *L, int i, DataType *ptr)
{
	if (i < 1 || i > L->length) { printf("����λ�÷Ƿ�������ʧ��\n"); return 0; }
	else { *ptr = L->data[i - 1]; return 1; }
}
int Delete(SeqList *L, int i, DataType *ptr)
{
	if (L->length == 0) { printf("�������ɾ��ʧ��\n"); return 0; }
	if (i < 1 || i > L->length) { printf("λ�ô���ɾ��ʧ��\n"); return 0; }
	*ptr = L->data[i - 1];                       /*ȡ��λ��i��Ԫ��*/
	for (int j = i; j < L->length; j++)              /* j��ʾԪ�����������±�*/
		L->data[j - 1] = L->data[j];
	L->length--;
	return 1;
}
void DestroyList(SeqList *L)
{
	free(L->data);
}


int main()
{
	int r[10] = { 1, 2, 3, 4, 5,6,7,8,9,10 }, i, x;
	SeqList L;                         /*�������LΪ˳�������*/
	CreatList(&L, r, 10);                     /*��������10��Ԫ�ص�˳���*/
	printf("��ǰ���Ա������Ϊ��");
	PrintList(&L);                      /*�����ǰ���Ա�1, 2, 3, 4, 5,6,7,8,9,10*/
	Insert(&L, 11, 11);                    /*�ڵ�11��λ�ò���ֵΪ11��Ԫ��*/
	printf("ִ�в������������Ϊ��");
	PrintList(&L);                     /*������������Ա�1, 2, 3, 4, 5,6,7,8,9,10,11*/
	printf("��ǰ���Ա�ĳ���Ϊ��%d\n", Length(&L));    /*������Ա�ĳ���11*/
	printf("��������ҵ�Ԫ��ֵ��");
	scanf("%d", &x);
	i = Locate(&L, x);
	if (0 == i)
		printf("����ʧ��\n");
	else 
		printf("Ԫ��%d��λ��Ϊ��%d\n", x, i);
	printf("��������ҵڼ���Ԫ��ֵ��", &i);
	scanf("%d", &i);
	if (Get(&L, i, &x) == 1)
		printf("��%d��Ԫ��ֵ��%d\n", i, x);
	else printf("���Ա���û�е�%d��Ԫ��\n", i);
	printf("������Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &i);
	if (Delete(&L, i, &x) == 1)
	{                                            /*ɾ����i��Ԫ��*/
		printf("ɾ����%d��Ԫ����%d��ɾ��������Ϊ��", i, x);
		PrintList(&L);                         /*���ɾ��������Ա�*/
	}
	else 
		printf("ɾ������ʧ��\n");
	DestroyList(&L);
	getchar(); getchar();
	return 0;
}
