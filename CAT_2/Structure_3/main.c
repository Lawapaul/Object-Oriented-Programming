#include <stdio.h>
struct address{
    int hno;
    char area[20];
    char city[20];
};
struct student{
    char name[20];
    int roll;
    float gpa;
    struct address call;
};
struct student data;
int main(){
    scanf("%s %d %f",&data.name,&data.roll,&data.gpa);
    scanf("%d %s %s",&data.call.hno,&data.call.area,&data.call.city);
    printf("Student Data:\n");
    printf("%s\n%d\n%f\n%d\n%s\n%s",data.name,data.roll,data.gpa,data.call.hno,data.call.area,data.call.city);
}