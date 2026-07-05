#include <stdio.h>

int main() {
    char name[100];
    int age;
    int voting_age = 18;

    printf("======================================\n");
    printf("      VOTING ELIGIBILITY SYSTEM       \n");
    printf("======================================\n");

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    int len = 0;
    while (name[len] != '\0') len++;
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1 || age < 0) {
        printf("\nError: Invalid age entered. System exiting.\n");
        return 1;
    }

    printf("\nHello %s,\n", name);
    if (age >= voting_age) {
        printf("Status: ELIGIBLE\n");
        printf("You are legally qualified to cast your vote.\n");
    } else {
        int years_left = voting_age - age;
        printf("Status: NOT ELIGIBLE\n");
        printf("You must wait %d more year(s) to become an eligible voter.\n", years_left);
    }

    return 0;
}n