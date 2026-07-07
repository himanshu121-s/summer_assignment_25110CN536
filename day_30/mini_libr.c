#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Arrays to store book details
int bookId[MAX_BOOKS];
char bookName[MAX_BOOKS][50];
char authorName[MAX_BOOKS][50];
int available[MAX_BOOKS];

int bookCount = 0;

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &bookId[bookCount]);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", bookName[bookCount]);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", authorName[bookCount]);

    available[bookCount] = 1;

    bookCount++;

    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks() {
    int i;

    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n========== BOOK LIST ==========\n");

    for (i = 0; i < bookCount; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Book ID     : %d\n", bookId[i]);
        printf("Book Name   : %s\n", bookName[i]);
        printf("Author Name : %s\n", authorName[i]);

        if (available[i] == 1)
            printf("Status      : Available\n");
        else
            printf("Status      : Issued\n");
    }
}

// Function to search for a book
void searchBook() {
    int id, i;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (bookId[i] == id) {
            printf("\nBook Found!\n");
            printf("Book ID     : %d\n", bookId[i]);
            printf("Book Name   : %s\n", bookName[i]);
            printf("Author Name : %s\n", authorName[i]);

            if (available[i] == 1)
                printf("Status      : Available\n");
            else
                printf("Status      : Issued\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nBook not found!\n");
    }
}

// Function to issue a book
void issueBook() {
    int id, i;
    int found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (bookId[i] == id) {
            found = 1;

            if (available[i] == 1) {
                available[i] = 0;
                printf("\nBook issued successfully!\n");
            } else {
                printf("\nBook is already issued!\n");
            }

            break;
        }
    }

    if (found == 0) {
        printf("\nBook not found!\n");
    }
}

// Function to return a book
void returnBook() {
    int id, i;
    int found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < bookCount; i++) {
        if (bookId[i] == id) {
            found = 1;

            if (available[i] == 0) {
                available[i] = 1;
                printf("\nBook returned successfully!\n");
            } else {
                printf("\nBook is already available!\n");
            }

            break;
        }
    }

    if (found == 0) {
        printf("\nBook not found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n========== MINI LIBRARY SYSTEM ==========\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("\nExiting Library System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}