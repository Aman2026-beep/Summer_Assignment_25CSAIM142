#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[100];
    float gpa;
};

void flush_input() {
    while (getchar() != '\n');
}

void remove_newline(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Student database[100];
    int current_total = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    STUDENT RECORD MANAGEMENT     \n");
        printf("==================================\n");
        printf("1. Add New Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Roll No.\n");
        printf("4. View Class Statistics\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            flush_input(); 
            continue;
        }
        flush_input(); 

        switch (choice) {
            case 1:
                if (current_total >= 100) {
                    printf("\nError: Student database storage limit reached!\n");
                } else {
                    printf("\nEnter Unique Roll Number: ");
                    if (scanf("%d", &database[current_total].roll_no) != 1) {
                        printf("Invalid format! Registration canceled.\n");
                        flush_input();
                        break;
                    }
                    flush_input();

                    int duplicate = 0;
                    for (int i = 0; i < current_total; i++) {
                        if (database[i].roll_no == database[current_total].roll_no) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: A student with Roll Number %d already exists.\n", database[current_total].roll_no);
                        break;
                    }

                    printf("Enter Student Full Name: ");
                    fgets(database[current_total].name, sizeof(database[current_total].name), stdin);
                    remove_newline(database[current_total].name);

                    printf("Enter Student GPA (0.0 - 4.0): ");
                    if (scanf("%f", &database[current_total].gpa) != 1 || database[current_total].gpa < 0.0 || database[current_total].gpa > 4.0) {
                        printf("Invalid GPA rating! Registration canceled.\n");
                        flush_input();
                        break;
                    }

                    current_total++;
                    printf("\nSuccess: Student profile saved successfully!\n");
                }
                break;

            case 2:
                if (current_total == 0) {
                    printf("\nThe student database is currently empty.\n");
                } else {
                    printf("\n--------------------------------------------------\n");
                    printf("%-12s %-25s %-10s\n", "Roll No", "Student Name", "GPA");
                    printf("--------------------------------------------------\n");
                    for (int i = 0; i < current_total; i++) {
                        printf("%-12d %-25s %-10.2f\n", 
                               database[i].roll_no, 
                               database[i].name, 
                               database[i].gpa);
                    }
                    printf("--------------------------------------------------\n");
                }
                break;

            case 3:
                if (current_total == 0) {
                    printf("\nNo student profiles exist to search.\n");
                } else {
                    int search_roll, found_index = -1;
                    printf("\nEnter Roll Number to look up: ");
                    if (scanf("%d", &search_roll) != 1) {
                        printf("Invalid digit input.\n");
                        flush_input();
                        break;
                    }

                    for (int i = 0; i < current_total; i++) {
                        if (database[i].roll_no == search_roll) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Roll Number %d not found in active catalog.\n", search_roll);
                    } else {
                        printf("\nRecord Located:\n");
                        printf("---------------------\n");
                        printf("Roll Number:  %d\n", database[found_index].roll_no);
                        printf("Full Name:    %s\n", database[found_index].name);
                        printf("Current GPA:  %.2f\n", database[found_index].gpa);
                    }
                }
                break;

            case 4:
                if (current_total == 0) {
                    printf("\nNo data sets exist to compile academic metrics.\n");
                } else {
                    float total_gpa = 0;
                    float highest_gpa = database[0].gpa;
                    int highest_index = 0;

                    for (int i = 0; i < current_total; i++) {
                        total_gpa += database[i].gpa;
                        if (database[i].gpa > highest_gpa) {
                            highest_gpa = database[i].gpa;
                            highest_index = i;
                        }
                    }

                    printf("\n==================================\n");
                    printf("         CLASS METRICS            \n");
                    printf("==================================\n");
                    printf("Total Enrolled Students: %d\n", current_total);
                    printf("Class Average GPA:       %.2f\n", total_gpa / current_total);
                    printf("Valedictorian (Top GPA): %s (GPA: %.2f)\n", database[highest_index].name, database[highest_index].gpa);
                    printf("==================================\n");
                }
                break;

            case 5:
                printf("\nExiting Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option selection! Range spans from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}