#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"


Node* list(){
    // Create a 'sentinel node'.
    Node* sentinel_ptr = (Node*)malloc(NODE_SIZE);
    sentinel_ptr->next = NULL;
    sentinel_ptr->item = '\0';
    return sentinel_ptr;
}

void add(Node* sentinel_ptr, const char item){
    // instantiate a new node
    Node* new_node_ptr = (Node*)malloc(NODE_SIZE);
    new_node_ptr->item = item;
    
    Node* current_node_ptr = sentinel_ptr;
    
    // traverse each node
    while (true){
        if(current_node_ptr->next == NULL){
            // replace the last node with our new node.
            current_node_ptr->next = new_node_ptr;
            break;
        } else {
            // point to the next node
            current_node_ptr = current_node_ptr->next;
        }
    }
}

bool del(Node* sentinel_ptr, unsigned int index){
    Node* prior_node_ptr = sentinel_ptr;
    for (int i=0; i != index; i++){
        if (!prior_node_ptr){
            return false;
        }
        prior_node_ptr = prior_node_ptr->next;
    }

    if (prior_node_ptr->next){
        Node* index_node_ptr = prior_node_ptr->next;
        if (index_node_ptr->next){
            prior_node_ptr->next = index_node_ptr->next;
        }
        return true;
    }
}

unsigned int len(Node* sentinel_ptr){
    Node* current_node_ptr = sentinel_ptr;
    unsigned int nodes = 0;
    while (true){
        // Check if we're at the final node.
        if(current_node_ptr->next == NULL){
            return nodes;
        }
        nodes++;
        current_node_ptr = current_node_ptr->next;
    }
}

char peak(Node* sentinel_ptr, const unsigned int index){
    Node* current_node_ptr = sentinel_ptr->next;
    for (int i=0; i != index - 1; i++){
        current_node_ptr = current_node_ptr->next;
    }
    return current_node_ptr->item;
}

void print_list(Node* sentinel_ptr){    
    printf("###\n[");
    int i=0;
    do {
        i++;
        sentinel_ptr = sentinel_ptr->next;
        printf("%c,", sentinel_ptr->item);
    } while (sentinel_ptr->next != NULL);
    printf("]\n###\n");
}

void main(){
    Node* sentinel = list();
    printf("The number of nodes in the list is %u\n", len(sentinel));
    printf("Deleting index 0 succeded?:%d\n", del(sentinel, 0));

    add(sentinel, '0');
    add(sentinel, '1');
    add(sentinel, '2');
    add(sentinel, '3');
    print_list(sentinel);

    printf("The number of nodes in the list is %u\n", len(sentinel));
    unsigned int index = 3;
    printf("The item at index %u is: %c\n", index, peak(sentinel, index));

    int delindex = 1;
    printf("Deleting index %d succeded?:%d\n", delindex, del(sentinel, delindex));
    printf("The item at index %u is: %c\n", delindex, peak(sentinel, delindex));
    print_list(sentinel);


    // TODO free the memory of each item in the list.
    free(sentinel);
}

