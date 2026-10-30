#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *push(struct node *head,int a){
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=head;
    head=temp;
    return head;
}

void display(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node *pop(struct node *head){
    head=head->next;
    return head;
}
