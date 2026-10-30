#include <stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    int arr[a];
    for (int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int arr1[a];
    for (int i=0;i<a;i++){
        arr1[i]=arr[i];
    }
    printf("\n");
    printf("Original Array:\n");
    for (int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
    int j=0;
    for (int i=0;i<a;i++){
        
        if (arr1[i]%2!=0){
            arr[j]=arr1[i];
            j+=1;
        }
        else{
            continue;
        }
    }
    for (int i=0;i<a;i++){
        if (arr1[i]%2==0){
            arr[j]=arr1[i];
            j+=1;
        }
        else{
            continue;
        }
    }
    printf("\n");
    printf("Final Sorted Array:\n");
    for (int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }

}