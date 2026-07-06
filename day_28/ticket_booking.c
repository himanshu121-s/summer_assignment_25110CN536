#include <stdio.h>

struct Ticket
{
    int ticketId;
    char passengerName[50];
    int age;
    char destination[50];
    int seatNo;
};

int main()
{
    struct Ticket tickets[100];

    int count = 0;
    int choice;
    int searchId;
    int found;
    int i, j;

    do
    {
        printf("\n====================================\n");
        printf("        TICKET BOOKING SYSTEM\n");
        printf("====================================\n");

        printf("1. Book Ticket\n");
        printf("2. View All Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Check Available Seats\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (count >= 100)
                {
                    printf("All seats are booked!\n");
                    break;
                }

                printf("\nEnter Ticket ID: ");
                scanf("%d", &tickets[count].ticketId);

                printf("Enter Passenger Name: ");
                scanf(" %[^\n]", tickets[count].passengerName);

                printf("Enter Passenger Age: ");
                scanf("%d", &tickets[count].age);

                printf("Enter Destination: ");
                scanf(" %[^\n]", tickets[count].destination);

                tickets[count].seatNo = count + 1;

                printf("\nTicket booked successfully!\n");
                printf("Your Seat Number is: %d\n",
                       tickets[count].seatNo);

                count++;
                break;

            case 2:
                if (count == 0)
                {
                    printf("\nNo tickets booked.\n");
                }
                else
                {
                    printf("\n===== ALL BOOKED TICKETS =====\n");

                    for (i = 0; i < count; i++)
                    {
                        printf("\nTicket %d\n", i + 1);
                        printf("Ticket ID: %d\n",
                               tickets[i].ticketId);
                        printf("Passenger Name: %s\n",
                               tickets[i].passengerName);
                        printf("Age: %d\n",
                               tickets[i].age);
                        printf("Destination: %s\n",
                               tickets[i].destination);
                        printf("Seat Number: %d\n",
                               tickets[i].seatNo);
                    }
                }
                break;

            case 3:
                printf("\nEnter Ticket ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (tickets[i].ticketId == searchId)
                    {
                        printf("\nTicket Found!\n");
                        printf("Ticket ID: %d\n",
                               tickets[i].ticketId);
                        printf("Passenger Name: %s\n",
                               tickets[i].passengerName);
                        printf("Age: %d\n",
                               tickets[i].age);
                        printf("Destination: %s\n",
                               tickets[i].destination);
                        printf("Seat Number: %d\n",
                               tickets[i].seatNo);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Ticket not found!\n");
                }
                break;

            case 4:
                printf("\nEnter Ticket ID to cancel: ");
                scanf("%d", &searchId);

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (tickets[i].ticketId == searchId)
                    {
                        for (j = i; j < count - 1; j++)
                        {
                            tickets[j] = tickets[j + 1];
                        }

                        count--;

                        printf("Ticket cancelled successfully!\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Ticket not found!\n");
                }
                break;

            case 5:
                printf("\nTotal Seats: 100\n");
                printf("Booked Seats: %d\n", count);
                printf("Available Seats: %d\n", 100 - count);
                break;

            case 6:
                printf("\nExiting Ticket Booking System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}