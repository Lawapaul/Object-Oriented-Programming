#include <stdio.h>

int main(){
    int a;
    printf("1. Circle\n2. Rectangle\n3. Square\n4. Triangle\nEnter Choice: ");
    scanf("%d",&a);
    if (a==1){
        float pi=3.14;float radius;double area;
        printf("Enter Radius of Circle: ");
        scanf("%f",&radius);
        area=pi*(radius*radius);
        printf("Area of Circle is %lf",area);   
    }
    else if(a==2){
        float a,b;
        printf("Enter Length: ");
        scanf("%f",&a);
        printf("Enter Breath: ");
        scanf("%f",&b);
        double area=a*b;
        printf("Area of Rectangle is %lf",area);
        
    }
    else if(a==3){
        float a;
        printf("Enter Side Length: ");
        scanf("%f",&a);
        double area=a*a;
        printf("Area of Square is %lf",area);
    }
    else{
        float a,b;
        printf("Enter Height: ");
        scanf("%f",&a);
        printf("Enter Base: ");
        scanf("%f",&b);
        double area=(a*b)*0.5;
        printf("Area of Rectangle is %lf",area);

    }
}
