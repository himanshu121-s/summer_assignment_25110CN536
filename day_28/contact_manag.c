#include <stdio.h>

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

int main()
{
    struct Contact contacts[100];

    int count = 0;
    int choice;
    int i, j;
    int found;
    char searchName[50];

    do
    {
        printf("\n====================================\n");
        printf("      CONTACT MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Contact list is full!\n");
                    break;
                }

                printf("\nEnter Name: ");
                scanf(" %[^\n]", contacts[count].name);

                printf("Enter Phone Number: ");
                scanf("%s", contacts[count].phone);

                printf("Enter Email: ");
                scanf("%s", contacts[count].email);

                count++;

                printf("Contact added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo contacts available.\n");
                }
                else
                {
                    printf("\n===== ALL CONTACTS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nContact %d\n", i + 1);
                        printf("Name: %s\n",
                               contacts[i].name);
                        printf("Phone: %s\n",
                               contacts[i].phone);
                        printf("Email: %s\n",
                               contacts[i].email);
                    }
                }
                break;

            case 3:
                printf("\nEnter Name to search: ");
                scanf(" %[^\n]", searchName);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    int match = 1;

                    for (j = 0;
                         contacts[i].name[j] != '\0' ||
                         searchName[j] != '\0';
                         j++)
                    {
                        if (contacts[i].name[j] != searchName[j])
                        {
                            match = 0;
                            break;
                        }
                    }

                    if (match == 1)
                    {
                        printf("\nContact Found!\n");
                        printf("Name: %s\n",
                               contacts[i].name);
                        printf("Phone: %s\n",
                               contacts[i].phone);
                        printf("Email: %s\n",
                               contacts[i].email);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Contact not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Name to update: ");
                scanf(" %[^\n]", searchName);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    int match = 1;

                    for (j = 0;
                         contacts[i].name[j] != '\0' ||
                         searchName[j] != '\0';
                         j++)
                    {
                        if (contacts[i].name[j] != searchName[j])
                        {
                            match = 0;
                            break;
                        }
                    }

                    if (match == 1)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", contacts[i].name);

                        printf("Enter New Phone Number: ");
                        scanf("%s", contacts[i].phone);

                        printf("Enter New Email: ");
                        scanf("%s", contacts[i].email);

                        printf("Contact updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Contact not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Name to delete: ");
                scanf(" %[^\n]", searchName);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    int match = 1;

                    for (j = 0;
                         contacts[i].name[j] != '\0' ||
                         searchName[j] != '\0';
                         j++)
                    {
                        if (contacts[i].name[j] != searchName[j])
                        {
                            match = 0;
                            break;
                        }
                    }

                    if (match == 1)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            contacts[j] = contacts[j + 1];
                        }

                        count--;

                        printf("Contact deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Contact not found!\n");
                }
                break;

            case 6:
                printf("\nExiting Contact Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}