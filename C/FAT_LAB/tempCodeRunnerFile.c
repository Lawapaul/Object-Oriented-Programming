#include <stdlib.h>
// #include <stdio.h>

// struct Queue{
//     int size;
//     int f;
//     int r;
//     int* arr;
// };
// int isFull(struct Queue* q){
//     if(q->r==q->size-1){
//         return 1;
//     }
//     return 0;
// } 
// void enque(struct Queue* q,int data){
//     if(isFull(q)){
//         printf("Queue is Full\n");
//         return;
//     }
//     else{
//         if(q->f==-1){
//             q->f=0;
//         }
//         q->r++;
//         q->arr[q->r]=data;
       
//     }
// }
// int isEmpty(struct Queue* q){
//     return q->f==-1;
// }
// int deque(struct Queue* q){
//     if(isEmpty(q)){
//        return -1;
//     }
//     if(q->f==q->r){
//         q->f=q->r=-1;
//     }
//     else{
//         q->f++;
//     }
//     return q->arr[q->r];
    
// }
// void display(struct Queue* q){
//     for(int i=q->f;i<=q->r;i++){
//         printf("%d ",q->arr[i]);
//     }
    
// }
// int main(){
//     struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
//     int a;
//     q->size=5;
//     q->f=0;
//     q->f=0;
//     q->arr=(int*)malloc(q->size*sizeof(int));
//     for(int i=0;i<4;i++){
//         scanf("%d",&a);
//         enque(q,a);
//     }
//     display(q);

// }
