#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main()
{
    struct Student students[100];
    int count = 0;
    int choice, i, searchRoll;
    int found;

    do
    {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Roll Number: ");
                scanf("%d", &students[count].rollNo);

                printf("Enter Name: ");
                scanf(" %[^\n]", students[count].name);

                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);

                count++;

                printf("Student record added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No student records available.\n");
                }
                else
                {
                    printf("\n===== ALL STUDENT RECORDS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nStudent %d\n", i + 1);
                        printf("Roll Number: %d\n", students[i].rollNo);
                        printf("Name: %s\n", students[i].name);
                        printf("Marks: %.2f\n", students[i].marks);
                    }
                }
                break;

            case 3:
                printf("Enter Roll Number to search: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollNo == searchRoll)
                    {
                        printf("\nStudent Found!\n");
                        printf("Roll Number: %d\n", students[i].rollNo);
                        printf("Name: %s\n", students[i].name);
                        printf("Marks: %.2f\n", students[i].marks);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student record not found.\n");
                }
                break;

            case 4:
                printf("Enter Roll Number to update: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollNo == searchRoll)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", students[i].name);

                        printf("Enter New Marks: ");
                        scanf("%f", &students[i].marks);

                        printf("Student record updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student record not found.\n");
                }
                break;

            case 5:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &searchRoll);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (students[i].rollNo == searchRoll)
                    {
                        for (int j = i; j < count - 1; j++)
                        {
                            students[j] = students[j + 1];
                        }

                        count--;

                        printf("Student record deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student record not found.\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}