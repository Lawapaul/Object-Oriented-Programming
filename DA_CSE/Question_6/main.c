#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strcmp(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

void my_swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sort(char *arr[], int n, int (*cmp)(const char *, const char *), void (*swp)(char **, char **)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cmp(arr[j], arr[j + 1]) > 0) {
                swp(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    char *names[n];

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);
        names[i] = strdup(temp);
    }

    sort(names, n, my_strcmp, my_swap);


    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }

    return 0;
}
