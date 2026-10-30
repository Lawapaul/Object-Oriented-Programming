#include <stdio.h>
struct time{
    int h,m,s,ss,mm;   
};
struct time mai;
int main(){
    scanf("%d %d %d",&mai.h,&mai.m,&mai.s);
    mai.ss=mai.s/60;
    printf("%d\n",mai.s/60);
    if(mai.ss>0){
        mai.m=mai.m+mai.ss;
        mai.s-=mai.ss*60;
    }
    if(mai.m>60){
        mai.mm=mai.m/60;
        mai.h+=mai.mm;
        mai.m-=mai.mm*60;
    }

        printf("%dH:%dM:%dS",mai.h,mai.m,mai.s);
    }
   
