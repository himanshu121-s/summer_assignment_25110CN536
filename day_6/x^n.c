#include <stdio.h>

int main() {
    int x, n, i;
    long long result = 1;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter exponent (n): ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        result = result * x;
    }

    printf("%d^%d = %lld\n", x, n, result);

    return 0;
}