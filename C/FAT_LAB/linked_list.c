#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};
struct node* push(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
}
struct node* pop(struct node* head){
    if(head==NULL){
        return NULL;
    }
    else{
        head=head->next;
    }
    return head;
}
struct node* push_end(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    struct node* ptr=head;
    if(head==NULL){
        return temp;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
struct node* pop_end(struct node* head){
    struct node* ptr=head;
    if(head==NULL){
        return head;
    }
    else if(head->next==NULL){
        head=head->next;
    }
    else{
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=NULL;
    }
    return head;
}
void print(struct node* head){
    if(head==NULL){
        return;
    }
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
struct node* insert_middle(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        return head;
    }
    else{
        while(ptr!=NULL && ptr->data!=30){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return head;
} 
struct node* delete_middle(struct node* head){
    struct node *ptr=head;
    struct node* q=NULL;
    while(ptr->next!=NULL && ptr->data!=30){
        q=ptr;
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        q->next=ptr->next;
    }
    return head;
    
}
struct node* sort(struct node* head){
    struct node* ptr;
    struct node* ptr1;
    int temp;
    for(ptr=head;ptr!=NULL;ptr=ptr->next){
        for(ptr1=ptr;ptr!=NULL;ptr1=ptr1->next){
           if (ptr1->data < ptr->data){
            temp=ptr->data;
            ptr->data=ptr1->data;
            ptr1->data=temp;
           }
        }
    }
    return head;
}
int main(){
    struct node* head=NULL;
    int a,b;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        head=push_end(head,b);
    }
    head=insert_middle(head,40);
    head=delete_middle(head);
    print(head);
    printf("\n");
    head=sort(head);
    print(head);

    return 0;
}
