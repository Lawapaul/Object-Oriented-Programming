#include <stdlib.h>
#include <stdio.h>
int main(){
    int *ptr;
    int *ptr1;
    ptr=(int*)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        scanf("%d",(ptr+i));
    }
    printf("\nOriginal Array:\n");
    for(int i=0;i<5;i++){
        printf("%d ",ptr[i]);
    }
    int a;
    scanf("%d",&a);
    ptr1=(int*)realloc(ptr,(5+a)*sizeof(int));
    for(int i=5;i<5+a;i++){
        scanf("%d",(ptr1+i));
    }
    printf("\nNew Array:\n");
    for(int i=0;i<5+a;i++){
        printf("%d ",ptr1[i]);
    }
}