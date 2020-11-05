#include<stdio.h>
/*��˳���Ĵ洢�ṹ����͸�����������ŵ�����*/
#define MaxSize 100           /*����˳��������100��Ԫ��*/
typedef int DataType;           /*�������Ա���������ͣ�����Ϊint��*/
typedef struct
{
	DataType data[MaxSize];    /*�������Ԫ�ص�����*/
	int length;                 /*���Ա�ĳ���*/
} SeqList;

int CreatList(SeqList *L, DataType a[], int n)
{
	if (n > MaxSize) 
	{
		printf("˳���Ŀռ䲻�����޷�����˳���\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		L->data[i] = a[i];
	L->length = n;
	return 1;
}

void PrintList(SeqList *L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d ", L->data[i]);       /*������Ա��Ԫ��ֵ������Ϊint��*/
	printf("\n");
}
int Insert(SeqList *L, int i, DataType x)
{
	if (L->length >= MaxSize) 
	{
		printf("������󣬲���ʧ��\n");
		return 0;
	}
	if (i < 1 || i > L->length + 1) 
	{ 
		printf("λ�ô��󣬲���ʧ��\n");
		return 0; 
	}
	for (int j = L->length; j >= i; j--)                   /*j��ʾԪ�����*/
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = x;
	L->length++;
	return 1;
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

int Length(SeqList *L)
{
	return L->length;
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

int main()
{
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList L;                         /*�������LΪ˳�������*/
	CreatList(&L, r, 5);                     /*��������5��Ԫ�ص�˳���*/
	printf("��ǰ���Ա������Ϊ��");
	PrintList(&L);                      /*�����ǰ���Ա�1 2 3 4 5*/
	Insert(&L, 2, 8);                    /*�ڵ�2��λ�ò���ֵΪ8��Ԫ��*/
	printf("ִ�в������������Ϊ��");
	PrintList(&L);                     /*������������Ա�1 8 2 3 4 5*/
	printf("��ǰ���Ա�ĳ���Ϊ��%d\n", Length(&L));    /*������Ա�ĳ���6*/
	printf("��������ҵ�Ԫ��ֵ��");
	scanf("%d", &x);
	i = Locate(&L, x);
	if (0 == i) printf("����ʧ��\n");
	else printf("Ԫ��%d��λ��Ϊ��%d\n", x, i);
	printf("��������ҵڼ���Ԫ��ֵ��", &i);
	scanf("%d", &i);
	if (Get(&L, i, &x) == 1) printf("��%d��Ԫ��ֵ��%d\n", i, x);
	else printf("���Ա���û�е�%d��Ԫ��\n", i);
	printf("������Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &i);
	if (Delete(&L, i, &x) == 1) {                /*ɾ����i��Ԫ��*/
		printf("ɾ����%d��Ԫ����%d��ɾ��������Ϊ��", i, x);
		PrintList(&L);                         /*���ɾ��������Ա�*/
	}
	else printf("ɾ������ʧ��\n");
	getchar(); getchar();
	return 0;
}
