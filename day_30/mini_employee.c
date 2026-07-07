#include <stdio.h>
#include <string.h>

#define MAX 100

int empId[MAX];
char empName[MAX][50];
char department[MAX][50];
float salary[MAX];

int empCount = 0;

// Function to add employee
void addEmployee() {
    if (empCount >= MAX) {
        printf("\nEmployee storage is full!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &empId[empCount]);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", empName[empCount]);

    printf("Enter Department: ");
    scanf(" %[^\n]", department[empCount]);

    printf("Enter Salary: ");
    scanf("%f", &salary[empCount]);

    empCount++;

    printf("\nEmployee added successfully!\n");
}

// Function to display all employees
void displayEmployees() {
    int i;

    if (empCount == 0) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n========== EMPLOYEE RECORDS ==========\n");

    for (i = 0; i < empCount; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID : %d\n", empId[i]);
        printf("Name        : %s\n", empName[i]);
        printf("Department  : %s\n", department[i]);
        printf("Salary      : %.2f\n", salary[i]);
    }
}

// Function to search employee
void searchEmployee() {
    int id, i;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < empCount; i++) {
        if (empId[i] == id) {
            printf("\nEmployee Found!\n");
            printf("Employee ID : %d\n", empId[i]);
            printf("Name        : %s\n", empName[i]);
            printf("Department  : %s\n", department[i]);
            printf("Salary      : %.2f\n", salary[i]);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found!\n");
    }
}

// Function to update employee
void updateEmployee() {
    int id, i;
    int found = 0;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < empCount; i++) {
        if (empId[i] == id) {
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", empName[i]);

            printf("Enter New Department: ");
            scanf(" %[^\n]", department[i]);

            printf("Enter New Salary: ");
            scanf("%f", &salary[i]);

            printf("\nEmployee record updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found!\n");
    }
}

// Function to delete employee
void deleteEmployee() {
    int id, i, j;
    int found = 0;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < empCount; i++) {
        if (empId[i] == id) {
            found = 1;

            // Shift all records one position left
            for (j = i; j < empCount - 1; j++) {
                empId[j] = empId[j + 1];
                strcpy(empName[j], empName[j + 1]);
                strcpy(department[j], department[j + 1]);
                salary[j] = salary[j + 1];
            }

            empCount--;

            printf("\nEmployee deleted successfully!\n");
            break;
        }
    }

    if (found == 0) {
        printf("\nEmployee not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== EMPLOYEE MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                printf("\nExiting Employee Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}