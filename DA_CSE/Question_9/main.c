#include <stdio.h>

float yardsFeetToMiles(int *yards, int *feet) {
    float total_feet=(*feet)+ (*yards * 3);
    return total_feet / 5280; // Convert feet to miles
}

int main() {
    int yards,feet;
    scanf("%d",&yards);
    scanf("%d",&feet);
    float miles1 = yardsFeetToMiles(&yards, &feet);

    printf("%d Yards and %d feet is %.2f miles.\n", yards,feet,miles1);

    return 0;
}
