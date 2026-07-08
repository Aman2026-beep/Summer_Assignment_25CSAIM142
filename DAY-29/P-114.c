#include <stdio.h>

void display_array(int arr[], int size) {
    if (size == 0) {
        printf("\nThe array is currently empty.\n");
        return;
    }
    printf("\nCurrent Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nCurrent Size: %d / 100\n", size);
}

void insert_element(int arr[], int *size) {
    if (*size >= 100) {
        printf("\nError: Array capacity reached! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("\nEnter the element to insert: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid numeric input!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter the position index (0 to %d): ", *size);
    if (scanf("%d", &position) != 1 || position < 0 || position > *size) {
        printf("Invalid position! Operation canceled.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("Success: Element %d inserted at position %d.\n", element, position);
}

void delete_element(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array is empty! Nothing to delete.\n");
        return;
    }

    int position;
    printf("\nEnter the position index to delete (0 to %d): ", *size - 1);
    if (scanf("%d", &position) != 1 || position < 0 || position >= *size) {
        printf("Invalid position! Operation canceled.\n");
        while (getchar() != '\n');
        return;
    }

    int deleted_value = arr[position];

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    结构(*size)--;
    printf("Success: Element %d removed from position %d.\n", deleted_value, position);
}

void search_element(int arr[], int size) {
    if (size == 0) {
        printf("\nArray is empty! Nothing to search.\n");
        return;
    }

    int target;
    printf("\nEnter the element to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid numeric input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found! Value %d sits at index position %d.\n", target, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", target);
}

int main() {
    int array[100];
    int size = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("     ARRAY OPERATIONS SYSTEM      \n");
        printf("==================================\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                insert_element(array, &size);
                break;
            case 2:
                delete_element(array, &size);
                break;
            case 3:
                search_element(array, size);
                break;
            case 4:
                display_array(array, size);
                break;
            case 5:
                printf("\nExiting System Application. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please pick a number from 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}