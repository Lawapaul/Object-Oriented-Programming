
#include <stdio.h>

int main(){
    float x;
    printf("Enter Salary: ");
    scanf("%f",&x);
    if ((x>=1)&&(x<=4000)){
        float hra=0.1* x;
        float da=0.5*x;
        float gross=(hra+da+x);
        printf("Gross Salary is %.2f%%",gross);
        
    }
    else if ((x>=4001)&&(x<=8000)){
        float hra=0.2* x;
        float da=0.6*x;
        float gross=(hra+da+x);
        printf("Gross Salary is %.2f%%",gross);

    }
    else if ((x>=8001)&&(x<=12000)){
        float hra=0.25* x;
        float da=0.7*x;
        float gross=(hra+da+x);
        printf("Gross Salary is %.2f%%",gross);
    }
    else{
        float hra=0.3* x;
        float da=0.8*x;
        float gross=(hra+da+x);
        printf("Gross Salary is %.2f%%",gross);
}
}