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
void add(Node* sentinel, const char item);

/** Delete an element from a list.
 * @returns true if the operation succeeded, false if there is the list is shorter than
 * the supplied index argument.  
 */
bool del(Node* sentinel, size_t idx);

/* Get the length of a list */
size_t len(const Node* sentinel);

/* Read the value stored in the node at the supplied index arg. */
char peak(const Node* sentinel, size_t idx);

/* Pretty-print a list to stdout */
void print(const Node* sentinel);

/* Print a list as a contiguous string */
void pstring(const Node* sentinel);