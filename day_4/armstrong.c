#include <stdio.h>
#include <math.h>
int main()
{
    int num, originalnum, remainder, digits = 0;
    int result = 0;
    printf(" enter a number:");
    scanf("%d", &num);
    originalnum = num;
    while ((originalnum != 0))
    {
        originalnum /= 10;
        digits++;
    }
    originalnum = num;
    while (originalnum != 0)
    {
        remainder = originalnum % 10;
        result += pow(remainder, digits);
        originalnum /= 10;
    }
    if (result == num)
        printf("%d is an armstrong number", num);
    else
        printf("%d is not an armstrong number", num);
    return 0;
}