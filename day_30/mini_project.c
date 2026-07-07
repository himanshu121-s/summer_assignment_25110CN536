#include <stdio.h>
#include <string.h>

#define MAX 100

// Arrays to store student data
int rollNo[MAX];
char name[MAX][50];
char course[MAX][30];
float marks[MAX];

int studentCount = 0;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortStudents();
void findTopper();
void calculateAverage();

// Function to add a student
void addStudent() {
    if (studentCount >= MAX) {
        printf("\nStudent storage is full!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &rollNo[studentCount]);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name[studentCount]);

    printf("Enter Course Name: ");
    scanf(" %[^\n]", course[studentCount]);

    printf("Enter Marks: ");
    scanf("%f", &marks[studentCount]);

    studentCount++;

    printf("\nStudent added successfully!\n");
}

// Function to display all students
void displayStudents() {
    int i;

    if (studentCount == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (i = 0; i < studentCount; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", rollNo[i]);
        printf("Name        : %s\n", name[i]);
        printf("Course      : %s\n", course[i]);
        printf("Marks       : %.2f\n", marks[i]);
    }
}

// Function to search student
void searchStudent() {
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++) {
        if (rollNo[i] == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", rollNo[i]);
            printf("Name        : %s\n", name[i]);
            printf("Course      : %s\n", course[i]);
            printf("Marks       : %.2f\n", marks[i]);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found!\n");
    }
}

// Function to update student
void updateStudent() {
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++) {
        if (rollNo[i] == roll) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", name[i]);

            printf("Enter New Course: ");
            scanf(" %[^\n]", course[i]);

            printf("Enter New Marks: ");
            scanf("%f", &marks[i]);

            printf("\nStudent record updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found!\n");
    }
}

// Function to delete student
void deleteStudent() {
    int roll, i, j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++) {

        if (rollNo[i] == roll) {
            found = 1;

            // Shift records to left
            for (j = i; j < studentCount - 1; j++) {
                rollNo[j] = rollNo[j + 1];
                strcpy(name[j], name[j + 1]);
                strcpy(course[j], course[j + 1]);
                marks[j] = marks[j + 1];
            }

            studentCount--;

            printf("\nStudent deleted successfully!\n");
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found!\n");
    }
}

// Function to sort students by marks
void sortStudents() {
    int i, j;
    int tempRoll;
    float tempMarks;
    char tempName[50];
    char tempCourse[30];

    if (studentCount == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    for (i = 0; i < studentCount - 1; i++) {
        for (j = 0; j < studentCount - i - 1; j++) {

            if (marks[j] < marks[j + 1]) {

                // Swap marks
                tempMarks = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = tempMarks;

                // Swap roll numbers
                tempRoll = rollNo[j];
                rollNo[j] = rollNo[j + 1];
                rollNo[j + 1] = tempRoll;

                // Swap names
                strcpy(tempName, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tempName);

                // Swap courses
                strcpy(tempCourse, course[j]);
                strcpy(course[j], course[j + 1]);
                strcpy(course[j + 1], tempCourse);
            }
        }
    }

    printf("\nStudents sorted by marks successfully!\n");
}

// Function to find topper
void findTopper() {
    int i, topIndex = 0;

    if (studentCount == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    for (i = 1; i < studentCount; i++) {
        if (marks[i] > marks[topIndex]) {
            topIndex = i;
        }
    }

    printf("\n========== TOPPER DETAILS ==========\n");
    printf("Roll Number : %d\n", rollNo[topIndex]);
    printf("Name        : %s\n", name[topIndex]);
    printf("Course      : %s\n", course[topIndex]);
    printf("Marks       : %.2f\n", marks[topIndex]);
}

// Function to calculate average marks
void calculateAverage() {
    int i;
    float sum = 0, average;

    if (studentCount == 0) {
        printf("\nNo student records available!\n");
        return;
    }

    for (i = 0; i < studentCount; i++) {
        sum = sum + marks[i];
    }

    average = sum / studentCount;

    printf("\nAverage Marks = %.2f\n", average);
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Marks\n");
        printf("7. Find Topper\n");
        printf("8. Calculate Average Marks\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

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
                sortStudents();
                break;

            case 7:
                findTopper();
                break;

            case 8:
                calculateAverage();
                break;

            case 9:
                printf("\nThank you for using the system!\n");
                printf("Program terminated successfully.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}