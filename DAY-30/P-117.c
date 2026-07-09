#include <stdio.h>
#include <string.h>

struct Student {
    int roll_number;
    char name[100];
    float marks;
};

int main() {
    struct Student database[100];
    int student_count = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("      STUDENT RECORD SYSTEM       \n");
        printf("==================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
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
                if (student_count >= 100) {
                    printf("\nDatabase full! Cannot add more student records.\n");
                } else {
                    printf("\nEnter Roll Number: ");
                    if (scanf("%d", &database[student_count].roll_number) != 1) {
                        printf("Invalid input! Operation canceled.\n");
                        while (getchar() != '\n');
                        break;
                    }
                    while (getchar() != '\n');

                    printf("Enter Full Name: ");
                    fgets(database[student_count].name, sizeof(database[student_count].name), stdin);
                    
                    int len = 0;
                    while (database[student_count].name[len] != '\0') len++;
                    if (len > 0 && database[student_count].name[len - 1] == '\n') {
                        database[student_count].name[len - 1] = '\0';
                    }

                    printf("Enter Marks: ");
                    if (scanf("%f", &database[student_count].marks) != 1) {
                        printf("Invalid input! Operation canceled.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    student_count++;
                    printf("\nRecord added successfully!\n");
                }
                break;

            case 2:
                if (student_count == 0) {
                    printf("\nNo student records available.\n");
                } else {
                    printf("\n-------------------------------------------------\n");
                    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
                    printf("-------------------------------------------------\n");
                    for (int i = 0; i < student_count; i++) {
                        printf("%-10d %-25s %-10.2f\n", 
                               database[i].roll_number, 
                               database[i].name, 
                               database[i].marks);
                    }
                    printf("-------------------------------------------------\n");
                }
                break;

            case 3:
                if (student_count == 0) {
                    printf("\nNo records available to search.\n");
                } else {
                    int search_roll;
                    int found = 0;
                    printf("\nEnter Roll Number to search: ");
                    if (scanf("%d", &search_roll) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                        break;
                    }

                    for (int i = 0; i < student_count; i++) {
                        if (database[i].roll_number == search_roll) {
                            printf("\nRecord Found:\n");
                            printf("Roll Number: %d\n", database[i].roll_number);
                            printf("Name:        %s\n", database[i].name);
                            printf("Marks:       %.2f\n", database[i].marks);
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {
                        printf("\nStudent with Roll Number %d not found.\n", search_roll);
                    }
                }
                break;

            case 4:
                printf("\nExiting Student Record System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option! Please pick a number from 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}