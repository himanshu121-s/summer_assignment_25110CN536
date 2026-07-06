#include <stdio.h>

int main()
{
    char name[50];
    int rollNo;
    float english, maths, science, computer, hindi;
    float total, percentage;

    printf("===== MARKSHEET GENERATION SYSTEM =====\n");

    // Input student details
    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);

    // Input subject marks
    printf("\nEnter English Marks: ");
    scanf("%f", &english);

    printf("Enter Maths Marks: ");
    scanf("%f", &maths);

    printf("Enter Science Marks: ");
    scanf("%f", &science);

    printf("Enter Computer Marks: ");
    scanf("%f", &computer);

    printf("Enter Hindi Marks: ");
    scanf("%f", &hindi);

    // Calculate total and percentage
    total = english + maths + science + computer + hindi;
    percentage = total / 5;

    // Display Marksheet
    printf("\n=====================================\n");
    printf("          STUDENT MARKSHEET\n");
    printf("=====================================\n");

    printf("Student Name : %s\n", name);
    printf("Roll Number  : %d\n", rollNo);

    printf("-------------------------------------\n");
    printf("Subject              Marks\n");
    printf("-------------------------------------\n");

    printf("English              %.2f\n", english);
    printf("Maths                %.2f\n", maths);
    printf("Science              %.2f\n", science);
    printf("Computer             %.2f\n", computer);
    printf("Hindi                %.2f\n", hindi);

    printf("-------------------------------------\n");
    printf("Total Marks          %.2f / 500\n", total);
    printf("Percentage           %.2f%%\n", percentage);

    // Check Pass or Fail
    if (english < 33 || maths < 33 || science < 33 ||
        computer < 33 || hindi < 33)
    {
        printf("Result               FAIL\n");
        printf("Grade                F\n");
    }
    else
    {
        printf("Result               PASS\n");

        // Grade calculation
        if (percentage >= 90)
        {
            printf("Grade                A+\n");
        }
        else if (percentage >= 80)
        {
            printf("Grade                A\n");
        }
        else if (percentage >= 70)
        {
            printf("Grade                B+\n");
        }
        else if (percentage >= 60)
        {
            printf("Grade                B\n");
        }
        else if (percentage >= 50)
        {
            printf("Grade                C\n");
        }
        else if (percentage >= 40)
        {
            printf("Grade                D\n");
        }
        else
        {
            printf("Grade                E\n");
        }
    }

    printf("=====================================\n");

    return 0;
}