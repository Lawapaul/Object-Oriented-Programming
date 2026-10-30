#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a],arr1[b],arr2[a+b];
    for (int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<b;i++){
        scanf("%d",&arr1[i]);
    }
    for (int i=0;i<a;++i){
        for (int j=0;j<a-i-1;++j){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("Sorted array 1:\n");
    for (int i=0;i<a;i++){
        printf("%d " ,arr[i]);
    }

    for (int i=0;i<a;++i){
        for (int j=0;j<a-i-1;++j){
            if (arr1[j]>arr1[j+1]){
                int temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;

            }
        }
    }
    printf("\nSorted Array 2:\n");
    for (int i=0;i<b;i++){
        printf("%d " ,arr1[i]);
    }
    




}