#include<stdio.h>
int main(){
    int temp, n,d,rev=0;
    printf("enter the number:");
    scanf("%d",&n);
    temp=n;
    while(n>0){
        d=n%10;
        rev= rev*10+d;
        n=n/10;

    }if(temp==rev)
    { printf(" the given number is palindrome");}
        else {
         printf("the given number is not palindrome");}
    return 0;
}