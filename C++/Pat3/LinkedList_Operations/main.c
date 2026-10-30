#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

void display(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node *insertAtBeginning(struct node *head,int a){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=head;
    head=temp;
    return temp;
}

struct node *insertAtEnd(struct node *head,int a){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    ptr->next=temp;
    return head;
}
struct node *insertAtMiddle(struct node *head,int a,int b){
    struct node *ptr=head;
    while(ptr->next!=NULL && ptr->data!=a){
        ptr=ptr->next;
    }
    if(ptr->next!=NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=b;
        temp->next=ptr->next;
        ptr->next=temp;
        return head;
    }else{
        printf("Element Not Found");
    }
}

struct node *deleteatBeginning(struct node *head){
    head=head->next;
    return head;
}
struct node *deleteatEnd(struct node *head){
    struct node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return head;
}
struct node *deleteatMiddle(struct node *head,int a){
    struct node* ptr=head;
    struct node* q=NULL;
    while(ptr->next!=NULL && ptr->data){
        q=ptr;
        ptr=ptr->next;
    }
    q->next=ptr->next;
    return head;
}
struct node* reverse(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* prev=NULL;
    struct node* curr=NULL;
    struct node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next
    }
    head=prev;
    return head;
}