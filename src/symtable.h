#pragma once

#include "base.h"
#include "linked_list.h"

typedef struct ST {
// Linked list implementation of Symbol table.
    Node* head; // pointer to linked list head
} ST;

ST* init_ST();
// Symbol table constructor; allocates memory for the ST and initializes head.

int* get(char* key, ST* st);
/* Fetches a pointer to the value with the given key. If there is no such key
in the symbol table return NULL. 
The result of this function should never be cast directly into an int, because 
NULL evaluates to 0 when casted to an int. This causes a problem with 
distinguishing between if a key is associated with a value of 0 or if it is 
does not exist. */

void put(char* key, int val, ST* st);
/* Associates val with key. If the key already exists, val overwrites the 
current value. */

void printst(ST* st);
// Prints the symbol table.