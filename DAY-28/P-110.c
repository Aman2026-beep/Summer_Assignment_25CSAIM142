#include <stdio.h>
#include <string.h>

struct BankAccount {
    int account_no;
    char holder_name[100];
    double balance;
};

void empty_input_stream() {
    while (getchar() != '\n');
}

void strip_newline_char(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct BankAccount ledger[100];
    int account_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("       BANK ACCOUNT SYSTEM        \n");
        printf("==================================\n");
        printf("1. Open New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            empty_input_stream(); 
            continue;
        }
        empty_input_stream(); 

        switch (choice) {
            case 1:
                if (account_count >= 100) {
                    printf("\nError: Banking database registry capacity full!\n");
                } else {
                    printf("\nEnter Unique Account Number (Integer): ");
                    if (scanf("%d", &ledger[account_count].account_no) != 1) {
                        printf("Invalid format! Registration canceled.\n");
                        empty_input_stream();
                        break;
                    }
                    empty_input_stream();

                    int duplicate = 0;
                    for (int i = 0; i < account_count; i++) {
                        if (ledger[i].account_no == ledger[account_count].account_no) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: An account with number %d already exists.\n", ledger[account_count].account_no);
                        break;
                    }

                    printf("Enter Account Holder's Full Name: ");
                    fgets(ledger[account_count].holder_name, sizeof(ledger[account_count].holder_name), stdin);
                    strip_newline_char(ledger[account_count].holder_name);

                    printf("Enter Initial Deposit Balance ($): ");
                    if (scanf("%lf", &ledger[account_count].balance) != 1 || ledger[account_count].balance < 0) {
                        printf("Invalid opening balance! Registration canceled.\n");
                        empty_input_stream();
                        break;
                    }

                    account_count++;
                    printf("\nSuccess: New bank account opened successfully!\n");
                }
                break;

            case 2:
                if (account_count == 0) {
                    printf("\nThe system database has no active registered accounts.\n");
                } else {
                    printf("\n--------------------------------------------------------------\n");
                    printf("%-15s %-30s %-15s\n", "Account No.", "Holder Name", "Balance");
                    printf("--------------------------------------------------------------\n");
                    for (int i = 0; i < account_count; i++) {
                        printf("%-15d %-30s $%-14.2f\n", 
                               ledger[i].account_no, 
                               ledger[i].holder_name, 
                               ledger[i].balance);
                    }
                    printf("--------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (account_count == 0) {
                    printf("\nNo operational accounts exist to receive deposits.\n");
                } else {
                    int target_acc, found_index = -1;
                    printf("\nEnter Target Account Number: ");
                    if (scanf("%d", &target_acc) != 1) {
                        printf("Invalid transaction entry format.\n");
                        empty_input_stream(); break;
                    }

                    for (int i = 0; i < account_count; i++) {
                        if (ledger[i].account_no == target_acc) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Error: Account number %d not registered.\n", target_acc);
                    } else {
                        double amount;
                        printf("Enter amount to deposit: $");
                        if (scanf("%lf", &amount) != 1 || amount <= 0) {
                            printf("Invalid deposit volume! Transaction canceled.\n");
                            empty_input_stream(); break;
                        }
                        
                        ledger[found_index].balance += amount;
                        printf("Success: Deposited $%.2f. New Balance: $%.2f\n", amount, ledger[found_index].balance);
                    }
                }
                break;

            case 4:
                if (account_count == 0) {
                    printf("\nNo operational accounts exist to request withdrawals.\n");
                } else {
                    int target_acc, found_index = -1;
                    printf("\nEnter Target Account Number: ");
                    if (scanf("%d", &target_acc) != 1) {
                        printf("Invalid transaction entry format.\n");
                        empty_input_stream(); break;
                    }

                    for (int i = 0; i < account_count; i++) {
                        if (ledger[i].account_no == target_acc) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Error: Account number %d not registered.\n", target_acc);
                    } else {
                        double amount;
                        printf("Current Balance: $%.2f\n", ledger[found_index].balance);
                        printf("Enter amount to withdraw: $");
                        if (scanf("%lf", &amount) != 1 || amount <= 0) {
                            printf("Invalid withdrawal volume! Transaction canceled.\n");
                            empty_input_stream(); break;
                        }

                        if (amount > ledger[found_index].balance) {
                            printf("Transaction Denied: Insufficient ledger funds available.\n");
                        } else {
                            ledger[found_index].balance -= amount;
                            printf("Success: Withdrew $%.2f. Remaining Balance: $%.2f\n", amount, ledger[found_index].balance);
                        }
                    }
                }
                break;

            case 5:
                printf("\nShutting down Core Banking System Terminal. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}