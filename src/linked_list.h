#pragma once // include this source at most once during compilation.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_list.h"

// define the node struct here so we can use it within it's own definition
typedef struct Node Node;

#define NODE_SIZE sizeof(Node)

/* Create a new list */
Node* ll_new(void);

/* Destruct a list, freeing it's memory */
void ll_free(Node* sentinel);

/** Add an element to the end of a list 
 * @returns false if an error occured.
 */
bool ll_add(Node* sentinel, char item);

/** Delete an element from a list.
 * @returns true if the operation succeeded, false if there is the list is shorter than
 * the supplied index argument.
 */
bool ll_del(Node* sentinel, size_t idx);

/* Replace the value stored by the node at idx. */
bool ll_replace(Node* sentinel, size_t idx, char item);

/* Get the length of a list */
size_t ll_len(const Node* sentinel);

/** Peak the idx'th node, or the last node if there are fewer than
 * @returns The node at idx. If no such node exists returns the terminating character: '\0' 
 */
Node* ll_peek(Node* sentinel, size_t idx);

/* Pretty-print a list */
void ll_print(const Node* sentinel);

/* Print a list as a contiguous string */
void ll_stringprint(const Node* sentinel);