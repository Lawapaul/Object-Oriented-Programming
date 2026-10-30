#include <stdio.h>
struct person{
    char name[50][5];
    char date[50][5];
    int salary[5];
};
struct person data;
int main(){
    int a=5;
    for(int i=0;i<a;i++){
        scanf("%s",&data.name[i]);
        scanf("%s",&data.date[i]);
        scanf("%d",&data.salary[i]);
    }
    for(int i=0;i<a;i++){
        printf("\nEmployee %d Data: \n",i+1);
        printf("Name: %s\n",data.name[i]);
        printf("Date of Joining: %s\n",data.date[i]);
        printf("Salary: %d\n",data.salary[i]);
    }


}