#include <stdlib.h>
#include <stdio.h>

struct dnode{
    struct dnode* prev;
    int data;
    struct dnode* next;
};

struct dnode* push(struct dnode* head,int ele){
    struct dnode* temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=ele;
    if(head==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{
        struct dnode* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        temp->next=NULL;
        ptr->next=temp;
        temp->prev=ptr;
    }
    return head;
}
void display(struct dnode* head){
    struct dnode*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct dnode* push_pop(struct dnode* head){
    struct dnode* ptr=head;
    struct dnode* temp=(struct dnode*)malloc(sizeof(struct dnode));
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp->data=ptr->data;
    temp->prev=NULL;
    temp->next=head;
    head=temp;
    ptr->prev->next=NULL;
    return head;
}
int main(){
    int b;
    struct dnode* head=NULL;
    for(int i=0;i<5;i++){
        scanf("%d",&b);
        head=push(head,b);
    }
    printf("\n");
    display(head);
    printf("\n");
    for(int i=0;i<3;i++){
        head=push_pop(head);
    }
    display(head);
}