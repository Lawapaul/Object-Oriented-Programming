#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calculate_stats(float *weights, int n, float *sum, float *mean, float *std_dev) {
    *sum = 0.0;
    for (int i = 0; i < n; i++) {
        *sum += *(weights + i);
    }
    *mean = *sum / n;
    float sum_of_squares = 0.0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += (*(weights + i) - *mean) * (*(weights + i) - *mean);
    }
    *std_dev = sum_of_squares / n;
}

int main() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    float *weights = (float *)malloc(n * sizeof(float));
    printf("Enter the weights of %d people:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", weights + i);
    }

    float sum, mean, std_dev;

    calculate_stats(weights, n, &sum, &mean, &std_dev);


    std_dev = sqrt(std_dev); 

    // Print results
    printf("Sum of weights: %.2f\n", sum);
    printf("Mean of weights: %.2f\n", mean);
    printf("Standard deviation of weights: %.2f\n", std_dev);

    // Free dynamically allocated memory
    free(weights);

    return 0;
}
