#include <stdio.h>

int main(){
    float w,h;
    printf("Enter Weight: ");
    scanf("%f",&w);
    printf("Enter Height: ");
    scanf("%f",&h);
    float d=h*h;
    float e=w/d;
    if (e<=18.5){
        printf("Underweight");
    }
    else if((e>18.5)&&(e<=24.9)){
        printf("Normal");
    }
    else if((e>24.9)&&(e<=29.9)){
        printf("Overweight");


    }
    else{
        printf("Obese");
    }
}