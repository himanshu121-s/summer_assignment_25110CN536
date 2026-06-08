#include<stdio.h>
int main(){
    int i,n,flag=0;
    printf("enter the number:");
    scanf("%d",&n);
    if(n==1){
         printf("neither prime nor composite");}
         else {
         if(n==2){ printf(" the number is the smallest prime number");}  
         else {   
         for(i=2;i<=n/2;i++){
        if(n%i==0)
        { flag=1;}}
        if(flag==1){
             printf("the number is not a prime number");}
             else { printf(" the number is prime");}}}
             return 0;}
      
            