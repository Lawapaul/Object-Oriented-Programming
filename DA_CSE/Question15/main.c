#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    char arr[a][b][1];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%c",&arr[i][j]);
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }

}