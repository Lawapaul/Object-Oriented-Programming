#include <stdio.h>

struct time{
    int h,m,s;
};
struct time call;
int main(){
    scanf("%d %d %d",&call.h,&call.m,&call.s);
    int count=0;
    while(call.s>60){
        call.s-=60;
        count+=1;
    }
    call.m+=count;
    int count1=0;
    while(call.m>60){
        call.m-=60;
        count1+=1;
    }
    call.h+=count1;
    printf("Time is:\n");
    printf("%dHH:%dMM:%dSS",call.h,call.m,call.s);
}