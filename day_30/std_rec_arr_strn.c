#include <stdio.h>
#include <string.h>

int main()
{
    int rollNo[100];
    char name[100][50];
    float marks[100];

    int count = 0;
    int choice;
    int i, j;
    int searchRoll;
    int found;

    do
    {
        printf("\n====================================\n");
        printf("       STUDENT RECORD SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Student record is full!\n");
                    break;
                }

                printf("\nEnter Roll Number: ");
                scanf("%d", &rollNo[count]);

                printf("Enter Student Name: ");
                scanf(" %[^\n]", name[count]);

                printf("Enter Marks: ");
                scanf("%f", &marks[count]);

                count++;

                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo student records available.\n");
                }
                else
                {
                    printf("\n===== ALL STUDENT RECORDS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nStudent %d\n", i + 1);
                        printf("Roll Number: %d\n", rollNo[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Marks: %.2f\n", marks[i]);
                    }
                }
                break;

            case 3:
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (rollNo[i] == searchRoll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Roll Number: %d\n", rollNo[i]);
                        printf("Name: %s\n", name[i]);
                        printf("Marks: %.2f\n", marks[i]);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Roll Number to update: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (rollNo[i] == searchRoll)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", name[i]);

                        printf("Enter New Marks: ");
                        scanf("%f", &marks[i]);

                        printf("Student updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Roll Number to delete: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (rollNo[i] == searchRoll)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            rollNo[j] = rollNo[j + 1];
                            strcpy(name[j], name[j + 1]);
                            marks[j] = marks[j + 1];
                        }

                        count--;

                        printf("Student deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student not found!\n");
                }
                break;

            case 6:
                printf("\nExiting Student Record System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}