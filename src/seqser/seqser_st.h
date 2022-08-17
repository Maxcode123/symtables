#pragma once

#include "llist.h"

typedef struct SequentialSearchST {
// Linked list implementation of symbol table.
    Node* head; // pointer to linked list head
    void (*get)(struct SequentialSearchST* self, key k, Int* val);
    void (*put)(struct SequentialSearchST* self, key k, int v);
    void (*print)(struct SequentialSearchST* self);
} SequentialSearchST;

SequentialSearchST* init_ST();
// Symbol table constructor; allocates memory for the ST and initializes head.

void _get(SequentialSearchST* self, key k, Int* val);
/* Insert the value of the given key where val_ptr points to. If there is no 
such key, points val_ptr to NULL. */

void _put(SequentialSearchST* self, key k, int v);
/* Associates val with key. If the key already exists, val overwrites the 
current value. */

void _printst(SequentialSearchST* self);
// Prints the symbol table.