#include <stdio.h>

int main() {
    double balance = 5000.00;
    int choice;
    double amount;

    do {
        printf("\n==================================\n");
        printf("          ATM SIMULATION          \n");
        printf("==================================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit ATM\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a valid menu number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter deposit amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount! Operation canceled.\n");
                } else {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                }
                while (getchar() != '\n'); 
                break;

            case 3:
                printf("\nEnter withdrawal amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("Invalid amount! Operation canceled.\n");
                } else if (amount > balance) {
                    printf("Transaction Failed! Insufficient account balance.\n");
                } else {
                    balance -= amount;
                    printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, balance);
                }
                while (getchar() != '\n'); 
                break;

            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please pick a number from 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}n