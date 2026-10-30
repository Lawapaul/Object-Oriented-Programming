#include <stdio.h>

int SPECIAL_NUMBER(int);
int main(){
    int a;
    scanf("%d",&a);
    return SPECIAL_NUMBER(a);

}
int SPECIAL_NUMBER(int a){
    int temp=a;
    int rev,digit;
    int last=a%10;
    int count=0;
    while(a!=0){
        a=a/10;
        count+=a%10;
    }
    if(last==count){
        printf("THIS IS A SPECIAL NUMBER");
    }
    else{
        printf("THIS IS NOT A SPECIAL NUMBER. ");
    }
    return 0;
}
