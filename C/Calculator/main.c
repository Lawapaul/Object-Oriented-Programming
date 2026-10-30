#include <stdio.h>
#include <string.h>

int add(int,int);
int sub(int,int);
int multiplication(int,int);
int division(int,int);
int main(){
    char a;
    int c,d;
    printf("Enter Operation: ");
    scanf("%c",&a);
    printf("Enter Number 1: ");
    scanf("%d",&c);
    printf("Enter Number 2: ");
    scanf("%d",&d);
    if(a=='+'){
        return add(c,d);
    }
    else if(a=='-'){
        printf("%d",sub(c,d));
    }
    else if(a=='*'){
        printf("%d",multiplication(c,d));
    }
    if(a=='/'){
        printf("%d",division(c,d));
    }
}
int add(int x,int y){
    return x+y;
}
int sub(int x,int y){
    return x-y;
}
int multiplication(int x,int y){
    return x*y;
}
int division(int x,int y){
    return x/y;
}
