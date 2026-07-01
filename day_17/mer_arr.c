#include <stdio.h>

int main()
{
    int arr1[100], arr2[100], arr3[200];
    int n1, n2, i, j;

    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of first array:\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of second array:\n");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }

    for(j = 0; j < n2; j++)
    {
        arr3[i] = arr2[j];
        i++;
    }

    printf("Merged array:\n");
    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}