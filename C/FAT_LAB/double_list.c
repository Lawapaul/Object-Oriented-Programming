#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* push(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=head;
    head=temp;
    return head;
}
struct node* push_end(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        return temp;
    }
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}
struct node* pop(struct node* head){
    if(head==NULL){
        return NULL;
    }
    head=head->next;
    head->prev=NULL;
    return head;
}
struct node* pop_end(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node* ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    return head;
}
struct node* push_middle(struct node* head,int data,int ele){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    temp->data=data;
    if(head==NULL){
        return temp;
    }
    struct node* ptr=head;
    while(ptr->next!=NULL && ptr->data!=ele){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;
    return head;

}
struct node* pop_middle(struct node* head,int ele){
    struct node* ptr=head;
    struct node* q;
    if(head==NULL){
        return NULL;
    }
    while(ptr->next!=NULL && ptr->data!=ele){
        q=ptr;
        ptr=ptr->next;
    }
    q->next=ptr->next;
    ptr->prev=q;
    return head;

}
void print(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void sort(struct node* head){
    struct node* ptr;
    struct node* q;
    int temp;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        for(q=ptr->next;q!=NULL;q=q->next){
            if(ptr->data > q->data){
                temp=ptr->data;
                ptr->data=q->data;
                q->data=temp;
            }
        }
    }
}
int main(){
    int a,b;
    scanf("%d",&a);
    struct node* head=NULL;
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        head=push_end(head,b);
    }
    head=pop_end(head);
    head=push_middle(head,4,3);
    head=pop_middle(head,5);
    sort(head);
    print(head);
}