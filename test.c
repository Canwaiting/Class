#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    srand(time(NULL));
    printf("%d",rand() % 11);
    return 1;

}
