// ------------------------------------------------------------------------------------------------------ Link list 1

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
    while(now != NULL){
        now = head;
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

// ------------------------------------------------------------------------------------------------------ Link list 2
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Insert a node at the beginning of the list
struct node* add_top(struct node* head, int data) {
    struct node* temp = create_node(data);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    return temp;
}

// Function to print the list from head to tail
void print_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

// Function to free memory used by the list
void free_mem(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create the head node
    struct node* head = create_node(100);
    struct node* now = head;

    // Create the rest of the nodes
    for (int i = 2; i <= 10; i++) {
        now->next = create_node(i * 100);
        now->next->prev = now;  // Set the previous pointer
        now = now->next;
    }

    printf("Main link        ");
    print_list(head); // Print the list

    // Add a node at the beginning
    head = add_top(head, 50);
    printf("Add to top       ");
    print_list(head); // Print the list

    // Add a node at the end
    struct node* temp = create_node(5000);
    now->next = temp;
    temp->prev = now;
    printf("Add to end       ");
    print_list(head); // Print the list

    // Free memory
    free_mem(head);

    return 0;
}


// ------------------------------------------------------------------------------------------------------ Stack

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node (doubly linked list node)
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to push an element onto the stack
struct node* push(struct node* top, int data) {
    struct node* new_node = create_node(data);
    new_node->next = top; // The current top becomes the next node
    if (top != NULL) {
        top->prev = new_node; // Set the previous pointer of the current top
    }
    return new_node; // New node is now the top
}

// Function to pop an element from the stack
struct node* pop(struct node* top, int* popped_value) {
    if (top == NULL) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        *popped_value = -1;
        return NULL;
    }
    *popped_value = top->data; // Retrieve the data to return
    struct node* temp = top;   // Store the current top to free
    top = top->next;           // Move the top pointer to the next node
    if (top != NULL) {
        top->prev = NULL; // Update the previous pointer of the new top
    }
    free(temp);           // Free the old top
    return top;
}

// Function to print the stack (top to bottom)
void print_stack(struct node* top) {
    struct node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the stack memory
void free_stack(struct node* top) {
    struct node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    struct node* top = NULL; // Initialize the stack as empty
    int popped_value;

    // Push elements onto the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    printf("After pushing 10, 20, 30:\n");
    print_stack(top);

    // Pop an element from the stack
    top = pop(top, &popped_value);
    if (popped_value != -1) {
        printf("Popped: %d\n", popped_value);
    }
    print_stack(top);

    // Push another element
    top = push(top, 40);
    printf("After pushing 40:\n");
    print_stack(top);

    // Pop all elements to demonstrate stack emptying
    while (top != NULL) {
        top = pop(top, &popped_value);
        if (popped_value != -1) {
            printf("Popped: %d\n", popped_value);
        }
    }
    print_stack(top);

    // Free memory
    free_stack(top);

    return 0;
}

// ------------------------------------------------------------------------------------------------------ Que

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node (doubly linked list node)
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Define the structure for a queue
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to initialize an empty queue
struct queue* create_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to enqueue an element at the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* new_node = create_node(data);
    if (q->rear == NULL) {
        // If the queue is empty, front and rear both point to the new node
        q->front = q->rear = new_node;
    } else {
        // Link the new node to the current rear and update the rear
        q->rear->next = new_node;
        new_node->prev = q->rear;
        q->rear = new_node;
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the front of the queue
int dequeue(struct queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    int data = q->front->data;
    struct node* temp = q->front;
    q->front = q->front->next;
    if (q->front != NULL) {
        q->front->prev = NULL; // Update the previous pointer of the new front
    } else {
        // If the queue is now empty, update rear to NULL
        q->rear = NULL;
    }
    free(temp); // Free the old front node
    return data;
}

// Function to print the queue from front to rear
void print_queue(struct queue* q) {
    struct node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free all memory used by the queue
void free_queue(struct queue* q) {
    struct node* temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    struct queue* q = create_queue(); // Initialize the queue

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("After enqueueing 10, 20, 30:\n");
    print_queue(q);

    // Dequeue an element
    int dequeued = dequeue(q);
    if (dequeued != -1) {
        printf("Dequeued: %d\n", dequeued);
    }
    print_queue(q);

    // Enqueue another element
    enqueue(q, 40);
    printf("After enqueueing 40:\n");
    print_queue(q);

    // Dequeue all elements to demonstrate queue emptying
    while (q->front != NULL) {
        dequeued = dequeue(q);
        if (dequeued != -1) {
            printf("Dequeued: %d\n", dequeued);
        }
    }
    print_queue(q);

    // Free memory
    free_queue(q);

    return 0;
}

// ------------------------------------------------------------------------------------------------------ Tree

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
};

// Function to create a new tree node
struct tree_node* create_node(int data) {
    struct tree_node* new_node = (struct tree_node*)malloc(sizeof(struct tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary tree
struct tree_node* insert_node(struct tree_node* root, int data) {
    if (root == NULL) {
        return create_node(data); // If the tree is empty, create a new root
    }
    if (data < root->data) {
        // Insert in the left subtree
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        // Insert in the right subtree
        root->right = insert_node(root->right, data);
    }
    return root; // Return the root node
}

// In-order traversal: Left -> Root -> Right
void inorder_traversal(struct tree_node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Pre-order traversal: Root -> Left -> Right
void preorder_traversal(struct tree_node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Post-order traversal: Left -> Right -> Root
void postorder_traversal(struct tree_node* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Free all nodes in the tree
void free_tree(struct tree_node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    struct tree_node* root = NULL; // Initialize the root of the tree

    // Insert nodes into the tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // Perform tree traversals
    printf("In-order Traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder_traversal(root);
    printf("\n");

    // Free all nodes
    free_tree(root);

    return 0;
}


