#include<stdio.h>
int main(){
    int d,n,pro=1;
    printf(" enter the number:");
    scanf("%d",&n);
    while(n>0){
        d= n%10;
        pro= pro*d;
        n= n/10;
    } printf(" the product of digits of the given number is:%d",pro);
    return 0;
}