/*
    Name: MD SUZON MIA
    ID: 241-15-717
    Task: delet n point
*/

#include <stdio.h>
#include <stdlib.h>

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
// delet head node
struct node* delet_head(struct node* head){
    struct node* temp = head;
    head = head->next;
    free(temp);
    return(head);
}

// delete n node 
void delet_node(struct node* head, int point) {
    struct node* temp = head;
    struct node* prev = NULL;
    int count = 1;

    while (temp != NULL && count < point) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
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

    int delet_nde_n = 2; // Point to be deleted (1-index)

    printf("\nPlease enter 'n' you want to Delete (index) 1 to 10 (1 is HEAD)\n");
    scanf("%d", &delet_nde_n);

    // if the point is 1 to delete the head
    if (delet_nde_n == 1) {
        head = delet_head(head);
    } else {
        delet_node(head, delet_nde_n);
    }

    printf("Main link        ");
    print_list(head); //print the list
    

    free_mem(head); // Free memory

    return 0;
}

