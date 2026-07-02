#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int i, j, len1, len2, temp;
    int anagram = 1;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if(len1 != len2) {
        printf("Strings are not anagrams.");
        return 0;
    }

    // Sort first string
    for(i = 0; i < len1 - 1; i++) {
        for(j = i + 1; j < len1; j++) {
            if(str1[i] > str1[j]) {
                temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }

    // Sort second string
    for(i = 0; i < len2 - 1; i++) {
        for(j = i + 1; j < len2; j++) {
            if(str2[i] > str2[j]) {
                temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    // Compare sorted strings
    for(i = 0; i < len1; i++) {
        if(str1[i] != str2[i]) {
            anagram = 0;
            break;
        }
    }

    if(anagram)
        printf("Strings are anagrams.");
    else
        printf("Strings are not anagrams.");

    return 0;
}