#include <stdio.h>
#include <string.h>

int main()
{
    int empId[100];
    char empName[100][50];
    float salary[100];

    int count = 0;
    int choice;
    int searchId;
    int found;
    int i, j;

    do
    {
        printf("\n====================================\n");
        printf("   MINI EMPLOYEE MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
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
                scanf("%d", &empId[count]);

                printf("Enter Employee Name: ");
                scanf(" %[^\n]", empName[count]);

                printf("Enter Employee Salary: ");
                scanf("%f", &salary[count]);

                count++;

                printf("Employee added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo employee records available.\n");
                }
                else
                {
                    printf("\n===== ALL EMPLOYEES =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("Employee ID: %d\n", empId[i]);
                        printf("Name: %s\n", empName[i]);
                        printf("Salary: %.2f\n", salary[i]);
                    }
                }
                break;

            case 3:
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (empId[i] == searchId)
                    {
                        printf("\nEmployee Found!\n");
                        printf("Employee ID: %d\n", empId[i]);
                        printf("Name: %s\n", empName[i]);
                        printf("Salary: %.2f\n", salary[i]);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Employee ID to update: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (empId[i] == searchId)
                    {
                        printf("Enter New Employee Name: ");
                        scanf(" %[^\n]", empName[i]);

                        printf("Enter New Salary: ");
                        scanf("%f", &salary[i]);

                        printf("Employee updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Employee ID to delete: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (empId[i] == searchId)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            empId[j] = empId[j + 1];
                            strcpy(empName[j], empName[j + 1]);
                            salary[j] = salary[j + 1];
                        }

                        count--;

                        printf("Employee deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee not found!\n");
                }
                break;

            case 6:
                printf("\nExiting Mini Employee Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}