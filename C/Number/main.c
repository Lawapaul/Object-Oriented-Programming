#include <stdio.h>

int main(){
    int a;
    printf("Enter Number of Inputs: ");
    scanf("%d",&a);
    int num[a];
    for (int i=0;i<a;i++){
        printf("Enter Number %d: ",i+1);
        scanf("%d",&num[i]);
    }
    for (int i=0;i<a;i++){
        if (num[i]<=9){
            switch (num[i])
            {
                case 1:
                printf("One\n");
                break;
                case 2:
                printf("Two\n");
                break;
                case 3:
                printf("Three\n");
                break;
                case 4:
                printf("Four\n");
                break;
                case 5:
                printf("Five\n");
                break;
                case 6:
                printf("Six\n");
                break;
                case 7:
                printf("Seven\n");
                break;
                case 8:
                printf("Eight\n");
                break;
                case 9:
                printf("Nine\n");
                break;
            }
        }
        else if(num[i]%2==0){
            printf("Even\n");
        }
        else{
            printf("Odd\n");
        }


    }
}

