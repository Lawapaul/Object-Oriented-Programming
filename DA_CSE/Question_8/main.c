#include <stdio.h>         
#include <stdlib.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
void add_matrices(int *mat1, int *mat2, int *result, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // Accessing elements of matrices using pointer arithmetic
            *(result+ i * c + j) = *(mat1 + i * c + j) + *(mat2 + i * r + j);
        }
    }
}

// Function to display a matrix
void display_matrix(int *matrix, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // Accessing elements of the matrix using pointer arithmetic
            printf("%d ", *(matrix + i * c + j));
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);
    int *mat1 = (int *)malloc(rows * cols * sizeof(int));
    int *mat2 = (int *)malloc(rows * cols * sizeof(int));
    int *result = (int *)malloc(rows * cols * sizeof(int));

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", mat1 + i * cols + j);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", mat2 + i * cols + j);
        }
    }

    add_matrices(mat1, mat2, result, rows, cols);

    // Displaying matrices
    printf("\nMatrix 1:\n");
    display_matrix(mat1, rows, cols);

    printf("\nMatrix 2:\n");
    display_matrix(mat2, rows, cols);

    printf("\nResultant Matrix:\n");
    display_matrix(result, rows, cols);

    free(mat1);
    free(mat2);
    free(result);

    return 0;
}