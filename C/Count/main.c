    #include <stdio.h>

    int main(){
        int num,digit;
        printf("Enter Number: ");
        scanf("%d",&num);
        int count=0;
        while (num!=0){
            digit=num%10;
            count+=1;
            num/=10;

        }
        printf("No of Digits are %d",count);
    }