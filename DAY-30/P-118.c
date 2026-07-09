#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; 
};

int main() {
    struct Book library[100];
    int book_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("       MINI LIBRARY SYSTEM        \n");
        printf("==================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a valid menu number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                if (book_count >= 100) {
                    printf("\nLibrary database is full!\n");
                } else {
                    printf("\nEnter Book ID (Integer): ");
                    if (scanf("%d", &library[book_count].id) != 1) {
                        printf("Invalid input! Operation canceled.\n");
                        while (getchar() != '\n');
                        break;
                    }
                    while (getchar() != '\n'); 

                    printf("Enter Book Title: ");
                    fgets(library[book_count].title, sizeof(library[book_count].title), stdin);
                    int len = 0;
                    while (library[book_count].title[len] != '\0') len++;
                    if (len > 0 && library[book_count].title[len - 1] == '\n') {
                        library[book_count].title[len - 1] = '\0';
                    }

                    printf("Enter Author Name: ");
                    fgets(library[book_count].author, sizeof(library[book_count].author), stdin);
                    len = 0;
                    while (library[book_count].author[len] != '\0') len++;
                    if (len > 0 && library[book_count].author[len - 1] == '\n') {
                        library[book_count].author[len - 1] = '\0';
                    }

                    library[book_count].is_issued = 0; 
                    book_count++;
                    printf("\nBook added successfully!\n");
                }
                break;

            case 2:
                if (book_count == 0) {
                    printf("\nThe library has no books right now.\n");
                } else {
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("%-10s %-30s %-25s %-10s\n", "Book ID", "Title", "Author", "Status");
                    printf("----------------------------------------------------------------------------\n");
                    for (int i = 0; i < book_count; i++) {
                        printf("%-10d %-30s %-25s %-10s\n", 
                               library[i].id, 
                               library[i].title, 
                               library[i].author, 
                               (library[i].is_issued == 1) ? "Issued" : "Available");
                    }
                    printf("----------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (book_count == 0) {
                    printf("\nNo books available in the library.\n");
                } else {
                    int issue_id;
                    int found = 0;
                    printf("\nEnter Book ID to issue: ");
                    if (scanf("%d", &issue_id) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                        break;
                    }

                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == issue_id) {
                            found = 1;
                            if (library[i].is_issued == 1) {
                                printf("\nSorry, this book is already issued to someone else.\n");
                            } else {
                                library[i].is_issued = 1;
                                printf("\nSuccess! Book '%s' has been issued.\n", library[i].title);
                            }
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nBook ID %d not found in the system.\n", issue_id);
                    }
                }
                break;

            case 4:
                if (book_count == 0) {
                    printf("\nNo books registered in this library system.\n");
                } else {
                    int return_id;
                    int found = 0;
                    printf("\nEnter Book ID to return: ");
                    if (scanf("%d", &return_id) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                        break;
                    }

                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == return_id) {
                            found = 1;
                            if (library[i].is_issued == 0) {
                                printf("\nThis book is already sitting in the library catalog.\n");
                            } else {
                                library[i].is_issued = 0;
                                printf("\nSuccess! Book '%s' has been returned to the shelves.\n", library[i].title);
                            }
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nBook ID %d not found in the system.\n", return_id);
                    }
                }
                break;

            case 5:
                printf("\nExiting Library System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please pick a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}