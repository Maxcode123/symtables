#pragma once

#include "../base.h"

typedef struct DynamicArray {
    int n; // size
    void* array;
} DynamicArray;

void* initstatic_Array(int size, char* type);
