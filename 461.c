#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<malloc.h>

char* color[4]={"梅花","黑桃","红桃","方块"};
char* point[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char* card[13];

int main()
{
    printf("当前有%d张纸牌\n",);
    printf("请问你要发多少张牌？\n");
    // scanf();
    // 执行发牌的操作，然后下一步就把其输出
    // 判断卡的数目是否符合条件，上溢和下溢，符合才进行下一步
//for循环输出所要的牌写一个函数
    return 1;
}

// 目的是要发出不重复且随机的牌，那么牌的花色和点数都要随机
// 用随机数即可解决这个问题，然后是重复。解决重复即要知道
// 它是否已经是发出，所以则要有一个标识，创建一个二维的数组用0和1来区分


void SendCard(int n)
{
    int c,p;
    srand(time(NULL));
    


}
