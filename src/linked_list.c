#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"


Node* list(){
    // create a 'sentinel node'.
    Node* sentinel = (Node*)malloc(NODE_SIZE);
    sentinel->next = NULL;
    sentinel->item = '\0';
    return sentinel;
}

void free_list(Node* sentinel){
    // traverse each node in order and free it's memory.
    size_t i = 0;
    do {
        i++;
        free(sentinel);
        sentinel = sentinel->next;
    } while (sentinel->next != NULL);
}

void add(Node* sentinel, char item){
    // instantiate a new node
    Node* new_node_ptr = (Node*)malloc(NODE_SIZE);
    new_node_ptr->item = item;
    
    // traverse each node
    Node* current_node = sentinel;
    while (true){
        if(current_node->next == NULL){
            // replace the last node with our new node.
            current_node->next = new_node_ptr;
            break;
        } else {
            // point to the next node
            current_node = current_node->next;
        }
    }
}

bool del(Node* sentinel, size_t idx){
    Node* prior_node_ptr = sentinel;
    for (size_t i=0; i != idx; i++){
        if (!prior_node_ptr){
            return false;
        }
        prior_node_ptr = prior_node_ptr->next;
    }

    if (prior_node_ptr->next){
        Node* index_node_ptr = prior_node_ptr->next;
        if (index_node_ptr->next){
            prior_node_ptr->next = index_node_ptr->next;
        } else {
            free(index_node_ptr);
            prior_node_ptr->next = NULL;
        }
        return true;
    }
}

size_t len(const Node* sentinel){
    const Node* current_node = sentinel;
    size_t nodes = 0;
    while (true){
        // Check if we're at the final node.
        if(current_node->next == NULL){
            return nodes;
        }
        nodes++;
        current_node = current_node->next;
    }
}

char peak(const Node* sentinel, size_t idx){
    Node* current_node = sentinel->next;

    for (int i=0; i != idx; i++){
        current_node = current_node->next;
    }
    return current_node->item;
}

void print(const Node* sentinel){
    printf("###\n[");
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("%c,", sentinel->item);
    }
    printf("]\n###\n");
}

void pstring(const Node* sentinel){
    printf("###\n");
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("%c", sentinel->item);
    }
    printf("\n###\n");
}

void main(){
    Node* sentinel = list();
    printf("The number of nodes in the list is %lu\n", len(sentinel));
    printf("Deleting idx 0 succeded?:%d\n", del(sentinel, 0));

    add(sentinel, 'a');
    add(sentinel, 'b');
    add(sentinel, 'c');
    add(sentinel, 'd');
    print(sentinel);
    pstring(sentinel);

    printf("The number of nodes in the list is %lu\n", len(sentinel));
    size_t idx = 3;
    printf("The item at idx %lu is: %c\n", idx, peak(sentinel, idx));

    size_t delindex = 0;
    printf("Deleting idx %lu succeded?:%d\n", delindex, del(sentinel, delindex));
    print(sentinel);

    printf("Deleting idx %lu succeded?:%d\n", delindex, del(sentinel, delindex));
    print(sentinel);

    printf("Deleting idx %lu succeded?:%d\n", delindex, del(sentinel, delindex));
    print(sentinel);

    printf("Deleting idx %lu succeded?:%d\n", delindex, del(sentinel, delindex));
    print(sentinel);

    free_list(sentinel);
}

