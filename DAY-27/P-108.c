#include <stdio.h>
#include <string.h>

struct Marksheet {
    int roll_no;
    char name[100];
    float math;
    float science;
    float english;
    float total;
    float percentage;
    char grade[5];
};

void clear_input_stream() {
    while (getchar() != '\n');
}

void trim_string_newline(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    struct Marksheet records[100];
    int total_students = 0;
    int choice;

    do {
        printf("\n==================================\n");
        printf("    MARKSHEET GENERATION SYSTEM   \n");
        printf("==================================\n");
        printf("1. Enter Student Marks\n");
        printf("2. Generate Marksheets\n");
        printf("3. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_input_stream(); 
            continue;
        }
        clear_input_stream(); 

        switch (choice) {
            case 1:
                if (total_students >= 100) {
                    printf("\nError: System database storage capacity full!\n");
                } else {
                    printf("\nEnter Unique Roll Number: ");
                    if (scanf("%d", &records[total_students].roll_no) != 1) {
                        printf("Invalid format! Record addition canceled.\n");
                        clear_input_stream();
                        break;
                    }
                    clear_input_stream();

                    int duplicate = 0;
                    for (int i = 0; i < total_students; i++) {
                        if (records[i].roll_no == records[total_students].roll_no) {
                            duplicate = 1;
                            break;
                        }
                    }
                    if (duplicate) {
                        printf("Error: A student with Roll Number %d already exists.\n", records[total_students].roll_no);
                        break;
                    }

                    printf("Enter Student Full Name: ");
                    fgets(records[total_students].name, sizeof(records[total_students].name), stdin);
                    trim_string_newline(records[total_students].name);

                    printf("Enter Marks for Mathematics (0-100): ");
                    if (scanf("%f", &records[total_students].math) != 1 || records[total_students].math < 0 || records[total_students].math > 100) {
                        printf("Invalid marks entered! Operation canceled.\n");
                        clear_input_stream(); break;
                    }

                    printf("Enter Marks for Science (0-100): ");
                    if (scanf("%f", &records[total_students].science) != 1 || records[total_students].science < 0 || records[total_students].science > 100) {
                        printf("Invalid marks entered! Operation canceled.\n");
                        clear_input_stream(); break;
                    }

                    printf("Enter Marks for English (0-100): ");
                    if (scanf("%f", &records[total_students].english) != 1 || records[total_students].english < 0 || records[total_students].english > 100) {
                        printf("Invalid marks entered! Operation canceled.\n");
                        clear_input_stream(); break;
                    }

                    records[total_students].total = records[total_students].math + records[total_students].science + records[total_students].english;
                    records[total_students].percentage = (records[total_students].total / 300.0) * 100.0;

                    if (records[total_students].percentage >= 90.0) {
                        strcpy(records[total_students].grade, "A+");
                    } else if (records[total_students].percentage >= 80.0) {
                        strcpy(records[total_students].grade, "A");
                    } else if (records[total_students].percentage >= 70.0) {
                        strcpy(records[total_students].grade, "B");
                    } else if (records[total_students].percentage >= 60.0) {
                        strcpy(records[total_students].grade, "C");
                    } else if (records[total_students].percentage >= 50.0) {
                        strcpy(records[total_students].grade, "D");
                    } else {
                        strcpy(records[total_students].grade, "Fail");
                    }

                    total_students++;
                    printf("\nSuccess: Academic scores logged successfully!\n");
                }
                break;

            case 2:
                if (total_students == 0) {
                    printf("\nNo student marks data found in the system database.\n");
                } else {
                    for (int i = 0; i < total_students; i++) {
                        printf("\n====================================================\n");
                        printf("                OFFICIAL REPORT CARD                \n");
                        printf("====================================================\n");
                        printf(" Roll No: %-10d | Name: %-25s\n", records[i].roll_no, records[i].name);
                        printf("----------------------------------------------------\n");
                        printf(" Subject                  Maximum Marks    Obtained \n");
                        printf("----------------------------------------------------\n");
                        printf(" Mathematics              100              %.2f\n", records[i].math);
                        printf(" Science                  100              %.2f\n", records[i].science);
                        printf(" English                  100              %.2f\n", records[i].english);
                        printf("----------------------------------------------------\n");
                        printf(" Cumulative Total Marks:  300 / %.2f\n", records[i].total);
                        printf(" Aggregate Percentage:    %.2f%%\n", records[i].percentage);
                        printf(" Final Evaluation Grade:  %s\n", records[i].grade);
                        printf("====================================================\n");
                    }
                }
                break;

            case 3:
                printf("\nExiting Marksheet Generation System. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option selection! Choose between 1 and 3.\n");
        }

    } while (choice != 3);

    return 0;
}