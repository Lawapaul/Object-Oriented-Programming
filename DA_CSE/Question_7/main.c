#include <stdio.h>

char *day_name(int n) {
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    n = (n % 7 + 7) % 7;
    return days[n];
}

int main() {
    int day_number;
    printf("Enter a number: ");
    scanf("%d", &day_number);
    printf("The day corresponding to %d is %s.\n", day_number, day_name(day_number));
    return 0;
}
