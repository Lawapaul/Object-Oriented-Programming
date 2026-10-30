#include <stdlib.h>
#include <stdio.h>

struct Queue{
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct Queue* q){
    return q->f==q->size-1;
}
int isEmpty(struct Queue* q){
    return q->f==-1;
}
void enque(struct Queue* q,int data){
    if(isFull(q)){
        printf("Queue is Full");
        return;
    }
    if(q->f==-1){
        q->f=0;
    }
    q->r++;
    q->arr[q->r]=data;
}
void deque(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty");
        return;
    }
    if(q->f==q->r){
        q->f=q->r=-1;
    }
    q->f++;

}
void display(struct Queue* q){
    for(int i=q->f;i<=q->r;i++){
        printf("%d ",q->arr[i]);
    }
}
int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->f=-1;
    q->r=-1;
    q->size=4;
    q->arr=(int*)malloc(q->size*sizeof(struct Queue));
    int b;
    int count=0;
    while(scanf("%d",&b) && b!=-1){
        enque(q,b);
        count++;
        if(count==q->size-1){
            q->size*=2;
            q->arr=(int*)realloc(q->arr,q->size*sizeof(int));
        }
    }
    display(q);
}