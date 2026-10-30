#include <stdio.h>

int main(){
    float unit;
    printf("Enter Totals Units Consumed: ");
    scanf("%f",&unit);
    if (unit>300){
        float remain=(unit-300);
        float cost=(remain*1.5);
        float total=cost+320;
        printf("Total Electricity Bill is %f",total);

    }
    else if (unit>100 && unit <300){
        float remain=(unit -100);
        float cost=(remain*1.20);
        float total=(cost+80);
        printf("Total Electricity bill is %f",total);
    }
    else if (unit>0 && unit <100){
        float cost=unit*0.80;
        printf("Total Electricity Bill is %f",cost);
    }
    
}