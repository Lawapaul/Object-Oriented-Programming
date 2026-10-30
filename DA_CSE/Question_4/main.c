#include <stdio.h>
#include <string.h>
int main(){
    char a[100];
    int count,f,m,l,l1;
    gets(a);
    for (int i=0;i<strlen(a);i++){
        if(a[i]==' '){
            count+=1;
        }
    }
    if (count==1){
        printf("%c.",a[0]);
        for (int i=0;i<strlen(a);i++){
        if(a[i]==' '){
            m=i+1;
        }    
    }
    for(int i=m;i<strlen(a);i++){
        printf("%c",a[i]);
    }
    }
    else if(count==2){
        printf("%c.",a[0]);
        for(int i=0;i<strlen(a);i++){
            if(a[i]==' '){
                l=i+1;
                l1+=1;
                break;               
            }
        }
        printf("%c.",a[l]);
        l1=0;
        for(int i=0;i<strlen(a);i++){
            if(a[i]==' '){
                l=i+1;
            }
        }
        for(int j=l;j<strlen(a);j++){
            printf("%c",a[j]);
        }

    }

}