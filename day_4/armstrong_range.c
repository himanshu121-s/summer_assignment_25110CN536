#include <stdio.h>
#include <math.h>
int main()
{
    int start, end, num, temp, remainder, digits;
    int sum;
    printf("enter start and end of range:");
    scanf("%d%d", &start, &end);
    printf("armstrong numbers between %d and %d are:\n", start, end);
    for (num = start; num <= end; num++)
    {
        temp = num;
        digits = 0;
        sum = 0;
        while (temp != 0)
        {
            digits++;
            temp /= 10;
        }
        temp = num;
        while (temp != 0)
        {
            remainder = temp % 10;
            sum += pow(remainder, digits);
            temp /= 10;
        }
        if (sum == num)
            printf("%d", num);
    }
    return 0;
}