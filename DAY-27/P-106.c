#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[100];
    char role[50];
    double salary;
};

void flush_terminal_buffer() {
    while (getchar() != '\n');
}

void strip_trailing_newline(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Employee database[100];
    int active_records = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    EMPLOYEE MANAGEMENT SYSTEM    \n");
        printf("==================================\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. View Payroll Analytics\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            flush_terminal_buffer(); 
            continue;
        }
        flush_terminal_buffer(); 

        switch (choice) {
            case 1:
                if (active_records >= 100) {
                    printf("\nError: Employee database storage limit reached!\n");
                } else {
                    printf("\nEnter Unique Employee ID (Integer): ");
                    if (scanf("%d", &database[active_records].id) != 1) {
                        printf("Invalid format! Registration canceled.\n");
                        flush_terminal_buffer();
                        break;
                    }
                    flush_terminal_buffer();

                    int duplicate = 0;
                    for (int i = 0; i < active_records; i++) {
                        if (database[i].id == database[active_records].id) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: An employee with ID %d already exists.\n", database[active_records].id);
                        break;
                    }

                    printf("Enter Full Name: ");
                    fgets(database[active_records].name, sizeof(database[active_records].name), stdin);
                    strip_trailing_newline(database[active_records].name);

                    printf("Enter Job Title/Role: ");
                    fgets(database[active_records].role, sizeof(database[active_records].role), stdin);
                    strip_trailing_newline(database[active_records].role);

                    printf("Enter Monthly Salary ($): ");
                    if (scanf("%lf", &database[active_records].salary) != 1 || database[active_records].salary < 0) {
                        printf("Invalid salary entry! Registration canceled.\n");
                        flush_terminal_buffer();
                        break;
                    }

                    active_records++;
                    printf("\nSuccess: Employee profile saved successfully!\n");
                }
                break;

            case 2:
                if (active_records == 0) {
                    printf("\nThe employee database is currently empty.\n");
                } else {
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("%-10s %-25s %-22s %-15s\n", "ID", "Employee Name", "Role/Designation", "Salary");
                    printf("----------------------------------------------------------------------------\n");
                    for (int i = 0; i < active_records; i++) {
                        printf("%-10d %-25s %-22s $%-14.2f\n", 
                               database[i].id, 
                               database[i].name, 
                               database[i].role, 
                               database[i].salary);
                    }
                    printf("----------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (active_records == 0) {
                    printf("\nNo employee profiles exist to search.\n");
                } else {
                    int search_id, found_index = -1;
                    printf("\nEnter Employee ID to look up: ");
                    if (scanf("%d", &search_id) != 1) {
                        printf("Invalid digit input.\n");
                        flush_terminal_buffer();
                        break;
                    }

                    for (int i = 0; i < active_records; i++) {
                        if (database[i].id == search_id) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Employee ID %d not found in active records.\n", search_id);
                    } else {
                        printf("\nRecord Located:\n");
                        printf("---------------------\n");
                        printf("Employee ID: %d\n", database[found_index].id);
                        printf("Full Name:   %s\n", database[found_index].name);
                        printf("Job Position:%s\n", database[found_index].role);
                        printf("Salary:      $%.2f\n", database[found_index].salary);
                    }
                }
                break;

            case 4:
                if (active_records == 0) {
                    printf("\nNo data sets exist to compile financial metrics.\n");
                } else {
                    double total_payroll = 0;
                    double highest_pay = database[0].salary;
                    int top_earner_index = 0;

                    for (int i = 0; i < active_records; i++) {
                        total_payroll += database[i].salary;
                        if (database[i].salary > highest_pay) {
                            highest_pay = database[i].salary;
                            top_earner_index = i;
                        }
                    }

                    printf("\n==================================\n");
                    printf("        PAYROLL ANALYTICS         \n");
                    printf("==================================\n");
                    printf("Total Workforce Size:   %d staff members\n", active_records);
                    printf("Total Monthly Budget:   $%.2f\n", total_payroll);
                    printf("Average Staff Salary:   $%.2f\n", total_payroll / active_records);
                    printf("Highest Paid Position:  %s ($%.2f)\n", database[top_earner_index].name, database[top_earner_index].salary);
                    printf("==================================\n");
                }
                break;

            case 5:
                printf("\nExiting HR Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option selection! Range spans from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}