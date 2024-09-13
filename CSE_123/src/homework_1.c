/*
    Name: MD SUZON MIA
    ID: 241-15-717
    Task: Write a C program to -
            Create a linked list "main"
                Insert nodes at the beginning of the list on "main"
                Insert nodes at the end of the list on "main"
            (using functions)
*/

#include <stdio.h>
#include <stdlib.h>

// create structure
struct node{
    int data;
    struct node* next; 
};

// function crorcreating a node
struct node* create_node(int data){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node; // return node adress
}

// Insert nodes at the beginning of the list.
struct node* add_top(struct node* head, int data){
    struct node* temp = create_node(data);
    temp -> next = head;
    return temp;
}

// Function to print all node
void print_list(struct node* head){
    struct node* temp_p = head;
    while(temp_p != NULL){
        printf("%d --> ", temp_p ->data);
        temp_p = temp_p -> next;
    }
    printf("END\n");
}

// free memory
void free_mem(struct node* head){
    struct node* now;
    now = head;
    while(now != NULL){
        free(now);
        now = now ->next;
    }
}


int main() {
    // --create 10 node--
    struct node* head = create_node(100); // create head node
    struct node* now = head;
    struct node* temp;

    // create rest 9 node
    for(int i = 2; i <= 10; i++){
        now -> next = create_node (i*100);
        now = now ->next; 
    }

    printf("Main link        ");
    print_list(head); //print the list

    temp = add_top(head, 50); // add link(50) at first in main link
    printf("Add to top       ");
    print_list(temp); //print the list
    free(temp);

    now -> next = create_node(5000); // add link(5000) at end in main link
    printf("Add to end       ");
    print_list(head); //print the list    

    free_mem(head); // Free memory

    return 0;
}

