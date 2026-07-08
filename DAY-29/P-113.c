#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        printf("\n==================================\n");
        printf("      MENU-DRIVEN CALCULATOR      \n");
        printf("==================================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid numeric input!\n");
                while (getchar() != '\n');
                continue;
            }
            printf("Enter second number: ");
            if (scanf("%lf", &num2) != 1) {
                printf("Invalid numeric input!\n");
                while (getchar() != '\n');
                continue;
            }
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\nResult: %.4f + %.4f = %.4f\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("\nResult: %.4f - %.4f = %.4f\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("\nResult: %.4f * %.4f = %.4f\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("\nMathematical Error: Division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("\nResult: %.4f / %.4f = %.4f\n", num1, num2, result);
                }
                break;

            case 5:
                printf("\nExiting Calculator Application. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please pick a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}