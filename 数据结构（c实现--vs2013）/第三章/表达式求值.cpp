#include <stdio.h>             
#include <string.h>  
int Compute(char *str);                  /*����������������ʽstr��ֵ*/
int Comp(char str1, char str2);             /*�����������Ƚ�str1��str2���ȼ�*/
/*�˳���ֻ�ܴ����������һλ�����*/
int main()
{
	char str[100];                /*���御���ܴ���ַ������Խ��ռ��̵�����*/
	int result;
	printf("������һ�����ʽ��");
	scanf("%s", str); strcat(str, "#");         /*���ռ������벢���϶����*/
	result = Compute(str);                 /* result���������*/
	printf("���ʽ��ֵ�ǣ�%d\n", result);
	getchar(); getchar();
	return 0;
}

int Compute(char *str)
{
	char OPND[100], OPTR[100];             /*��������˳��ջ*/
	OPTR[0] = '#';                          /*ջOPTR��ʼ��Ϊ�����*/
	int top1 = -1, top2 = 0;             /*��ʼ��ջOPND��OPTR��ջ��ָ��*/
	int i, k, x, y, z, op;
	for (i = 0; str[i] != '\0'; )                   /*����ɨ��ÿһ���ַ�*/
	{
		if (str[i] >= 48 && str[i] <= 57)          /*����0��ASCII����48*/
			OPND[++top1] = str[i++] - 48;        /*���ַ�ת��Ϊ����ѹջ*/
		else 
		{
			k = Comp(str[i], OPTR[top2]);
			if (k == 1)
				OPTR[++top2] = str[i++];            /*str[i]�����ȼ���*/
			else if (k == -1) 
			{                     /*str[i]�����ȼ���*/
				y = OPND[top1--];              /*���������ջ��ջ����Ԫ��*/
				x = OPND[top1--];
				op = OPTR[top2--];             /*�������ջ��ջһ��Ԫ��*/
				switch (op)                    /*opΪ�ַ��ͣ�������Ӧ����*/
				{
				case '+': z = x + y; break;
				case '-': z = x - y; break;
				case '*': z = x * y; break;
				case '/': z = x / y; break;
				default: break;
				}
				OPND[++top1] = z;             /*���������������ջ*/
			}
			else
			{                 /*str[i]�������ջ��ջ��Ԫ�����ȼ���ͬ*/
				top2--; i++;                    /*ƥ��str[i]��ɨ����һ���ַ�*/
			}
		}
	}
	return OPND[top1];               /*�������ջ��ջ��Ԫ�ؼ�Ϊ������*/
}
int Comp(char str1, char str2)
{           /*�Ƚ�str1��str2�����ȼ���1��str1�ߣ�0����ͬ��-1��str1��*/
	switch (str1)
	{
	case '+':
	case '-': if (str2 == '(' || str2 == '#') return 1; else return -1; break;
	case '*':
	case '/': if (str2 == '*' || str2 == '/') return -1; else return 1; break;
	case '(': return 1; break;
	case ')': if (str2 == '(') return 0; else return -1; break;
	case '#': if (str2 == '#') return 0; else return -1; break;
	default: break;
	}
}
