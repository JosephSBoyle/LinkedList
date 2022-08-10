#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"
#include <assert.h>

Node* list(){
    // create a 'sentinel node'.
    Node* sentinel = (Node*)malloc(NODE_SIZE);
    sentinel->next = NULL;
    sentinel->item = '\0';
    return sentinel;
}

Node* peak(Node* sentinel, size_t idx){
    Node* node = sentinel;

    // compare to idx + 1, since we want our peak to be zero-indexed
    // and we have a sentinel node
    for (size_t i=0; i != idx+1; i++){
        if (node->next == NULL){
            // return the sentinel node as there are fewer than idx elements in the list
            return sentinel;
        }
        node = node->next;
    }
    return node;
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
    Node* new_node = (Node*)malloc(NODE_SIZE);
    new_node->item = item;

    // traverse each node
    while (true){
        if(sentinel->next == NULL){
            // replace the last node with our new node.
            sentinel->next = new_node;
            break;
        } else {
            // point to the next node
            sentinel = sentinel->next;
        }
    }
}

bool del(Node* sentinel, size_t idx){
    // TODO find a way to leverage peak to simplify this
    for (size_t i=0; i != idx; i++){
        if (!sentinel){
            return false;
        }
        sentinel = sentinel->next;
    }
    if (sentinel->next){
        Node* index_node_ptr = sentinel->next;
        if (index_node_ptr->next){
            sentinel->next = index_node_ptr->next;
        } else {
            free(index_node_ptr);
            sentinel->next = NULL;
        }
        return true;
    }
}

bool replace(Node* sentinel, size_t idx, char item){
    Node* node = peak(sentinel, idx);
    // check if the sentinel and the peaked node are the same
    if (sentinel == node){
        return false;
    } else {
        node->item = item;
        return true;
    }

}
size_t len(Node* sentinel){
    Node* current_node = sentinel;
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

void print(Node* sentinel){
    printf("[");
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("'%c',", sentinel->item);
    }
    printf("]\n");
}

void pstring(Node* sentinel){
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("%c", sentinel->item);
    }
    printf("\n");
}

/* Tests */
void main(){
    Node* sentinel = list();

    add(sentinel, 'h');
    add(sentinel, 'e');
    add(sentinel, 'l');
    add(sentinel, 'l');
    add(sentinel, 'o');
    print(sentinel);

    replace(sentinel, 4, '0');
    pstring(sentinel);

    // check that deleting works for a valid index
    assert(del(sentinel, 4));
    // and fails when that index becomes invalid.
    assert(!del(sentinel, 4));

    // check peaking an invalid index returns the sentinel node
    assert(sentinel == peak(sentinel, 4));

    pstring(sentinel);
    free_list(sentinel);
}
