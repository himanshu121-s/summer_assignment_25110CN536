#include <stdio.h>

// Function to calculate factorial
long int factorial(int n)
{
    long int fact = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial of %d = %ld\n", num, factorial(num));

    return 0;
}