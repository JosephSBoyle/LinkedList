#include "linked_list.h"

struct Node {
    /* A node in a linked list */
    char item;  // character at this node
    Node *next; // pointer to the next node
};

Node* ll_new(){
    // create a 'sentinel node'.
    Node* sentinel = (Node*)malloc(NODE_SIZE);
    sentinel->next = NULL;
    sentinel->item = '\0';
    return sentinel;
}

Node* ll_peek(Node* sentinel, size_t idx){
    Node* node = sentinel;

    // compare to idx + 1, since we want our peek to be zero-indexed
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

void ll_free(Node* sentinel){
    // traverse each node in order and free it's memory.
    size_t i = 0;
    do {
        i++;
        free(sentinel);
        sentinel = sentinel->next;
    } while (sentinel->next != NULL);
}

bool ll_add(Node* sentinel, char item){
    // attempt to allocate space for the new node
    void* ptr = malloc(NODE_SIZE);
    if (ptr == NULL){
        return false;
    }

    // ptr is not NULL so we can safely cast it to a Node*.
    Node* new_node = (Node*)ptr;
    new_node->item = item;  
    new_node->next = NULL;

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
    return true;
}

bool ll_del(Node* sentinel, size_t idx){
    // TODO find a way to leverage peek to simplify this
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
            sentinel->next = NULL;
            free(index_node_ptr);
        }
        return true;
    }
}

bool ll_replace(Node* sentinel, size_t idx, char item){
    Node* node = ll_peek(sentinel, idx);
    // check if the sentinel and the peaked node are the same
    if (sentinel == node){
        return false;
    } else {
        node->item = item;
        return true;
    }

}

size_t ll_len(const Node* sentinel){
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

void ll_print(const Node* sentinel){
    printf("[");
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("'%c',", sentinel->item);
    }
    printf("]\n");
}

void ll_stringprint(const Node* sentinel){
    while (sentinel->next != NULL){
        sentinel = sentinel->next;
        printf("%c", sentinel->item);
    }
    printf("\n");
}

