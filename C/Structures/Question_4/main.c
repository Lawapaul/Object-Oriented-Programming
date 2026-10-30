#include <stdio.h>
#include <string.h>
struct person{
    char name[50][10];
    char team[50][10];
    int average[10];
};
struct person data;
int main(){
    int a=10;
    for(int i=0;i<a;i++){
        scanf("%s",&data.name[i]);
        scanf("%s",&data.team[i]);
        scanf("%d",&data.average[i]);
    }
    printf("\n");
      for ( int i = 0; i < a; i ++)  {  
        for ( int j = i + 1; j < 10; j++)  {  
            if (strcmp(data.team[i],data.team[j])==0)  {  
                for (int k = j; k < a - 1; k++){  
                    data.team[k] = data.team[k + 1];  
                }  
                a--;  
                     
            }
            j--;   
        }  
    }  

}