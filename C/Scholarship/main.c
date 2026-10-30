#include <stdio.h>

int main(){
    float e,m,p,l,c,cs;
    char m;
    int count;
    printf("Enter Gender(M/F): ");
    scanf("%c",&m);
    printf("Enter Marks in English: ");
    scanf("%f",&e);
    printf("Enter Marks in Maths: ");
    scanf("%f",&m);
    printf("Enter Marks in Physics: ");
    scanf("%f",&p);
    printf("Enter Marks in Language: ");
    scanf("%f",&l);
    printf("Enter Marks in Chemistry: ");
    scanf("%f",&c);
    printf("Enter Marks in Computer Science: ");
    scanf("%f",&cs);
    float total=(e+m+p+l+c+cs);
    float pert=(total/6)*100;
    if ((e>=90),(m>=90),(p>=90),(l>=90),(c>=90),(cs>=90)){
        printf("Pragati Scholorship");
        count+=1;
    }
    else if (m>=80){
        printf("Ramanujan Scholorship");
        count+=1;
    }
    else if ((p>=90) && (m>=90))
    {
        printf("Einstein Scholorship");
        count+=1;
    }
    else if((cs>=85)&&(cs<95)){
        printf("Gaurav Foundation Scholorship");
        count+=1;
    }
    else if((e>=75)&&(cs<85)){
        printf("Shakespeare Scholorship");
        count+=1;
    }
    else if((m=='F')&&(c>=90)){
        printf("Prathiba Memorial Scholorship");
        count+=1;
    }
    else if((pert>70 && (e>50),(m>50),(p>50),(l>50),(c>50),(cs>50))){
        if(count>2){
            printf("Genius Kid Scholarship");
        }
    }



}


