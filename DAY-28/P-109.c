#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued; 
};

void clear_system_buffer() {
    while (getchar() != '\n');
}

void trim_string(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Book inventory[100];
    int book_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    LIBRARY MANAGEMENT SYSTEM     \n");
        printf("==================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_system_buffer(); 
            continue;
        }
        clear_system_buffer(); 

        switch (choice) {
            case 1:
                if (book_count >= 100) {
                    printf("\nError: Library catalog storage capacity full!\n");
                } else {
                    printf("\nEnter Unique Book ID (Integer): ");
                    if (scanf("%d", &inventory[book_count].id) != 1) {
                        printf("Invalid format! Registration canceled.\n");
                        clear_system_buffer();
                        break;
                    }
                    clear_system_buffer();

                    int duplicate = 0;
                    for (int i = 0; i < book_count; i++) {
                        if (inventory[i].id == inventory[book_count].id) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: A book with ID %d already exists in the catalog.\n", inventory[book_count].id);
                        break;
                    }

                    printf("Enter Book Title: ");
                    fgets(inventory[book_count].title, sizeof(inventory[book_count].title), stdin);
                    trim_string(inventory[book_count].title);

                    printf("Enter Author Name: ");
                    fgets(inventory[book_count].author, sizeof(inventory[book_count].author), stdin);
                    trim_string(inventory[book_count].author);

                    inventory[book_count].is_issued = 0; 

                    book_count++;
                    printf("\nSuccess: Book registered to library catalog!\n");
                }
                break;

            case 2:
                if (book_count == 0) {
                    printf("\nThe library inventory is currently empty.\n");
                } else {
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("%-10s %-30s %-25s %-12s\n", "ID", "Book Title", "Author", "Availability");
                    printf("--------------------------------------------------------------------------------\n");
                    for (int i = 0; i < book_count; i++) {
                        printf("%-10d %-30s %-25s %-12s\n", 
                               inventory[i].id, 
                               inventory[i].title, 
                               inventory[i].author, 
                               (inventory[i].is_issued == 1) ? "Checked Out" : "In Library");
                    }
                    printf("--------------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (book_count == 0) {
                    printf("\nNo books exist in the collection to check out.\n");
                } else {
                    int target_id, found_index = -1;
                    printf("\nEnter Book ID to issue: ");
                    if (scanf("%d", &target_id) != 1) {
                        printf("Invalid numeric format.\n");
                        clear_system_buffer();
                        break;
                    }

                    for (int i = 0; i < book_count; i++) {
                        if (inventory[i].id == target_id) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Book ID %d not found in active catalog.\n", target_id);
                    } else if (inventory[found_index].is_issued == 1) {
                        printf("Transaction Blocked: Book is already checked out by another patron.\n");
                    } else {
                        inventory[found_index].is_issued = 1;
                        printf("Success: Book \"%s\" is now marked as checked out.\n", inventory[found_index].title);
                    }
                }
                break;

            case 4:
                if (book_count == 0) {
                    printf("\nNo books exist in the collection database.\n");
                } else {
                    int target_id, found_index = -1;
                    printf("\nEnter Book ID to return: ");
                    if (scanf("%d", &target_id) != 1) {
                        printf("Invalid numeric format.\n");
                        clear_system_buffer();
                        break;
                    }

                    for (int i = 0; i < book_count; i++) {
                        if (inventory[i].id == target_id) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Book ID %d not found in active catalog.\n", target_id);
                    } else if (inventory[found_index].is_issued == 0) {
                        printf("Transaction Canceled: Book is already sitting inside the library shelf.\n");
                    } else {
                        inventory[found_index].is_issued = 0;
                        printf("Success: Book \"%s\" has been safely returned to the shelves.\n", inventory[found_index].title);
                    }
                }
                break;

            case 5:
                printf("\nExiting Library Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option selection! Choose between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}