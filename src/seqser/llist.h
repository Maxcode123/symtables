#pragma once

#include "../base.h"

typedef struct Node
// Node of linked list
{
    key k;
    int v;
    struct Node* next;
} Node;

Node* init_Node(key k, int v);
/* Node constructor; allocates memory for a Node and returns a pointer to a 
Node with the given values. */

Node* init_List();
/* Linked list constructor; returns the pointer to the head of the list with
the initialization value. */

void add_node(Node* n, Node** head_ptr);
// Adds a node to the linked list.

Node* get_node(key k, Node* head);
/* Returns a pointer to the node in the list matching the given key. If there 
is no such Node, return NULL. */

bool subs_node(key k, int v, Node* head);
/* Substitutes the value of the Node with the given key. If there is no such
Node, returns false, otherwise returns true. */

void printn(Node* n);
/* Prints Node with format:
    key: {key}, value: {val} */

void printl(Node* head);
// Prints all nodes in the list.

