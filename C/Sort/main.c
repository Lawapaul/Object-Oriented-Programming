#include <stdio.h>

int main(){
    int a;
    printf("Enter Size of Array: ");
    scanf("%d",&a);
    int array1[a];
    for (int i=0;i<a;i++){
        printf("Enter Element %d: ",i+1);
        scanf("%d",&array1[i]);
    }
    for (int i=0;i<a;i++){
        for (int j=0;i<a;j++){
            if (array1[j]>array1[j+1]){
                int temp=array1[j];
                array1[j]=array1[j+1];
                array1[j+1]=temp;
            }
        }
    }
    for (int i=0;i<a;i++){
        printf("%d ",array1[i]);
    }

}