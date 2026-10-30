#include <stdio.h>

struct student{
    char name[10][50];
    char branch[10][50];
    int marks[10];
};
struct student call;
int main(){
    printf("Enter data in format (Name Branch Marks): ");
    for(int i=0;i<10;i++){
        scanf("%s %s %d",&call.name[i],&call.branch[i],&call.marks[i]);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%s %s %d\n",call.name[i],call.branch[i],call.marks[i]);
    }
}