#include "array.h"

item* initstatic_Array(int size)
{
    item* ptr = (item*)malloc(size * sizeof(item));
    return ptr;
}

void deletestatic_Array(item* ptr)
{
    free(ptr);
}

DynamicArray* init_Array(int size)
{
    DynamicArray* ptr = (DynamicArray*)malloc(sizeof(DynamicArray));
    ptr->n = size;
    ptr->array = initstatic_Array(size);    
    return ptr;
}

void delete_Array(DynamicArray* s)
{
    deletestatic_Array(s->array);
    free(s);
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

void shift_value(DynamicArray* s, int i, int j)
{
    put_value(s, get_value(s, j), i);
}

void shift_key(DynamicArray* s, int i, int j)
{
    put_key(s, get_key(s, j), i);
}

void resize_array(DynamicArray** s)
{
    DynamicArray* s2 = init_Array((*s)->n * RESIZECONST);
    for (int i = 0; i < (*s)->n; i++) s2->array[i] = (*s)->array[i];
    DynamicArray* tmp = *s;
    *s = s2;
    delete_Array(tmp);
}