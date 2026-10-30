#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a];
    int arr1[b];
    int arrf[a+b];
    for (int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<b;i++){
        scanf("%d",&arr1[i]);
    } 
    
    for (int i=0;i<a-1;i++){
        for (int j=0;j<a-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for (int i=0;i<b-1;i++){
        for (int j=0;j<b-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                int temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
    printf("Array 1:\n");
    for (int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
    printf("\nArray 2:\n");
    for (int i=0;i<b;i++){
        printf("%d ",arr1[i]);
    }
    for (int i=0;i<a;i++){
        arrf[i]=arr[i];
    }
    
    for (int i=a;i<a+b;i++){
        arrf[i]=arr1[i-a];
    }
    printf("\nFinal Sorted Array:\n");
    for (int i=0;i<a+b;i++){
        printf("%d ",arrf[i]);
    }
}