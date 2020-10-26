#include<stdio.h>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// 创建一个环，首先先定义一个结构体，然后尾指针指向自己，
// 形成一个环，然后通过循环不断插入，然后把这个环扩充。



Node * Creat(int n)
{
    Node* rear = NULL;
    Node* index;
    rear = (Node*)malloc(sizeof(Node));
    rear->data = 1;
    rear->next = rear;
    for(int i=2;i<=n;i++)
    {
        index = (Node*)malloc(sizeof(Node));
        index->data = i;
        index->next = rear;
        rear->next = index;
        rear = index;
    }
    return rear;
}
    

// 定义一个计数器，要是计数的值和给定的值大小相等，就把此时的所指向的
// 结构体移除，此时相当于在链表中执行删除的操作，然后把计数器归1，然后
// 继续执行，直至这个环只有一个数，然后再把这个数输出。

void Joseph(Node* rear,int m)
{
    Node* pre = rear,*p = rear->next;
    int count = 1;
    printf("出环的顺序为:\n");
    while(p->next!=p)
    {
        if(count<m)
        {
            pre = p;
            p = p->next;
            count++;
        }
        else
        {
            printf("%-3d\n",p->data);
            pre->next = p->next;
            free(p);
            p = pre->next;
            count = 1;
        }
    }
    printf("%-3d\n",p->data);
    free(p); 
}

Node* Creat(int n);
void Joseph(Node *rear,int m);



int main()
{
    int n,m;
    Node* rear = NULL;
    printf("请输入约瑟夫环的长度:\n");
    scanf("%d",&n);
    printf("请输入每次循环的数字:\n");
    scanf("%d",&m);
    rear = Creat(n);
    Joseph(rear,m);
    return 0;
}
