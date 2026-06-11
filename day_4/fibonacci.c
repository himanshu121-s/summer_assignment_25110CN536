#include <stdio.h>
int main()
{
    int n, first = 0, second = 1, next;
    printf("enter the number of terms:");
    scanf("%d", &n);
    printf(" the fibonacci series:");
    for (int i = 0; i < n; i++)

    {
        printf("%d", first);
        next = first + second;
        first = second;
        second = next;
    }
    return 0;
}