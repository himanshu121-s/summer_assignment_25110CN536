#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, i, j, k;

    printf("Enter the number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter the sorted elements of first array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter the sorted elements of second array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;
    k = 0;

    // Merge the two sorted arrays
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of first array
    while(i < n1) {
        c[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of second array
    while(j < n2) {
        c[k] = b[j];
        j++;
        k++;
    }

    printf("Merged sorted array:\n");
    for(i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}