#include <stdio.h>
#include <string.h>

struct Account {
    int account_number;
    char holder_name[100];
    double balance;
};

void clear_input_buffer() {
    while (getchar() != '\n');
}

void trim_newline(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void create_account(struct Account bank[], int *count) {
    if (*count >= 100) {
        printf("\nSystem error: Maximum account capacity reached!\n");
        return;
    }

    printf("\nEnter Unique Account Number (Integer): ");
    if (scanf("%d", &bank[*count].account_number) != 1) {
        printf("Invalid input! Account creation aborted.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    for (int i = 0; i < *count; i++) {
        if (bank[i].account_number == bank[*count].account_number) {
            printf("Error: An account with this number already exists!\n");
            return;
        }
    }

    printf("Enter Account Holder's Full Name: ");
    fgets(bank[*count].holder_name, sizeof(bank[*count].holder_name), stdin);
    trim_newline(bank[*count].holder_name);

    printf("Enter Initial Deposit Amount: $");
    if (scanf("%lf", &bank[*count].balance) != 1 || bank[*count].balance < 0) {
        printf("Invalid amount! Account creation aborted.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    (*count)++;
    printf("\nSuccess: Account created successfully!\n");
}

void display_accounts(struct Account bank[], int count) {
    if (count == 0) {
        printf("\nNo accounts registered in the system yet.\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-15s %-30s %-15s\n", "Account No.", "Holder Name", "Balance");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15d %-30s $%-14.2f\n", 
               bank[i].account_number, 
               bank[i].holder_name, 
               bank[i].balance);
    }
    printf("------------------------------------------------------------\n");
}

void perform_transaction(struct Account bank[], int count, int is_deposit) {
    if (count == 0) {
        printf("\nNo accounts available in the database.\n");
        return;
    }

    int target_id;
    int found_index = -1;
    double amount;

    printf("\nEnter Account Number: ");
    if (scanf("%d", &target_id) != 1) {
        printf("Invalid account format!\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();

    for (int i = 0; i < count; i++) {
        if (bank[i].account_number == target_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Error: Account number %d not found.\n", target_id);
        return;
    }

    if (is_deposit) {
        printf("Enter amount to deposit: $");
        if (scanf("%lf", &amount) != 1 || amount <= 0) {
            printf("Invalid deposit amount!\n");
            clear_input_buffer();
            return;
        }
        clear_input_buffer();

        bank[found_index].balance += amount;
        printf("Success: Deposited $%.2f. New Balance: $%.2f\n", amount, bank[found_index].balance);
    } else {
        printf("Enter amount to withdraw: $");
        if (scanf("%lf", &amount) != 1 || amount <= 0) {
            printf("Invalid withdrawal amount!\n");
            clear_input_buffer();
            return;
        }
        clear_input_buffer();

        if (amount > bank[found_index].balance) {
            printf("Transaction Failed: Insufficient funds! Balance is $%.2f\n", bank[found_index].balance);
        } else {
            bank[found_index].balance -= amount;
            printf("Success: Withdrew $%.2f. New Balance: $%.2f\n", amount, bank[found_index].balance);
        }
    }
}

int main() {
    struct Account system_database[100];
    int active_accounts = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("     BANK MANAGEMENT SYSTEM       \n");
        printf("==================================\n");
        printf("1. Create New Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit Application\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice! Please enter a menu option digit.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                create_account(system_database, &active_accounts);
                break;
            case 2:
                display_accounts(system_database, active_accounts);
                break;
            case 3:
                perform_transaction(system_database, active_accounts, 1);
                break;
            case 4:
                perform_transaction(system_database, active_accounts, 0);
                break;
            case 5:
                printf("\nExiting Bank Management System. Goodbye!\n