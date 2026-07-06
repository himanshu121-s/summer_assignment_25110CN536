#include <stdio.h>
#include <string.h>

int main()
{
    int bookId[100];
    char bookName[100][50];
    char authorName[100][50];
    int issued[100];

    int count = 0;
    int choice;
    int searchId;
    int found;
    int i;

    do
    {
        printf("\n====================================\n");
        printf("         MINI LIBRARY SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Library is full!\n");
                    break;
                }

                printf("\nEnter Book ID: ");
                scanf("%d", &bookId[count]);

                printf("Enter Book Name: ");
                scanf(" %[^\n]", bookName[count]);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", authorName[count]);

                issued[count] = 0;
                count++;

                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo books available.\n");
                }
                else
                {
                    printf("\n===== ALL BOOKS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nBook %d\n", i + 1);
                        printf("Book ID: %d\n", bookId[i]);
                        printf("Book Name: %s\n", bookName[i]);
                        printf("Author: %s\n", authorName[i]);

                        if (issued[i] == 1)
                        {
                            printf("Status: Issued\n");
                        }
                        else
                        {
                            printf("Status: Available\n");
                        }
                    }
                }
                break;

            case 3:
                printf("\nEnter Book ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (bookId[i] == searchId)
                    {
                        printf("\nBook Found!\n");
                        printf("Book ID: %d\n", bookId[i]);
                        printf("Book Name: %s\n", bookName[i]);
                        printf("Author: %s\n", authorName[i]);

                        if (issued[i] == 1)
                        {
                            printf("Status: Issued\n");
                        }
                        else
                        {
                            printf("Status: Available\n");
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Book not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Book ID to issue: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (bookId[i] == searchId)
                    {
                        found = 1;

                        if (issued[i] == 0)
                        {
                            issued[i] = 1;
                            printf("Book issued successfully!\n");
                        }
                        else
                        {
                            printf("Book is already issued!\n");
                        }

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Book not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Book ID to return: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (bookId[i] == searchId)
                    {
                        found = 1;

                        if (issued[i] == 1)
                        {
                            issued[i] = 0;
                            printf("Book returned successfully!\n");
                        }
                        else
                        {
                            printf("Book is already available!\n");
                        }

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Book not found!\n");
                }
                break;

            case 6:
                printf("\nExiting Mini Library System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}