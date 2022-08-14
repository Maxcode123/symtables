#pragma once

#include "llist.h"

typedef struct {
// Linked list implementation of symbol table.
    Node* head; // pointer to linked list head
} SequentialSearchST;

SequentialSearchST* init_ST();
// Symbol table constructor; allocates memory for the ST and initializes head.

void get(key k, SequentialSearchST* st, Int* val);
/* Insert the value of the given key where val_ptr points to. If there is no 
such key, points val_ptr to NULL. */

void put(key k, int v, SequentialSearchST* st);
/* Associates val with key. If the key already exists, val overwrites the 
current value. */

void printst(SequentialSearchST* st);
// Prints the symbol table.