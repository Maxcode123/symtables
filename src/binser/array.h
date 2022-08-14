#pragma once

#include "../base.h"

#define KEYSIZE 10 // 10 characters max for each key
#define ARRAYINITSIZE 100 // initial size of dynamic array

typedef char key[KEYSIZE]; // key type

typedef union {
    key k;
    int v;
} item;

typedef struct {
    int i; // current index
    int n; // size
    item* array; // underlying static array
} DynamicArray;


item* initstatic_Array(int size);
DynamicArray* init_Array();
bool full(DynamicArray* s);
int get_value(DynamicArray* s, int i);
key* get_key(DynamicArray* s, int i);
void put_value(DynamicArray* s, int val, int i);
void put_key(DynamicArray* s, key k, int i);
void exchange_value(DynamicArray* s, int i, int j);
void exchange_key(DynamicArray* s, int i, int j);
void resize_array(DynamicArray* s);

