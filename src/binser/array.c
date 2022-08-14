#include "array.h"

item* initstatic_Array(int size)
{
    item* ptr = (item*)malloc(size * sizeof(item));
    return ptr;
}

DynamicArray* init_Array()
{
    DynamicArray* ptr = (DynamicArray*)malloc(sizeof(DynamicArray));
    ptr->i = -1;
    ptr->n = ARRAYINITSIZE;
    ptr->array = initstatic_Array(ARRAYINITSIZE);    
    return ptr;
}

bool full(DynamicArray* s)
{
    return s->i == s->n;
}

int get_value(DynamicArray* s, int i)
{
    return s->array[i].v;
}

key get_key(DynamicArray* s, int i)
{
    return s->array[i].k;
}

void put_value(DynamicArray* s, int val, int i)
{
    item it = {.v=val};
    s->array[i] = it;
}

void put_key(DynamicArray* s, key k, int i)
{
    item it = {.k=k};
    s->array[i] = it;
}
