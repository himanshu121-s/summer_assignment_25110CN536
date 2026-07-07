#include <stdio.h>

int main() {
    int arr[100], n, i, choice;
    int sum, max, min, key, found;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    do {
        printf("\n===== MENU DRIVEN ARRAY OPERATIONS =====\n");
        printf("1. Input Array\n");
        printf("2. Display Array\n");
        printf("3. Find Sum of Elements\n");
        printf("4. Find Maximum Element\n");
        printf("5. Find Minimum Element\n");
        printf("6. Search an Element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter %d elements:\n", n);
                for(i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Array inserted successfully.\n");
                break;

            case 2:
                printf("Array Elements are:\n");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                sum = 0;
                for(i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Sum of elements = %d\n", sum);
                break;

            case 4:
                max = arr[0];
                for(i = 1; i < n; i++) {
                    if(arr[i] > max)
                        max = arr[i];
                }
                printf("Maximum element = %d\n", max);
                break;

            case 5:
                min = arr[0];
                for(i = 1; i < n; i++) {
                    if(arr[i] < min)
                        min = arr[i];
                }
                printf("Minimum element = %d\n", min);
                break;

            case 6:
                printf("Enter element to search: ");
                scanf("%d", &key);
                found = 0;

                for(i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Element not found.\n");
                break;

            case 7:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice! Please try again.\n");
        }

    } while(choice != 7);

    return 0;
}