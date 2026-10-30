#include <stdio.h>
int main(){
    //Initialize Matrix
    int array[3][3];
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            scanf("%d",&array[i][j]);
        }
    }
    //Print Matrix
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Sum of Rows
    for (int i=0;i<3;i++){
        int count=0;
        for (int j=0;j<3;j++){
            count+=array[i][j];
        }
        printf("Sum of Row %d is %d\n",i+1,count);
    }
    printf("\n");

    //Sum of Columns
    for (int i=0;i<3;i++){
        int count=0;
        for (int j=0;j<3;j++){
            count+=array[j][i];
        }
        printf("Sum of Column %d is %d\n",i+1,count);
    }
    printf("\n");
    //Maximum element in Row
    for (int i=0;i<3;i++){
        int max=0;
        for (int j=0;j<3;j++){
            if (max<array[i][j]){
                max=array[i][j];

            }
        }
        printf("Maximum element of Row %d is %d\n",i+1,max);
    }
    printf("\n");
    //Minimum element in Column
    for (int i=0;i<3;i++){
        int min=array[i][0];
        for (int j=0;j<3;j++){
            if (min>array[i][j]){
                min=array[i][j];

            }
        }
        printf("Minimum element of Row %d is %d\n",i+1,min);
    }
    printf("\n");

    //Diagonals - Right
    printf("Diagonals Right to Left: ");
    for (int i=0;i<3;i++){
        printf("%d ",array[i][i]);
    }

    //Diagonals - Left
    printf("\n");
    printf("Diagonals Left to Right: ");
    for (int i=0;i<3;i++){
        printf("%d ",array[i][2-i]);
    }




}