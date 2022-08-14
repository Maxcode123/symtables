#include "array.h"

item* initstatic_Array(int size)
{
    item* ptr = (item*)malloc(size * sizeof(item));
    return ptr;
}

DynamicArray* init_Array()
{
    item* array = initstatic_Array(ARRAYINITSIZE);    
    DynamicArray* ptr = (DynamicArray*)malloc(sizeof(DynamicArray));
    ptr->i = -1;
    ptr->n = ARRAYINITSIZE;
    ptr->array = array;
    return ptr;
}
