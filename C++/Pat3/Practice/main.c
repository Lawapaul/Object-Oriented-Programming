#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node* next;
};

struct node* push(int a,struct node* head){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    if(head==NULL){
        temp->next=NULL;
        head=temp;
        return head;
    }
    else{
        temp->next=head;
        head=temp;
        return head;
    }

}
struct node* remove_even(struct node* head) {
    struct node* ptr = head;
    struct node* prev = NULL;

    // Handle the case where the head contains even numbers
    while (ptr != NULL && (ptr->data) % 2 == 0) {
        struct node* temp = ptr;
        head = ptr->next;  // Move the head forward
        ptr = head;  // Move to the next node
        free(temp);  // Free the removed node
    }

    // Traverse and remove even numbers from the rest of the list
    while (ptr != NULL) {
        if (ptr->data % 2 == 0) {
            prev->next = ptr->next;  // Remove the even node by updating the previous node's next pointer
            free(ptr);  // Free the removed node
            ptr = prev->next;  // Move to the next node
        } else {
            prev = ptr;  // Move the previous pointer forward
            ptr = ptr->next;  // Move the current pointer forward
        }
    }

    return head;  // Return the updated head of the list
}
struct node* pop(struct node* head){
    head=head->next;
    return head;

}
void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
struct node* remove_odd(struct node* head){
    struct node* ptr = head;
    struct node* prev = NULL;
    while(ptr != NULL && ptr->data % 2 != 0){
        struct node* temp = ptr;
        head = ptr->next;
        ptr = head;
        free(temp);
    }
    while(ptr != NULL){
        if(ptr->data % 2 != 0){
            prev->next = ptr->next;
            free(ptr);
            ptr = prev->next;
        }else{
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}

struct node* merge(struct node* head1, struct node* head2){
    struct node* ptr=head1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=head2;
    return head1;
}
int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
    head1=push(1,head1);
    head1=push(2,head1);
    head1=push(3,head1);
    head1=push(4,head1);
    head1=push(5,head1);
    head1=push(6,head1);

    head2=push(7,head2);
    head2=push(8,head2);
    head2=push(9,head2);
    head2=push(10,head2);
    head2=push(11,head2);
    head2=push(12,head2);

    head1=remove_even(head1);
    head2=remove_odd(head2);
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    merge(head1,head2);
    display(head1);
    
    

}


