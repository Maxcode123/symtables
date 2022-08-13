#pragma once

#include "../base.h"

typedef struct Node
// Node of linked list
{
    char* key;
    int val;
    struct Node* next;
} Node;

Node* init_Node(char* key, int val);
/* Node constructor; allocates memory for a Node and returns a pointer to a 
Node with the given values. */

Node* init_List();
/* Linked list constructor; returns the pointer to the head of the list with
the initialization value. */

void add_node(Node* n, Node** head_ptr);
// Adds a node to the linked list.

Node* get_node(char* key, Node* head);
/* Returns a pointer to the node in the list matching the given key. If there 
is no such Node, return NULL. */

int subs_node(char* key, int val, Node* head);
/* Substitutes the val of the Node with the given key. If there is no such
Node, return FALSE, otherwise returns TRUE. */

void printn(Node* n);
/* Prints Node with format:
    key: {key}, value: {val} */

void printl(Node* head);
// Prints all nodes in the list.

