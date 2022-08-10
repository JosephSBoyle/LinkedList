#include <stdbool.h>

// define the node struct here so we can use it within it's own definition
typedef struct Node Node;

struct Node {
    /* A node in a linked list */
    char item;  // character at this node
    Node *next; // pointer to the next node
};

size_t NODE_SIZE = sizeof(Node);

/* Create a new list */
Node* list();

/* Destruct a list, freeing it's memory */
void free_list(Node* sentinel);

/* Add an element to the end of a list */
void add(Node* sentinel, char item);

/** Delete an element from a list.
 * @returns true if the operation succeeded, false if there is the list is shorter than
 * the supplied index argument.
 */
bool del(Node* sentinel, size_t idx);

/* Replace the value stored by the node at idx. */
bool replace(Node* sentinel, size_t idx, char item);

/* Get the length of a list */
size_t len(Node* sentinel);

/* Peak the idx'th node, or the last node if there are fewer than
   idx elements in the list. */
Node* peak(Node* sentinel, size_t idx);

/* Pretty-print a list */
void print(Node* sentinel);

/* Print a list as a contiguous string */
void pstring(Node* sentinel);