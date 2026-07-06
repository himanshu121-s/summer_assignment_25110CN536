#include <stdio.h>

int main()
{
    int answer;
    int score = 0;

    printf("===== QUIZ APPLICATION =====\n");

    // Question 1
    printf("\n1. What is the capital of India?\n");
    printf("1. Mumbai\n");
    printf("2. New Delhi\n");
    printf("3. Kolkata\n");
    printf("4. Chennai\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is New Delhi.\n");
    }

    // Question 2
    printf("\n2. Which language is used for system programming?\n");
    printf("1. HTML\n");
    printf("2. CSS\n");
    printf("3. C\n");
    printf("4. SQL\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is C.\n");
    }

    // Question 3
    printf("\n3. Who is known as the father of C language?\n");
    printf("1. Dennis Ritchie\n");
    printf("2. James Gosling\n");
    printf("3. Bjarne Stroustrup\n");
    printf("4. Guido van Rossum\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is Dennis Ritchie.\n");
    }

    // Question 4
    printf("\n4. Which symbol is used to end a statement in C?\n");
    printf("1. :\n");
    printf("2. ;\n");
    printf("3. ,\n");
    printf("4. .\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is semicolon (;).\n");
    }

    // Question 5
    printf("\n5. Which loop executes at least once?\n");
    printf("1. for loop\n");
    printf("2. while loop\n");
    printf("3. do-while loop\n");
    printf("4. None\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Wrong! Correct answer is do-while loop.\n");
    }

    // Final Score
    printf("\n===== QUIZ COMPLETED =====\n");
    printf("Your final score is: %d out of 5\n", score);

    if (score == 5)
    {
        printf("Excellent performance!\n");
    }
    else if (score >= 3)
    {
        printf("Good job!\n");
    }
    else
    {
        printf("Keep practicing!\n");
    }

    return 0;
}