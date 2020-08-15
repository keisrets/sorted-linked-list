#include "list.h"

Node * add_node(Node **head, int data) {
    // create new node
    Node *new = malloc(sizeof(Node));
    new->val = data;
    new->next = NULL;

    if(*head == NULL) {
        *head = new;
    } else {
        Node *current = *head;
        Node *prev = NULL;
        bool inserted = false;
    
        // check if new node int value is smaller than head int value
        if(new->val <= current->val) {
            new->next = *head;
            *head = new;
            inserted = true;
        } else {
            // iterate through list
            while (current->next != NULL) {
                // insert before current node if the new node int 
                // value is smaller than current node int value
                if(new->val <= current->val) {
                    prev->next = new;
                    new->next = current;
                    
                    inserted = true;
                    break;
                }
                
                prev = current;
                current = current->next;
            }
            
        }
        
        // insert new node before or after the last element of the list
        if(!inserted) {
            if(new->val <= current->val) {
                prev->next = new;
                new->next = current;
            } else {
                current->next = new;
            }
        }
    }

    return *head;
}

void print_list(Node **head) {
    Node *current = *head;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }

    printf("\n");
}

void destroy_list(Node **head) {
    Node *current = *head;
    Node *next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}