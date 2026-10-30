#include <stdio.h>

int main(){
    int a;
    printf("Enter Size of Array: ");
    scanf("%d",&a);
    int array1[a];
    int arrayc[a];
    for (int i=0;i<a;i++){
        printf("Enter Array Element %d: ",i+1);
        scanf("%d",&array1[i]);
        arrayc[i]=-1;
    }
    for (int i=0;i<a;i++){
        int count=1;
        for (int j=i+1;j<a;j++){
            if (array1[i]==array1[j]){
                count+=1;
                arrayc[j]=0;
            }
        }
        if (arrayc[i]!=0){
            arrayc[i]=count;
        }
    }
    for (int i=0;i<a;i++){
        printf("%d\n",arrayc[i]);
    }
    

}