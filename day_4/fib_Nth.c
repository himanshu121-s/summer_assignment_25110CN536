#include <stdio.h>
int main()
{
    int n, a = 0, b = 1, c;
    printf("enter n");
    scanf("%d", &n);
    if (n == 0)
        printf("Nth fibonacci numvber= %d", a);
    else if (n == 1)
        printf("Nth fibonacci number =%d", b);
    else
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
    printf(" Nth fibonacci numver = %d", b);
    return 0;
}