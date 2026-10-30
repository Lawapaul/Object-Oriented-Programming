#include <stdio.h>

int main(){
    int matrix[3][3];
    int matrix1[3][3];
    int matrix2[3][3];
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            scanf("%d",matrix[i][j]);
        }
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            scanf("%d",matrix1[i][j]);
        }
    }
    printf("Matrix 1:\n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d",matrix1[i][j]);
        }
        printf("\n");
    }
    
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            matrix2[i][j]=matrix[i][j]+matrix1[i][j];
        }
    }
    printf("Matrix Addtion:\n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d",matrix2[i][j]);
        }
        printf("\n");
    }
        
    

}