#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    gets(str);
    int count;
    for (int i=0;i<strlen(str);i++){
        if(str[i]==' '){
            count+=1;
        }
    }
    int arr[count+1];
    int count1,l;
    int j=0;
    for (int i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            count1+=1;
        }
        else{
            l=i+1;
            arr[j]=count1;
            count1=0;
            j++;
        }
        
        
    }
    int count2;
    for (int i=l;i<strlen(str);i++){
        count2+=1;
    }
    arr[count]=count2;
    int max=arr[0];
    int max1;
    for(int i=0;i<count+1;i++){
        if (arr[i]>max){
            max=arr[i];
            max1=i;
        }
        }
    int count3,ls;
        for (int i=0;i<strlen(str);i++){
            if(str[i]==' '){
                count3+=1;
                if(count3==max1){
                    ls=i+1;
                    break;
                }
            }
        }
        for(int i=ls;i<strlen(str);i++){
            printf("%c",str[i]);
        if(str[i]==' '){
            break;
        }
     }
}    

    