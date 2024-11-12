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
void free_mem(struct node* head) {
    struct node* now;
    while (head != NULL) {
        now = head;
        head = head->next;
        free(now);
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

// problem
    #include <stdio.h>

int main(){
    int testcase;
    long long int x, y, a, b;
    long long int n, m, r, c;
    int linear_move, vertical_move;
    int ans = 0;

    scanf("%d", &testcase);

    for(int i = 0; i < testcase; i++){
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);

        ans = (y * (x - a)) + ((y - 1) * (x - a)) + (y - b);
        
        printf("My anser %lld\n", ans);
    }
}

//queue
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// creating a new queue element
struct node* new_queue_element(int data){
    struct node* new_queue_element = (struct node*)malloc(sizeof(struct node));
    new_queue_element->data = data;
    new_queue_element->next = NULL;

    return new_queue_element;
}

void print_queue(struct node* front, int *size_queue){

    printf("   _         _   Size of queue - %d\n", *size_queue);
    printf("    |       |   \n");
    printf("    |       |   \n");

    while(front != NULL){
        if(front->data >= 0 && front->data <= 9) {
            printf("    |-------|   \n");
            printf("    |   %d   |   \n", front->data);
        } else if(front->data > 9 && front->data <= 99) {
            printf("    |-------|   \n");
            printf("    |  %d   |   \n", front->data);
        } else if(front->data > 99 && front->data <= 999) {
            printf("    |-------|   \n");
            printf("    |  %d  |   \n", front->data);
        } else {
            printf("    |-------|   \n");
            printf("    | %d |   \n", front->data);
        }
        front = front->next;
    }

    printf("    |-------|   \n");
    printf("    |       |   \n");
    printf("    |       |   \n");
    printf("   _         _  \n");
}

struct node* free_memory(struct node* front, int n, int* size_queue){
    struct node* temp;

    for(int i = 0; i < n && front != NULL; i++){
        temp = front;
        front = front->next;
        free(temp);
        (*size_queue)--;
    }

    return front;
}

int main(){
    int size_queue = 0;
    struct node* front = NULL;
    struct node* rear = NULL;
    int input = -1;

repeat:

    printf("Clearing the terminal...\n");
    system("cls");

    print_queue(front, &size_queue);

    printf("\n\n-----------------------------------------------------------\n\n");

    printf("0. Exit\n");
    printf("1. Enqueue 10 elements '1 to 10'\n");
    printf("2. Enqueue 'n' elements\n");
    printf("3. Dequeue '1' element\n");
    printf("4. Dequeue 'n' elements\n\n==> ");

    scanf("%d", &input);

    if(input == 1){
        for(int i = 1; i <= 10; i++){
            struct node* new_element = new_queue_element(i);

            if(rear == NULL) {
                front = rear = new_element;
            } else {
                rear->next = new_element;
                rear = new_element;
            }

            size_queue++;
        }
    }

    if(input == 2){
        int n, element;
        printf("How many elements you want to enqueue\n ==> ");
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            printf("  ==> ");
            scanf("%d", &element);

            struct node* new_element = new_queue_element(element);

            if(rear == NULL) {
                front = rear = new_element;
            } else {
                rear->next = new_element;
                rear = new_element;
            }

            size_queue++;
        }
    }

    if(input == 3){
        if(size_queue > 0) {
            front = free_memory(front, 1, &size_queue);
            if(front == NULL) rear = NULL;
        } else {
            printf("Queue is empty!\n");
        }
    }

    if(input == 4){
        int n;
        printf("How many elements you want to dequeue\n ==> ");
        scanf("%d", &n);

        if(n <= size_queue) {
            front = free_memory(front, n, &size_queue);
            if(front == NULL) rear = NULL;
        } else {
            printf("Not enough elements in the queue!\n");
        }
    }

    if(input == 0){
        // Free memory
        free_memory(front, size_queue, &size_queue);

        goto end;
    }

    goto repeat;

end:
    return 0;
}

// add stack
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// creating a new stack eliment
struct node* new_stack_eliment(int data){
    struct node* new_stack_eliment = (struct node*)malloc(sizeof(struct node));
    new_stack_eliment -> data = data;
    new_stack_eliment -> next = NULL;

    return new_stack_eliment;
}

void print_stack(struct node* top, int *size_stack){

    printf("   _         _   Size of stack - %d\n", *size_stack);
    printf("    |       |   \n");
    printf("    |       |   \n");
    while(top != NULL){

        if(*size_stack != 0){
            if(top -> data > 9){
                printf("    |-------|   \n");
                printf("    |  %d   |   \n", top -> data);
            }else if(top -> data > 99){
                printf("    |-------|   \n");
                printf("    |  %d  |   \n", top -> data);
            }else if(top -> data > 999){
                printf("    |-------|   \n");
                printf("    | %d  |   \n", top -> data);
            }else if(top -> data > 9999){
                printf("    |-------|   \n");
                printf("    | %d |   \n", top -> data);
            }else if((top -> data <= 9) && (top -> data >= 0)){
                printf("    |-------|   \n");
                printf("    |   %d   |   \n", top -> data);
            }else{

            }
        }
        top = top -> next;
    }

    printf("     -------   \n");
}

struct node* free_memory(struct node* top, int n){
    struct node* now;
    if(n == 0){
        while(top != NULL){
            now = top;
            top = now -> next;

            free(now);
        }
    }else{
        for(int i = 0; i < n; i++){
            now = top;
            top = now -> next;

            free(now);
        }

        return top;
    }
}

//stack implimentation
int main(){
    int size_stack = 0;
    struct node* top;
    struct node* now = NULL;
    int input = -1;

repit:

    printf("Clearing the terminal...\n");
    system("cls");
    
    print_stack(top, &size_stack);

    printf("\n\n-----------------------------------------------------------\n\n");

    printf("0. Exit\n");
    printf("1. Push 10 eliment to stack '1 to 10'\n");
    printf("2. Push 'n' eliment to stack\n");
    printf("3. Pop '1' Eliment from top\n");
    printf("4. Pop 'n' Eliment from top\n\n==> ");

    scanf("%d", &input);

    if(input == 1){
        for(int i = 0; i < 10; i++){
            top = new_stack_eliment(i + 1);
            top -> next = now;

            now = top;
            size_stack++;
        }
    }

    if(input == 2){
        int eliment_n, eliment = 0;
        printf("How many eliment you want to Push\n ==> ");
        scanf("%d", &eliment);

        for(int i = 0; i < eliment; i++){
            printf("  ==> ");
            scanf("%d", &eliment_n);

            top = new_stack_eliment(eliment_n);
            top -> next = now;
            
            now = top;
            size_stack++;
        }
    }

    if(input == 3){
        top = free_memory(top, 1);
        now = top;

        size_stack--;
    }

    if(input == 4){
        int eliment;
        printf("How many eliment you want to Pop\n ==> ");
        scanf("%d", &eliment);

        top = free_memory(top, eliment);
        now = top;

        size_stack-=eliment;
    }

    if(input == 0){
        // free memory and end the code
        free_memory(top, 0);

        goto end;
    }

    goto repit;

end:
    return 0;
}



