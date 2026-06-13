#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = 0; i < rows; i++) {
        // Print spaces
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Ascending characters
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            printf("%c", ch);
        }

        // Descending characters
        for (char ch = 'A' + i - 1; ch >= 'A'; ch--) {
            printf("%c", ch);
        }

        printf("\n");
    }

    return 0;
}