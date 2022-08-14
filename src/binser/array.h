#pragma once

#include "../base.h"

#define RESIZECONST 2 // array resizing constant

typedef char* key; // key type

typedef union {
// item hold in dynamic arrays
    key k;
    int v;
} item;

typedef struct {
// Size adjustable array 
    int n; // size
    item* array; // pointer to underlying static array
} DynamicArray;


item* initstatic_Array(int size);
/* Allocates memory for a static array of items of the given size. Returns
pointer to array. */

void deletestatic_Array(item* ptr);
// Deallacotes the memory held by the array that ptr points to.

DynamicArray* init_Array(int size);
/* Initializes a static array and allocates memory for a dynamic array. Returns
pointer to dynamic array. */

void delete_Array(DynamicArray* s);
/* Deallocates the memory held by the dynamic array and the underlying static 
array. */

int get_value(DynamicArray* s, int i);
// Returns the item value of the dynamic array at index i.

key get_key(DynamicArray* s, int i);
// Returns the item key of the dynamic array at index i.

void put_value(DynamicArray* s, int val, int i);
// Inserts an item with v=val at index i.

void put_key(DynamicArray* s, key k, int i);
// Inserts an item with k=k at index i.

void shift_value(DynamicArray* s, int i, int j);
// Puts the item value at index j at the value of item at index i.

void shift_key(DynamicArray* s, int i, int j);
// Puts the item key at index j at the key of the item at index i.

void resize_array(DynamicArray** s);
/* Initializes a new dynamic array with size equal to the size of the given 
times RESIZINGCONST. 
Assigns all values of the given array to the new array.
Points the pointer of the given array to the new array.
Deletes the (obsolete) given array. */


