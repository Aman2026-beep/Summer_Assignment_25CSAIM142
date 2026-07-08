#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[100];
    int quantity;
    double price;
};

void flush_buffer() {
    while (getchar() != '\n');
}

void clean_string(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Product warehouse[100];
    int product_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM   \n");
        printf("==================================\n");
        printf("1. Add New Product\n");
        printf("2. Display Current Stock\n");
        printf("3. Update Stock Quantity\n");
        printf("4. View Low Stock Alerts\n");
        printf("5. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            flush_buffer(); 
            continue;
        }
        flush_buffer(); 

        switch (choice) {
            case 1:
                if (product_count >= 100) {
                    printf("\nError: Warehouse database storage limit reached!\n");
                } else {
                    printf("\nEnter Product ID (Integer): ");
                    if (scanf("%d", &warehouse[product_count].id) != 1) {
                        printf("Invalid format! Registration canceled.\n");
                        flush_buffer();
                        break;
                    }
                    flush_buffer();

                    int duplicate = 0;
                    for (int i = 0; i < product_count; i++) {
                        if (warehouse[i].id == warehouse[product_count].id) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: A product with ID %d already exists.\n", warehouse[product_count].id);
                        break;
                    }

                    printf("Enter Product Name: ");
                    fgets(warehouse[product_count].name, sizeof(warehouse[product_count].name), stdin);
                    clean_string(warehouse[product_count].name);

                    printf("Enter Initial Quantity: ");
                    if (scanf("%d", &warehouse[product_count].quantity) != 1 || warehouse[product_count].quantity < 0) {
                        printf("Invalid quantity tracking value! Registration canceled.\n");
                        flush_buffer();
                        break;
                    }

                    printf("Enter Unit Price ($): ");
                    if (scanf("%lf", &warehouse[product_count].price) != 1 || warehouse[product_count].price < 0) {
                        printf("Invalid price value! Registration canceled.\n");
                        flush_buffer();
                        break;
                    }

                    product_count++;
                    printf("\nSuccess: Product logged into system catalog!\n");
                }
                break;

            case 2:
                if (product_count == 0) {
                    printf("\nThe inventory database is currently empty.\n");
                } else {
                    printf("\n----------------------------------------------------------------------\n");
                    printf("%-10s %-25s %-15s %-15s\n", "ID", "Product Name", "Quantity", "Price");
                    printf("----------------------------------------------------------------------\n");
                    for (int i = 0; i < product_count; i++) {
                        printf("%-10d %-25s %-15d $%-14.2f\n", 
                               warehouse[i].id, 
                               warehouse[i].name, 
                               warehouse[i].quantity, 
                               warehouse[i].price);
                    }
                    printf("----------------------------------------------------------------------\n");
                }
                break;

            case 3:
                if (product_count == 0) {
                    printf("\nNo stock profiles exist to alter.\n");
                } else {
                    int search_id, found_index = -1;
                    printf("\nEnter Product ID to update: ");
                    if (scanf("%d", &search_id) != 1) {
                        printf("Invalid index choice.\n");
                        flush_buffer();
                        break;
                    }

                    for (int i = 0; i < product_count; i++) {
                        if (warehouse[i].id == search_id) {
                            found_index = i;
                            break;
                        }
                    }

                    if (found_index == -1) {
                        printf("Item ID %d not tracked in active catalog.\n", search_id);
                    } else {
                        int change_type, amount;
                        printf("Current stock level: %d\n", warehouse[found_index].quantity);
                        printf("Select option: (1) Restock/Add | (2) Sale/Deduct: ");
                        scanf("%d", &change_type);

                        if (change_type == 1) {
                            printf("Enter amount to add: ");
                            scanf("%d", &amount);
                            if (amount > 0) {
                                warehouse[found_index].quantity += amount;
                                printf("Stock updated! New total: %d\n", warehouse[found_index].quantity);
                            }
                        } else if (change_type == 2) {
                            printf("Enter amount to deduct: ");
                            scanf("%d", &amount);
                            if (amount > warehouse[found_index].quantity) {
                                printf("Transaction Refused: Deficit error! Not enough stock.\n");
                            } else if (amount > 0) {
                                warehouse[found_index].quantity -= amount;
                                printf("Stock updated! Remaining balance: %d\n", warehouse[found_index].quantity);
                            }
                        } else {
                            printf("Invalid command option map selected.\n");
                        }
                    }
                }
                break;

            case 4:
                if (product_count == 0) {
                    printf("\nNo stock items to cross-reference.\n");
                } else {
                    int low_count = 0;
                    int threshold = 5; 
                    
                    printf("\n==================================\n");
                    printf("   CRITICAL LOW STOCK WARNINGS   \n");
                    printf("   (Items with less than %d units) \n", threshold);
                    printf("==================================\n");
                    
                    for (int i = 0; i < product_count; i++) {
                        if (warehouse[i].quantity < threshold) {
                            printf