/*
    Name: MD SUZON MIA  
    ID: 241-15-717
    Task: Write a C program to -
            find the frequency of each character in a string
            (using a linked list)

            21-01-2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
    char mem_name;
    int frequency;
    struct member* next;
};

// Create New member
struct member* create_mem(char mem){
    struct member* new_member;

    new_member = (struct member*)malloc(sizeof(struct member));
    new_member -> mem_name = mem;
    new_member -> frequency = 1;
    new_member -> next = NULL;

    return new_member;
}

// Find if memer exist
int mem_exist(struct member* head, char mem){
    while(head != NULL){
        if(head -> mem_name == mem){
            head -> frequency += 1;

            return 1; 
        }
        head = head -> next;
    }
}

// Print Member and Frequency
void print_list(struct member* head){
    while(head != NULL){
        printf("|\t%c\t\t|\t%d\t\t|\n", head -> mem_name, head -> frequency);
        printf("|_______________________|_______________________|\n");
        head = head -> next;
    }
}

int main(){
    char string[1000];
    system("cls");
    printf("Please enter the String (Max - 1000)\n");
    printf("--> ");

    scanf("%s", string);
    struct member* head;
    struct member* now = head;

    for(int i = 0; i < strlen(string); i++){
        if(i != 0){
            if(mem_exist(head, string[i]) != 1){
                now -> next = create_mem(string[i]);    // create new member
                now = now -> next;
            }
        }else{
            head = create_mem(string[i]);               // create head member
            now = head;
        }
    }

    printf(" _______________________________________________\n|\tMember\t\t|\tFrequency\t|\n|_______________________|_______________________|\n");
    print_list(head);
    printf("\n\t\t      /\\_/\\\n\t\t     ( o.o )\n\t\t      > ^ <\n\n");
}

