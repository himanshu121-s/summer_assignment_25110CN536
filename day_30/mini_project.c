#include <stdio.h>
#include <string.h>

#define MAX 100

// Global arrays
int rollNo[MAX];
char name[MAX][50];
float marks[MAX];
int count = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void showResult();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("     STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Show Student Result\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                showResult();
                break;

            case 7:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 7);

    return 0;
}


// Function to add student
void addStudent()
{
    if (count >= MAX)
    {
        printf("\nStudent record is full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNo[count]);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Marks: ");
    scanf("%f", &marks[count]);

    count++;

    printf("\nStudent added successfully!\n");
}


// Function to display all students
void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n====================================\n");
    printf("        ALL STUDENT RECORDS\n");
    printf("====================================\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", rollNo[i]);
        printf("Name        : %s\n", name[i]);
        printf("Marks       : %.2f\n", marks[i]);
    }
}


// Function to search student
void searchStudent()
{
    int searchRoll;
    int i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (i = 0; i < count; i++)
    {
        if (rollNo[i] == searchRoll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", rollNo[i]);
            printf("Name        : %s\n", name[i]);
            printf("Marks       : %.2f\n", marks[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}


// Function to update student
void updateStudent()
{
    int searchRoll;
    int i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &searchRoll);

    for (i = 0; i < count; i++)
    {
        if (rollNo[i] == searchRoll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", name[i]);

            printf("Enter New Marks: ");
            scanf("%f", &marks[i]);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}


// Function to delete student
void deleteStudent()
{
    int searchRoll;
    int i, j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &searchRoll);

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

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}


// Function to show student result
void showResult()
{
    int searchRoll;
    int i;
    int found = 0;

    printf("\nEnter Roll Number: ");
    scanf("%d", &searchRoll);

    for (i = 0; i < count; i++)
    {
        if (rollNo[i] == searchRoll)
        {
            printf("\n====================================\n");
            printf("          STUDENT RESULT\n");
            printf("====================================\n");

            printf("Roll Number : %d\n", rollNo[i]);
            printf("Name        : %s\n", name[i]);
            printf("Marks       : %.2f\n", marks[i]);

            if (marks[i] >= 90)
            {
                printf("Grade       : A+\n");
            }
            else if (marks[i] >= 80)
            {
                printf("Grade       : A\n");
            }
            else if (marks[i] >= 70)
            {
                printf("Grade       : B\n");
            }
            else if (marks[i] >= 60)
            {
                printf("Grade       : C\n");
            }
            else if (marks[i] >= 50)
            {
                printf("Grade       : D\n");
            }
            else if (marks[i] >= 33)
            {
                printf("Grade       : E\n");
            }
            else
            {
                printf("Grade       : F\n");
            }

            if (marks[i] >= 33)
            {
                printf("Result      : PASS\n");
            }
            else
            {
                printf("Result      : FAIL\n");
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}