#include <stdio.h>
#include <string.h>

struct SalaryRecord {
    int employee_id;
    char name[100];
    double basic_salary;
    double allowance;
    double tax_deduction;
    double pf_deduction; 
    double net_salary;
};

void clear_stream() {
    while (getchar() != '\n');
}

void clean_input_string(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct SalaryRecord payroll[100];
    int staff_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("     SALARY MANAGEMENT SYSTEM     \n");
        printf("==================================\n");
        printf("1. Generate Employee Payroll\n");
        printf("2. View Comprehensive Payslips\n");
        printf("3. View Total Company Expenditure\n");
        printf("4. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_stream(); 
            continue;
        }
        clear_stream(); 

        switch (choice) {
            case 1:
                if (staff_count >= 100) {
                    printf("\nError: Payroll database capacity full!\n");
                } else {
                    printf("\nEnter Employee ID (Integer): ");
                    if (scanf("%d", &payroll[staff_count].employee_id) != 1) {
                        printf("Invalid format! Operations canceled.\n");
                        clear_stream();
                        break;
                    }
                    clear_stream();

                    int duplicate = 0;
                    for (int i = 0; i < staff_count; i++) {
                        if (payroll[i].employee_id == payroll[staff_count].employee_id) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: An employee with ID %d already has a compiled payroll.\n", payroll[staff_count].employee_id);
                        break;
                    }

                    printf("Enter Employee Full Name: ");
                    fgets(payroll[staff_count].name, sizeof(payroll[staff_count].name), stdin);
                    clean_input_string(payroll[staff_count].name);

                    printf("Enter Monthly Base/Basic Salary ($): ");
                    if (scanf("%lf", &payroll[staff_count].basic_salary) != 1 || payroll[staff_count].basic_salary < 0) {
                        printf("Invalid numeric value! Calculation aborted.\n");
                        clear_stream();
                        break;
                    }

                    printf("Enter Total Monthly Allowances ($): ");
                    if (scanf("%lf", &payroll[staff_count].allowance) != 1 || payroll[staff_count].allowance < 0) {
                        printf("Invalid numeric value! Calculation aborted.\n");
                        clear_stream();
                        break;
                    }

                    double gross = payroll[staff_count].basic_salary + payroll[staff_count].allowance;
                    
                    payroll[staff_count].tax_deduction = gross * 0.12; 
                    payroll[staff_count].pf_deduction = payroll[staff_count].basic_salary * 0.05; 
                    
                    payroll[staff_count].net_salary = gross - (payroll[staff_count].tax_deduction + payroll[staff_count].pf_deduction);

                    staff_count++;
                    printf("\nSuccess: Financial record tracked and calculated!\n");
                }
                break;

            case 2:
                if (staff_count == 0) {
                    printf("\nNo structural payroll records on file.\n");
                } else {
                    printf("\n========================================================================================\n");
                    printf("%-8s %-20s %-12s %-12s %-10s %-10s %-12s\n", "ID", "Name", "Basic", "Allowances", "Tax (12%)", "PF (5%)", "Net Salary");
                    printf("========================================================================================\n");
                    for (int i = 0; i < staff_count; i++) {
                        printf("%-8d %-20s $%-11.2f $%-11.2f $%-9.2f $%-9.2f $%-11.2f\n", 
                               payroll[i].employee_id, 
                               payroll[i].name, 
                               payroll[i].basic_salary, 
                               payroll[i].allowance, 
                               payroll[i].tax_deduction, 
                               payroll[i].pf_deduction, 
                               payroll[i].net_salary);
                    }
                    printf("----------------------------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (staff_count == 0) {
                    printf("\nNo data sets exist to compile financial metrics.\n");
                } else {
                    double total_basic = 0, total_allowance = 0, total_tax = 0, total_pf = 0, total_net = 0;

                    for (int i = 0; i < staff_count; i++) {
                        total_basic += payroll[i].basic_salary;
                        total_allowance += payroll[i].allowance;
                        total_tax += payroll[i].tax_deduction;
                        total_pf += payroll[i].pf_deduction;
                        total_net += payroll[i].net_salary;
                    }

                    printf("\n==================================\n");
                    printf("     COMPANY OUTFLOW METRICS      \n");
                    printf("==================================\n");
                    printf("Active Paid Workers:   %d staff\n", staff_count);
                    printf("Total Base Payroll:   $%.2f\n", total_basic);
                    printf("Total Allowances Out:  $%.2f\n", total_allowance);
                    printf("Total Tax Withheld:    $%.2f\n", total_tax);
                    printf("Total PF Contributed:  $%.2f\n", total_pf);
                    printf("----------------------------------\n");
                    printf("NET CASH OUTFLOW:      $%.2f\n", total_net);
                    printf("==================================\n");
                }
                break;

            case 4:
                printf("\nExiting Salary Management System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option selection! Range spans from 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}