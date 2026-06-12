#include <stdio.h>

int reverse = 0;

int reverseNumber(int n) {
    if (n == 0)
        return reverse;

    reverse = reverse * 10 + (n % 10);
    reverseNumber(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    reverse = 0;
    reverseNumber(num);

    printf("Reversed number = %d\n", reverse);

    return 0;
}