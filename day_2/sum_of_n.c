#include<stdio.h>
int main(){
    int n,d, sum=0;
    printf(" enter the number:");
    scanf("%d",&n);
    while(n>0){
        d= n%10;
        sum= sum+d;
        n=n/10;
    } printf( " the sum of entered number is:%d", sum);
    return 0;
}