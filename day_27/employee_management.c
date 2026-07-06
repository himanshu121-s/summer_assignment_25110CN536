#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int count = 0;
    int choice, i, j;
    int searchId;
    int found;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Employee list is full!\n");
                    break;
                }

                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[count].id);

                printf("Enter Employee Name: ");
                scanf(" %[^\n]", emp[count].name);

                printf("Enter Employee Salary: ");
                scanf("%f", &emp[count].salary);

                count++;

                printf("Employee added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No employee records available.\n");
                }
                else
                {
                    printf("\n===== ALL EMPLOYEE RECORDS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("ID: %d\n", emp[i].id);
                        printf("Name: %s\n", emp[i].name);
                        printf("Salary: %.2f\n", emp[i].salary);
                    }
                }
                break;

            case 3:
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (emp[i].id == searchId)
                    {
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", emp[i].id);
                        printf("Name: %s\n", emp[i].name);
                        printf("Salary: %.2f\n", emp[i].salary);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found.\n");
                }
                break;

            case 4:
                printf("\nEnter Employee ID to update: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (emp[i].id == searchId)
                    {
                        printf("Enter New Name: ");
                        scanf(" %[^\n]", emp[i].name);

                        printf("Enter New Salary: ");
                        scanf("%f", &emp[i].salary);

                        printf("Employee updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                printf("\nEnter Employee ID to delete: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (emp[i].id == searchId)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            emp[j] = emp[j + 1];
                        }

                        count--;

                        printf("Employee deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found.\n");
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