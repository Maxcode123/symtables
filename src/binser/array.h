#pragma once

#include "../base.h"

#define ARRAYINITSIZE 100 // initial size of dynamic array
#define RESIZECONST 2

typedef char* key; // key type

typedef union {
    key k;
    int v;
} item;

typedef struct {
    int n; // size
    item* array; // underlying static array
} DynamicArray;


item* initstatic_Array(int size);
void deletestatic_Array(item* ptr);
DynamicArray* init_Array(int size);
void delete_Array(DynamicArray* s);
int get_value(DynamicArray* s, int i);
key get_key(DynamicArray* s, int i);
void put_value(DynamicArray* s, int val, int i);
void put_key(DynamicArray* s, key k, int i);
void shift_value(DynamicArray* s, int i, int j);
void shift_key(DynamicArray* s, int i, int j);
void resize_array(DynamicArray** s);

