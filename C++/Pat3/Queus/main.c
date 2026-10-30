#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* f = NULL;  
struct node* rear = NULL; 

// Enqueue function to insert elements into the queue
void enque(int a) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    
    temp->data = a;
    temp->next = NULL;
    
    if (f == NULL) {
        f = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// 
void deque() {
    if (f == NULL) {
        printf("UNDERFLOW\n");
        return;
    }
    struct node *temp = f;
    f = f->next;

    free(temp);

    if (f == NULL) {
        rear = NULL;
    }
}

// Display function to print the elements of the queue
void display() {
    struct node *ptr = f;
    if (f == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");  // Print newline at the end for better formatting
}

int main() {
    // Enqueue some elements
    enque(14);
    enque(15);
    enque(16);
    enque(17);

    // Display the queue
    printf("Queue after enqueuing elements: ");
    display();

    // Dequeue some elements
    deque();
    printf("Queue after dequeuing one element: ");
    display();

    deque();
    printf("Queue after dequeuing another element: ");
    display();

    return 0;
}
