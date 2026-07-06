#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float bonus;
    float tax;
    float grossSalary;
    float netSalary;
};

int main()
{
    struct Employee emp[100];
    int count = 0;
    int choice, i, searchId;
    int found;

    do
    {
        printf("\n===== SALARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee Salary Record\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Employee Salary\n");
        printf("4. Update Employee Salary\n");
        printf("5. Delete Employee Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Employee record is full!\n");
                    break;
                }

                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[count].id);

                printf("Enter Employee Name: ");
                scanf(" %[^\n]", emp[count].name);

                printf("Enter Basic Salary: ");
                scanf("%f", &emp[count].basicSalary);

                // Salary calculations
                emp[count].hra =
                    emp[count].basicSalary * 0.20;

                emp[count].da =
                    emp[count].basicSalary * 0.10;

                emp[count].bonus =
                    emp[count].basicSalary * 0.05;

                emp[count].grossSalary =
                    emp[count].basicSalary +
                    emp[count].hra +
                    emp[count].da +
                    emp[count].bonus;

                emp[count].tax =
                    emp[count].grossSalary * 0.10;

                emp[count].netSalary =
                    emp[count].grossSalary -
                    emp[count].tax;

                count++;

                printf("Salary record added successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No salary records available.\n");
                }
                else
                {
                    printf("\n===== ALL SALARY RECORDS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nEmployee %d\n", i + 1);
                        printf("ID: %d\n", emp[i].id);
                        printf("Name: %s\n", emp[i].name);
                        printf("Basic Salary: %.2f\n",
                               emp[i].basicSalary);
                        printf("HRA: %.2f\n", emp[i].hra);
                        printf("DA: %.2f\n", emp[i].da);
                        printf("Bonus: %.2f\n", emp[i].bonus);
                        printf("Gross Salary: %.2f\n",
                               emp[i].grossSalary);
                        printf("Tax: %.2f\n", emp[i].tax);
                        printf("Net Salary: %.2f\n",
                               emp[i].netSalary);
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
                        printf("\nEmployee Salary Found!\n");
                        printf("ID: %d\n", emp[i].id);
                        printf("Name: %s\n", emp[i].name);
                        printf("Basic Salary: %.2f\n",
                               emp[i].basicSalary);
                        printf("Gross Salary: %.2f\n",
                               emp[i].grossSalary);
                        printf("Tax: %.2f\n", emp[i].tax);
                        printf("Net Salary: %.2f\n",
                               emp[i].netSalary);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee record not found.\n");
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
                        printf("Enter New Basic Salary: ");
                        scanf("%f", &emp[i].basicSalary);

                        // Recalculate salary
                        emp[i].hra =
                            emp[i].basicSalary * 0.20;

                        emp[i].da =
                            emp[i].basicSalary * 0.10;

                        emp[i].bonus =
                            emp[i].basicSalary * 0.05;

                        emp[i].grossSalary =
                            emp[i].basicSalary +
                            emp[i].hra +
                            emp[i].da +
                            emp[i].bonus;

                        emp[i].tax =
                            emp[i].grossSalary * 0.10;

                        emp[i].netSalary =
                            emp[i].grossSalary -
                            emp[i].tax;

                        printf("Salary updated successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee record not found.\n");
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
                        for (int j = i; j < count - 1; j++)
                        {
                            emp[j] = emp[j + 1];
                        }

                        count--;

                        printf("Salary record deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Employee record not found.\n");
                }
                break;

            case 6:
                printf("Exiting Salary Management System...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}