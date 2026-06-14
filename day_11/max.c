#include <stdio.h>

// Function to find the maximum of two numbers
int findMax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int num1, num2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    max = findMax(num1, num2);

    printf("Maximum = %d\n", max);

    return 0;
}