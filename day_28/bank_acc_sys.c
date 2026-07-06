#include <stdio.h>

struct Account
{
    int accountNo;
    char name[50];
    float balance;
};

int main()
{
    struct Account acc[100];

    int count = 0;
    int choice;
    int searchAcc;
    int found;
    int i, j;
    float amount;

    do
    {
        printf("\n====================================\n");
        printf("        BANK ACCOUNT SYSTEM\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("Account limit reached!\n");
                    break;
                }

                printf("\nEnter Account Number: ");
                scanf("%d", &acc[count].accountNo);

                printf("Enter Account Holder Name: ");
                scanf(" %[^\n]", acc[count].name);

                printf("Enter Initial Balance: ");
                scanf("%f", &acc[count].balance);

                count++;

                printf("Account created successfully!\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo accounts available.\n");
                }
                else
                {
                    printf("\n===== ALL BANK ACCOUNTS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nAccount %d\n", i + 1);
                        printf("Account Number: %d\n",
                               acc[i].accountNo);
                        printf("Account Holder: %s\n",
                               acc[i].name);
                        printf("Balance: %.2f\n",
                               acc[i].balance);
                    }
                }
                break;

            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &searchAcc);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (acc[i].accountNo == searchAcc)
                    {
                        printf("Enter amount to deposit: ");
                        scanf("%f", &amount);

                        if (amount > 0)
                        {
                            acc[i].balance += amount;

                            printf("Money deposited successfully!\n");
                            printf("New Balance: %.2f\n",
                                   acc[i].balance);
                        }
                        else
                        {
                            printf("Invalid amount!\n");
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Account Number: ");
                scanf("%d", &searchAcc);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (acc[i].accountNo == searchAcc)
                    {
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &amount);

                        if (amount <= 0)
                        {
                            printf("Invalid amount!\n");
                        }
                        else if (amount > acc[i].balance)
                        {
                            printf("Insufficient balance!\n");
                        }
                        else
                        {
                            acc[i].balance -= amount;

                            printf("Money withdrawn successfully!\n");
                            printf("Remaining Balance: %.2f\n",
                                   acc[i].balance);
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account not found!\n");
                }
                break;

            case 5:
                printf("\nEnter Account Number to search: ");
                scanf("%d", &searchAcc);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (acc[i].accountNo == searchAcc)
                    {
                        printf("\nAccount Found!\n");
                        printf("Account Number: %d\n",
                               acc[i].accountNo);
                        printf("Account Holder: %s\n",
                               acc[i].name);
                        printf("Balance: %.2f\n",
                               acc[i].balance);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account not found!\n");
                }
                break;

            case 6:
                printf("\nEnter Account Number to delete: ");
                scanf("%d", &searchAcc);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (acc[i].accountNo == searchAcc)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            acc[j] = acc[j + 1];
                        }

                        count--;

                        printf("Account deleted successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account not found!\n");
                }
                break;

            case 7:
                printf("\nExiting Bank Account System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}