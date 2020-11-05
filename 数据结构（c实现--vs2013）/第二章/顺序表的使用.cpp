#include<stdio.h>
/*将顺序表的存储结构定义和各个函数定义放到这里*/
#define MaxSize 100           /*假设顺序表最多存放100个元素*/
typedef int DataType;           /*定义线性表的数据类型，假设为int型*/
typedef struct
{
	DataType data[MaxSize];    /*存放数据元素的数组*/
	int length;                 /*线性表的长度*/
} SeqList;

int CreatList(SeqList *L, DataType a[], int n)
{
	if (n > MaxSize) 
	{
		printf("顺序表的空间不够，无法建立顺序表\n");
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
		printf("%d ", L->data[i]);       /*输出线性表的元素值，假设为int型*/
	printf("\n");
}
int Insert(SeqList *L, int i, DataType x)
{
	if (L->length >= MaxSize) 
	{
		printf("上溢错误，插入失败\n");
		return 0;
	}
	if (i < 1 || i > L->length + 1) 
	{ 
		printf("位置错误，插入失败\n");
		return 0; 
	}
	for (int j = L->length; j >= i; j--)                   /*j表示元素序号*/
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = x;
	L->length++;
	return 1;
}

int Locate(SeqList *L, DataType x)
{
	for (int i = 0; i < L->length; i++)
	if (L->data[i] == x) return i + 1;           /*返回序号*/
	return 0;                               /*退出循环，说明查找失败*/
}
int Get(SeqList *L, int i, DataType *ptr)
{
	if (i < 1 || i > L->length) { printf("查找位置非法，查找失败\n"); return 0; }
	else { *ptr = L->data[i - 1]; return 1; }
}

int Length(SeqList *L)
{
	return L->length;
}

int Delete(SeqList *L, int i, DataType *ptr)
{
	if (L->length == 0) { printf("下溢错误，删除失败\n"); return 0; }
	if (i < 1 || i > L->length) { printf("位置错误，删除失败\n"); return 0; }
	*ptr = L->data[i - 1];                       /*取出位置i的元素*/
	for (int j = i; j < L->length; j++)              /* j表示元素所在数组下标*/
		L->data[j - 1] = L->data[j];
	L->length--;
	return 1;
}

int main()
{
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList L;                         /*定义变量L为顺序表类型*/
	CreatList(&L, r, 5);                     /*建立具有5个元素的顺序表*/
	printf("当前线性表的数据为：");
	PrintList(&L);                      /*输出当前线性表1 2 3 4 5*/
	Insert(&L, 2, 8);                    /*在第2个位置插入值为8的元素*/
	printf("执行插入操作后数据为：");
	PrintList(&L);                     /*输出插入后的线性表1 8 2 3 4 5*/
	printf("当前线性表的长度为：%d\n", Length(&L));    /*输出线性表的长度6*/
	printf("请输入查找的元素值：");
	scanf("%d", &x);
	i = Locate(&L, x);
	if (0 == i) printf("查找失败\n");
	else printf("元素%d的位置为：%d\n", x, i);
	printf("请输入查找第几个元素值：", &i);
	scanf("%d", &i);
	if (Get(&L, i, &x) == 1) printf("第%d个元素值是%d\n", i, x);
	else printf("线性表中没有第%d个元素\n", i);
	printf("请输入要删除第几个元素：");
	scanf("%d", &i);
	if (Delete(&L, i, &x) == 1) {                /*删除第i个元素*/
		printf("删除第%d个元素是%d，删除后数据为：", i, x);
		PrintList(&L);                         /*输出删除后的线性表*/
	}
	else printf("删除操作失败\n");
	getchar(); getchar();
	return 0;
}
