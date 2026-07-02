#include <stdio.h>

int main() {
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Find string length without strlen()
    while(str[i] != '\0') {
        i++;
    }

    printf("Length of the string = %d", i);

    return 0;
}