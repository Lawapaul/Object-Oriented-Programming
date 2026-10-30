#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 100
int push(int arr[],int data,int size){
    arr[size]=data;
    return size+1;
}
int pop(int arr[],int size){
    size=size-1;
    return arr[size];
}
int postfix(char* exp){
    int stack[MAX];
    int size=0;
    for(int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            size=push(stack,exp[i]-'0',size);
        }
        else{
            int op1=pop(stack,size);
            size--;
            int op2=pop(stack,size);
            size--;
            int result;
            switch(exp[i]){
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                default:
                    result=0;
                    break;
            }
            size=push(stack,result,size);
        }
       
    }
     return pop(stack,size);
}
int main(){
    char a[MAX];
    scanf("%s",a);
    int result=postfix(a);
    printf("%d",result);
}