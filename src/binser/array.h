#pragma once

#include "../base.h"

#define KEYSIZE 10 // 10 characters max for each key
#define ARRAYINITSIZE 100 // initial size of dynamic array

typedef char key[KEYSIZE];

typedef struct DynamicArray {
    int n; // size
    void* array;
} DynamicArray;

void* initstatic_Array(int size, char* type);
DynamicArray* init_Array();
