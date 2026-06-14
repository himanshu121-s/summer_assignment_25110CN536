#include <stdio.h>

// Function to find the sum of two numbers
int findSum(int a, int b)
{
    return a + b;
}

int main()
{
    int num1, num2, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = findSum(num1, num2);

    printf("Sum = %d\n", sum);

    return 0;
}