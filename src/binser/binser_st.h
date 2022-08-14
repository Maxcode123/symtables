#pragma once

#include "array.h"

#define ARRAYINITSIZE 100 // initial size of symbol table

typedef struct {
    DynamicArray* keys;
    DynamicArray* values;
    int i; // current index
} BinarySearchST;

typedef struct {
    int value;
    bool isnull;
} Int;

BinarySearchST* init_ST();
BinarySearchST* sinit_ST(int size);
int compare(key k1, key k2);
bool isempty(BinarySearchST* st);
int rank(key k, BinarySearchST* st);
void shift_kv(BinarySearchST* st, int i, int j);
void resize_arrays(BinarySearchST* st);
void get(key k, BinarySearchST* st, Int* val);
void put(key k, int val, BinarySearchST* st);