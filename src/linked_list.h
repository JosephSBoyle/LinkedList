#include <stdbool.h>

// define the node struct here so we can use it within it's definition
typedef struct Node Node;

struct Node {
    /* A node in a linked list */
    char item;  // character at this node
    Node *next; // pointer to the next node
};

unsigned int NODE_SIZE = sizeof(Node); 

/* Create a new list */
Node* list();

/* Add an element to the end of a list */
void add(Node* sentinel, const char item);

/** Delete an element from a list.
 * @returns true if the operation succeeded, false if there is the list is shorter than
 * the supplied index argument.  
 */
bool del(Node* sentinel, const unsigned int index);

/* Get the length of a list */
unsigned int len(Node* sentinel);

/* Read the value stored in the node at the supplied index arg. */
char peak(Node* sentinel, const unsigned int index);

/* pretty-print a list stdout */
void print_list(Node* sentinel);