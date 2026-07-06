#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str1[200], str2[200], temp[400];
    int choice, i;
    int vowels, result;

    printf("Enter the first string: ");
    scanf(" %[^\n]", str1);

    do
    {
        printf("\n====================================\n");
        printf("    MENU DRIVEN STRING OPERATIONS\n");
        printf("====================================\n");

        printf("1. Display String\n");
        printf("2. Find String Length\n");
        printf("3. Copy String\n");
        printf("4. Concatenate Strings\n");
        printf("5. Compare Strings\n");
        printf("6. Reverse String\n");
        printf("7. Convert to Uppercase\n");
        printf("8. Convert to Lowercase\n");
        printf("9. Count Vowels\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("String = %s\n", str1);
                break;

            case 2:
                printf("Length of string = %d\n",
                       (int)strlen(str1));
                break;

            case 3:
                strcpy(temp, str1);

                printf("Copied string = %s\n", temp);
                break;

            case 4:
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);

                strcpy(temp, str1);
                strcat(temp, str2);

                printf("Concatenated string = %s\n", temp);
                break;

            case 5:
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);

                result = strcmp(str1, str2);

                if (result == 0)
                {
                    printf("Both strings are equal.\n");
                }
                else if (result < 0)
                {
                    printf("First string is smaller.\n");
                }
                else
                {
                    printf("First string is greater.\n");
                }
                break;

            case 6:
                strcpy(temp, str1);

                for (i = 0; i < strlen(temp) / 2; i++)
                {
                    char ch = temp[i];
                    temp[i] = temp[strlen(temp) - i - 1];
                    temp[strlen(temp) - i - 1] = ch;
                }

                printf("Reversed string = %s\n", temp);
                break;

            case 7:
                strcpy(temp, str1);

                for (i = 0; temp[i] != '\0'; i++)
                {
                    temp[i] = toupper(temp[i]);
                }

                printf("Uppercase string = %s\n", temp);
                break;

            case 8:
                strcpy(temp, str1);

                for (i = 0; temp[i] != '\0'; i++)
                {
                    temp[i] = tolower(temp[i]);
                }

                printf("Lowercase string = %s\n", temp);
                break;

            case 9:
                vowels = 0;

                for (i = 0; str1[i] != '\0'; i++)
                {
                    char ch = tolower(str1[i]);

                    if (ch == 'a' || ch == 'e' ||
                        ch == 'i' || ch == 'o' ||
                        ch == 'u')
                    {
                        vowels++;
                    }
                }

                printf("Number of vowels = %d\n", vowels);
                break;

            case 10:
                printf("Exiting String Operations System...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 10);

    return 0;
}