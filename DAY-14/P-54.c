#include <stdio.h>

int main() {
    int numbers[] = {12, 5, 7, 5, 28, 5, 12, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target;
    int count = 0;

    printf("Enter the number to find its frequency: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            count++;
        }
    }

    if (count > 0) {
        printf("The number %d appears %d times in the array.\n", target, count);
    } else {
        printf("The number %d does not exist in the array.\n", target);
    }

    return 0;
}