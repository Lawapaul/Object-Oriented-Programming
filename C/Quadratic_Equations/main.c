#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    printf("Enter a,b,c in format (a b c) ");
    scanf("%d %d %d",&a,&b,&c);
    int final=(b*b)-(4*a*c);
    int determinant = sqrt((b*b)-(4*a*c));
    printf("Determinant is %d\n",final);
    if (final>0){
        float root1= ((-b)+determinant)/2*a;
        float root2= ((-b)-determinant)/2*a;
        printf("Root 1: %.2f\n",root1);
        printf("Root 2: %.2f",root2);
    }
    else if (final==0){
         float root1= ((-b)+determinant)/2*a;
         printf("Both Roots are: %.2f\n",root1);
    }
    else if (final<0){
        int final1=(-1)*final;
        int determinant1=sqrt(final1);
        float real=(-b)/(2*a);
        float imaginary=(determinant1)/(2*a);
        printf("Root 1: %.2f+i%.2f\n",real,imaginary);
        printf("Root 2: %.2f-i%.2f",real,imaginary);
    }
}