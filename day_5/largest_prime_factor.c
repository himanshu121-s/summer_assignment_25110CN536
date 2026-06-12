#include <stdio.h>

int main() {
    int num, i, largestPrime = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    for(i = 2; i <= num; i++) {
        while(num % i == 0) {
            largestPrime = i;
            num = num / i;
        }
    }

    printf("Largest Prime Factor = %d\n", largestPrime);

    return 0;
}