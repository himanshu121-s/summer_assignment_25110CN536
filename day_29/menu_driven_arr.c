#include <stdio.h>

int main()
{
    int arr[100];
    int n, choice;
    int i, j;
    int value, position;
    int found;
    int temp;
    int max, min, sum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n====================================\n");
        printf("     MENU DRIVEN ARRAY OPERATIONS\n");
        printf("====================================\n");

        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Sort Array\n");
        printf("6. Reverse Array\n");
        printf("7. Find Maximum Element\n");
        printf("8. Find Minimum Element\n");
        printf("9. Find Sum of Elements\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n == 0)
                {
                    printf("Array is empty!\n");
                }
                else
                {
                    printf("Array elements are: ");

                    for (i = 0; i < n; i++)
                    {
                        printf("%d ", arr[i]);
                    }

                    printf("\n");
                }
                break;

            case 2:
                if (n >= 100)
                {
                    printf("Array is full!\n");
                    break;
                }

                printf("Enter position to insert: ");
                scanf("%d", &position);

                printf("Enter value to insert: ");
                scanf("%d", &value);

                if (position < 1 || position > n + 1)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for (i = n; i >= position; i--)
                    {
                        arr[i] = arr[i - 1];
                    }

                    arr[position - 1] = value;
                    n++;

                    printf("Element inserted successfully!\n");
                }
                break;

            case 3:
                if (n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter position to delete: ");
                scanf("%d", &position);

                if (position < 1 || position > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for (i = position - 1; i < n - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }

                    n--;

                    printf("Element deleted successfully!\n");
                }
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &value);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (arr[i] == value)
                    {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Element not found!\n");
                }
                break;

            case 5:
                for (i = 0; i < n - 1; i++)
                {
                    for (j = 0; j < n - i - 1; j++)
                    {
                        if (arr[j] > arr[j + 1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }

                printf("Array sorted successfully!\n");
                break;

            case 6:
                for (i = 0; i < n / 2; i++)
                {
                    temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
                }

                printf("Array reversed successfully!\n");
                break;

            case 7:
                if (n == 0)
                {
                    printf("Array is empty!\n");
                }
                else
                {
                    max = arr[0];

                    for (i = 1; i < n; i++)
                    {
                        if (arr[i] > max)
                        {
                            max = arr[i];
                        }
                    }

                    printf("Maximum element = %d\n", max);
                }
                break;

            case 8:
                if (n == 0)
                {
                    printf("Array is empty!\n");
                }
                else
                {
                    min = arr[0];

                    for (i = 1; i < n; i++)
                    {
                        if (arr[i] < min)
                        {
                            min = arr[i];
                        }
                    }

                    printf("Minimum element = %d\n", min);
                }
                break;

            case 9:
                sum = 0;

                for (i = 0; i < n; i++)
                {
                    sum = sum + arr[i];
                }

                printf("Sum of array elements = %d\n", sum);
                break;

            case 10:
                printf("Exiting Array Operations System...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 10);

    return 0;
}