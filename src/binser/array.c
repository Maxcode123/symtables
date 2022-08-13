#include "array.h"

void* initstatic_Array(int size, char* type)
{
    size_t s;
    if (strcmp(type, "key") == 0) s = sizeof(key);
    else if (strcmp(type, "value") == 0) s = sizeof(int);
    else {
        printf("Cannot initialize static array, unknown type: %s\n", type);
        exit(1);
    }
    void* ptr = malloc(s * size);
    return ptr;
}

DynamicArray* init_Array(char* type)
{
    void* array;
    if (strcmp(type, "key") == 0) 
    {
        key* array = initstatic_Array(ARRAYINITSIZE, type);
    }
    else if (strcmp(type, "value") == 0) 
    {
        int* array = initstatic_Array(ARRAYINITSIZE, type);
    }
    else 
    {
        printf("Cannot initialize dynamic array, unknown type: %s", type);
        exit(1);
    }
    DynamicArray* ptr = (DynamicArray*)malloc(sizeof(DynamicArray));
    ptr->i = -1;
    ptr->n = ARRAYINITSIZE;
    ptr->array = array;
    return ptr;
}