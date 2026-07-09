#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[100];
    char department[50];
    double salary;
};

int main() {
    struct Employee roster[100];
    int employee_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("   EMPLOYEE MANAGEMENT SYSTEM     \n");
        printf("==================================\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employees\n");
        printf("3. View Salary Analytics\n");
        printf("4. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a valid menu number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                if (employee_count >= 100) {
                    printf("\nDatabase full! Cannot add more records.\n");
                } else {
                    printf("\nEnter Employee ID (Integer): ");
                    if (scanf("%d", &roster[employee_count].id) != 1) {
                        printf("Invalid input! Operation canceled.\n");
                        while (getchar() != '\n');
                        break;
                    }
                    while (getchar() != '\n'); 

                    printf("Enter Full Name: ");
                    fgets(roster[employee_count].name, sizeof(roster[employee_count].name), stdin);
                    int len = 0;
                    while (roster[employee_count].name[len] != '\0') len++;
                    if (len > 0 && roster[employee_count].name[len - 1] == '\n') {
                        roster[employee_count].name[len - 1] = '\0';
                    }

                    printf("Enter Department: ");
                    fgets(roster[employee_count].department, sizeof(roster[employee_count].department), stdin);
                    len = 0;
                    while (roster[employee_count].department[len] != '\0') len++;
                    if (len > 0 && roster[employee_count].department[len - 1] == '\n') {
                        roster[employee_count].department[len - 1] = '\0';
                    }

                    printf("Enter Salary: ");
                    if (scanf("%lf", &roster[employee_count].salary) != 1 || roster[employee_count].salary < 0) {
                        printf("Invalid salary! Operation canceled.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    employee_count++;
                    printf("\nEmployee record added successfully!\n");
                }
                break;

            case 2:
                if (employee_count == 0) {
                    printf("\nNo employee records found.\n");
                } else {
                    printf("\n----------------------------------------------------------------------\n");
                    printf("%-10s %-25s %-20s %-15s\n", "ID", "Name", "Department", "Salary");
                    printf("----------------------------------------------------------------------\n");
                    for (int i = 0; i < employee_count; i++) {
                        printf("%-10d %-25s %-20s $%-14.2f\n", 
                               roster[i].id, 
                               roster[i].name, 
                               roster[i].department, 
                               roster[i].salary);
                    }
                    printf("----------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (employee_count == 0) {
                    printf("\nNo data available to calculate metrics.\n");
                } else {
                    double total_payroll = 0;
                    for (int i = 0; i < employee_count; i++) {
                        total_payroll += roster[i].salary;
                    }
                    double average_salary = total_payroll / employee_count;

                    printf("\n==================================\n");
                    printf("         SALARY ANALYTICS         \n");
                    printf("==================================\n");
                    printf("Total Workforce:     %d employees\n", employee_count);
                    printf("Total Monthly Budget: $%.2f\n", total_payroll);
                    printf("Average Staff Salary: $%.2f\n", average_salary);
                    printf("==================================\n");
                }
                break;

            case 4:
                printf("\nExiting Employee Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please pick a number from 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}