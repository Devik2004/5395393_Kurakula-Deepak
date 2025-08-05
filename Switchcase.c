#include <stdio.h>

int main() {
    int weekday;        // renamed variable to something more descriptive
    int validInput = 0; // flag to track if the input is valid

    do {
        printf("Enter day (1 to 7): ");
        scanf("%d", &weekday);

        switch (weekday) {
            case 1:
                printf("Monday\n");
                validInput = 1;
                break;
            case 2:
                printf("Tuesday\n");
                validInput = 1;
                break;
            case 3:
                printf("Wednesday\n");
                validInput = 1;
                break;
            case 4:
                printf("Thursday\n");
                validInput = 1;
                break;
            case 5:
                printf("Friday\n");
                validInput = 1;
                break;
            case 6:
                printf("Saturday\n");
                validInput = 1;
                break;
            case 7:
                printf("Sunday\n");
                validInput = 1;
                break;
            default:
                printf("Invalid input! Please try again.\n");
                break;
        }
    } while (!validInput);   // repeat until a valid day is entered

    return 0;
}