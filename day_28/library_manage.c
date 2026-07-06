#include <stdio.h>

struct Book
{
    int id;
    char title[100];
    char author[100];
    int issued;
};

int main()
{
    struct Book books[100];

    int count = 0;
    int choice;
    int searchId;
    int found;
    int i, j;

    do
    {
        printf("\n====================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");

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
                scanf("%d", &books[count].id);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", books[count].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", books[count].author);

                books[count].issued = 0;

                count++;

                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo books available in library.\n");
                }
                else
                {
                    printf("\n===== ALL BOOK RECORDS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nBook %d\n", i + 1);
                        printf("Book ID: %d\n", books[i].id);
                        printf("Title: %s\n", books[i].title);
                        printf("Author: %s\n", books[i].author);

                        if (books[i].issued == 1)
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
                    if (books[i].id == searchId)
                    {
                        printf("\nBook Found!\n");
                        printf("Book ID: %d\n", books[i].id);
                        printf("Title: %s\n", books[i].title);
                        printf("Author: %s\n", books[i].author);

                        if (books[i].issued == 1)
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
                    if (books[i].id == searchId)
                    {
                        found = 1;

                        if (books[i].issued == 0)
                        {
                            books[i].issued = 1;
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
                    if (books[i].id == searchId)
                    {
                        found = 1;

                        if (books[i].issued == 1)
                        {
                            books[i].issued = 0;
                            printf("Book returned successfully!\n");
                        }
                        else
                        {
                            printf("Book was not issued!\n");
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
                printf("\nEnter Book ID to delete: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (books[i].id == searchId)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            books[j] = books[j + 1];
                        }

                        count--;

                        printf("Book deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Book not found!\n");
                }
                break;

            case 7:
                printf("\nExiting Library Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}