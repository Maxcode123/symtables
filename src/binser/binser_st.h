#pragma once

#include "array.h"

#define ARRAYINITSIZE 100 // initial size of symbol table

typedef struct {
// Sorted array implementation of symbol table.
    DynamicArray* keys; // sorted array of keys
    DynamicArray* values; // sorted array of values
    int i; // current index
} BinarySearchST;

BinarySearchST* init_ST();
/* Allocates memory for the symbol table and the keys, values arrays. 
Initializes the table with the default size. */

BinarySearchST* sinit_ST(int size);
// Same as init_ST, but receives the size of the symbol table to initialize.

int compare(key k1, key k2);
// Compares k1 with k2. If k1 > k2 returns > 0, if k1 < k2 returns < 0, else 0.

bool isempty(BinarySearchST* st);
// Returns true if the symbol table has no entries.
 
int rank(key k, BinarySearchST* st);
// Returns the number of keys in st that are smaller than k.

void shift_kv(BinarySearchST* st, int i, int j);
// Puts the keys and values from index j to index i.  

void resize_arrays(BinarySearchST* st);
/* Resizes the keys and values array. 
see resize_array(DynamicArray** s) in array.h */

void get(key k, BinarySearchST* st, Int* val);
/* Puts the value associated with k to val. If no such key exists in the symbol
 table, sets isnull=true for val.  */

void put(key k, int v, BinarySearchST* st);
// Associates val with k. If k exists, it overwrites current value.