#include <stdio.h>
#include <string.h>

struct TicketLog {
    int booking_id;
    char customer_name[100];
    int row;
    int seat;
};

void clear_terminal_stream() {
    while (getchar() != '\n');
}

void clean_newline_character(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int theater_seats[5][5] = {0}; 
    struct TicketLog logs[100];
    int total_bookings = 0;
    int booking_counter = 1001; 
    int choice;

    do {
        printf("\n==================================\n");
        printf("      TICKET BOOKING SYSTEM       \n");
        printf("==================================\n");
        printf("1. View Seat Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Display Transaction Logs\n");
        printf("4. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection! Please enter a menu option digit.\n");
            clear_terminal_stream(); 
            continue;
        }
        clear_terminal_stream(); 

        switch (choice) {
            case 1:
                printf("\n--- THEATER SEAT CHART ---\n");
                printf("     [SCREEN THIS WAY]\n\n");
                printf("       ");
                for (int j = 0; j < 5; j++) {
                    printf("Seat %d  ", j + 1);
                }
                printf("\n");
                
                for (int i = 0; i < 5; i++) {
                    printf("Row %d:  ", i + 1);
                    for (int j = 0; j < 5; j++) {
                        if (theater_seats[i][j] == 0) {
                            printf("[ O ]   "); 
                        } else {
                            printf("[ X ]   "); 
                        }
                    }
                    printf("\n");
                }
                printf("\nLegend: [ O ] = Available  |  [ X ] = Booked\n");
                break;

            case 2:
                if (total_bookings >= 100) {
                    printf("\nError: System transaction logs capacity full!\n");
                    break;
                }

                int req_row, req_seat;
                printf("\nEnter Row Number (1-5): ");
                if (scanf("%d", &req_row) != 1 || req_row < 1 || req_row > 5) {
                    printf("Invalid row! Operation canceled.\n");
                    clear_terminal_stream(); break;
                }
                
                printf("Enter Seat Number (1-5): ");
                if (scanf("%d", &req_seat) != 1 || req_seat < 1 || req_seat > 5) {
                    printf("Invalid seat row! Operation canceled.\n");
                    clear_terminal_stream(); break;
                }
                clear_terminal_stream();

                int r_idx = req_row - 1;
                int s_idx = req_seat - 1;

                if (theater_seats[r_idx][s_idx] == 1) {
                    printf("\nReservation Failed: That seat is already taken!\n");
                } else {
                    printf("Enter Customer Full Name: ");
                    fgets(logs[total_bookings].customer_name, sizeof(logs[total_bookings].customer_name), stdin);
                    clean_newline_character(logs[total_bookings].customer_name);

                    theater_seats[r_idx][s_idx] = 1; 

                    logs[total_bookings].booking_id = booking_counter++;
                    logs[total_bookings].row = req_row;
                    logs[total_bookings].seat = req_seat;

                    printf("\nSuccess: Ticket Reserved successfully!\n");
                    printf("Your Ticket Booking ID is: %d\n", logs[total_bookings].booking_id);
                    
                    total_bookings++;
                }
                break;

            case 3:
                if (total_bookings == 0) {
                    printf("\nNo ticket sales recorded yet.\n");
                } else {
                    printf("\n----------------------------------------------------------------------\n");
                    printf("%-15s %-30s %-12s %-12s\n", "Booking ID", "Customer Name", "Row Num", "Seat Num");
                    printf("----------------------------------------------------------------------\n");
                    for (int i = 0; i < total_bookings; i++) {
                        printf("%-15d %-30s Row %-8d Seat %-8d\n", 
                               logs[i].booking_id, 
                               logs[i].customer_name, 
                               logs[i].row, 
                               logs[i].seat);
                    }
                    printf("----------------------------------------------------------------------\n");
                }
                break;

            case 4:
                printf("\nExiting Ticket Booking System Terminal. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}