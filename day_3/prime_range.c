#include <stdio.h>
int main()
{
    int low, high, i, j, flag = 0;
    printf("enter the lowest number of range:");
    scanf("%d", &low);
    printf(" enter the highest number of range:");
    scanf("%d", &high);
    for (i = low; i <= high; i++)
    {
        flag = 1;
        if (i < 2)
            continue;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d", i);
        }
    }
    return 0;
}