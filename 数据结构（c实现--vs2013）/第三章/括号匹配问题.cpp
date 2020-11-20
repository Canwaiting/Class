#include <stdio.h>              
int Match(char *str);                      /*�����������β�Ϊ�ַ���ָ��*/

int main()
{
	char str[100];                /*���御���ܴ���ַ������Խ��ռ��̵�����*/
	int k;                                /*k���յ��ú���Match�Ľ��*/
	printf("������һ����������ʽ��");
	scanf("%s", str);                       /*������ʽ���ַ�����ʽ����*/
	k = Match(str);                     /*�������ã�ʵ��Ϊ�ַ�������׵�ַ*/
	if (k == 0)
		printf("��ȷƥ��\n");
	else if (k == 1)
		printf("��������\n");
	else
		printf("��������\n");
	return 0;
}
int Matcchar *str)
{
	char s[100];                         /*����˳��ջ�����ٶ����ᷢ�����*/
	int i, top = -1;                        /*topΪջs��ջ��ָ��*/
	for (i = 0; str[i] != '\0'; i++)             /*���ζ�ÿһ���ַ�str[i]���д���*/
	{
		if (str[i] == ')') {                    /*��ǰɨ����ַ���������*/
			if (top > -1) top--;                /*��ջǰ�ж�ջ�Ƿ�Ϊ��*/
			else return -1;
		}
		else if (str[i] == '(')                 /*��ǰɨ����ַ���������*/
			s[++top] = str[i];              /*ִ����ջ����*/
	}
	if (top == -1)return 0;                /*ջ����������ȷƥ��*/	
	else return 1;
}
