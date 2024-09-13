#include <stdio.h>
#include <stdlib.h>

// 10 - 20 - 30 - 40 -50 

// create a stracture node
struct node{
    int data;
    struct node* next;
};

void traversal(struct node* ptr){
    while(ptr != NULL){
        printf("%d <=> ", ptr ->data);
        ptr = ptr -> next;
    }
    
}


int main() {
    // create a head node
    struct node* head;

    // dynamicly alocate memory for head
    head = (struct node *)malloc(sizeof(struct node));

    // "links" node
    struct node* first;
    struct node* second;
    struct node* third;
    struct node* forth;
    struct node* fifth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = forth;

    forth -> data = 40;
    forth -> next = fifth;

    fifth -> data = 50;
    fifth -> next = NULL;

    traversal(head);


    
    
    return 0;
}