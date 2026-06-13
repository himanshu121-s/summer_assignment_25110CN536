#include<stdio.h>
int main()
{
    int n,count = 0;
    printf("enter the number:");
    scanf("%d",&n);
    if (n==0){ 
        count = 1;
    }
    while(n > 0) {
       n = n / 10;
        count++;
    } printf("the number of digits is:%d",count);
    return 0;
}