#include <stdio.h>


struct book{
    char title[50];
    char name[50];
    char publication[50];
    int price;
};
struct book display;
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s",&display.title);
        scanf("%s",&display.name);
        scanf("%s",&display.publication);
        scanf("%d",&display.price);
        printf("\nBook %d Data:\n",i+1);
        printf("Title: %s\n",display.title);
        printf("Author Name: %s\n",display.name);
        printf("Publication: %s\n",display.publication);
        printf("Price: %d\n",display.price);
        printf("\n");
    }
}