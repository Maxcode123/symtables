#pragma once

#include "array.h"

typedef struct {
    DynamicArray keys;
    DynamicArray values;
    int i; // current index
} BinarySearchST;

BinarySearchST* init_ST();
int compare(key k1, key k2);
bool isempty(BinarySearchST* st);
int rank(key k, BinarySearchST* st);
int* get(key k, BinarySearchST* st);
void put(key k, int val, BinarySearchST* st);