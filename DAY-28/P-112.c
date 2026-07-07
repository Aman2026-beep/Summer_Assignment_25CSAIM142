#include <stdio.h>
#include <string.h>

struct Contact {
    char name[100];
    char phone[20];
    char email[100];
};

void clear_buffer() {
    while (getchar() != '\n');
}

void remove_newline_char(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Contact phonebook[100];
    int contact_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    CONTACT MANAGEMENT SYSTEM     \n");
        printf("==================================\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_buffer(); 
            continue;
        }
        clear_buffer(); 

        switch (choice) {
            case 1:
                if (contact_count >= 100) {
                    printf("\nError: Phonebook storage limit reached!\n");
                } else {
                    printf("\nEnter Full Name: ");
                    fgets(phonebook[contact_count].name, sizeof(phonebook[contact_count].name), stdin);
                    remove_newline_char(phonebook[contact_count].name);

                    int duplicate = 0;
                    for (int i = 0; i < contact_count; i++) {
                        if (strcasecmp(phonebook[i].name, phonebook[contact_count].name) == 0) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: A contact named \"%s\" already exists.\n", phonebook[contact_count].name);
                        break;
                    }

                    printf("Enter Phone Number: ");
                    fgets(phonebook[contact_count].phone, sizeof(phonebook[contact_count].phone), stdin);
                    remove_newline_char(phonebook[contact_count].phone);

                    printf("Enter Email Address: ");
                    fgets(phonebook[contact_count].email, sizeof(phonebook[contact_count].email), stdin);
                    remove_newline_char(phonebook[contact_count].email);

                    contact_count++;
                    printf("\nSuccess: Contact added successfully!\n");
                }
                break;

            case 2:
                if (contact_count == 0) {
                    printf("\nYour phonebook directory is currently empty.\n");
                } else {
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf("%-25s %-20s %-30s\n", "Name", "Phone Number", "Email Address");
                    printf("--------------------------------------------------------------------------------\n");
                    for (int i = 0; i < contact_count; i++) {
                        printf("%-25s %-20s %-30s\n", 
                               phonebook[i].name, 
                               phonebook[i].phone, 
                               phonebook[i].email);
                    }
                    printf("--------------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (contact_count == 0) {
                    printf("\nNo contacts exist to search.\n");
                } else {
                    char search_name[100];
                    int found = 0;
                    
                    printf("\nEnter Name to search: ");
                    fgets(search_name, sizeof(search_name), stdin);
                    remove_newline_char(search_name);

                    for (int i = 0; i < contact_count; i++) {
                        if (strcasecmp(phonebook[i].name, search_name) == 0) {
                            if (!found) {
                                printf("\nContact(s) Located:\n");
                                printf("--------------------------------------------------------------------------------\n");
                                printf("%-25s %-20s %-30s\n", "Name", "Phone Number", "Email Address");
                                printf("--------------------------------------------------------------------------------\n");
                            }
                            printf("%-25s %-20s %-30s\n", 
                                   phonebook[i].name, 
                                   phonebook[i].phone, 
                                   phonebook[i].email);
                            found = 1;
                        }
                    }
                    if (found) {
                        printf("--------------------------------------------------------------------------------\n");
                    } else {
                        printf("\nNo contact details matching \"%s\" were found.\n", search_name);
                    }
                }
                break;

            case 4:
                printf("\nExiting Contact Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}s