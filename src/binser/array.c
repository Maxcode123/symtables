#include "array.h"

void* initstatic_Array(int size, char* type)
{
    size_t s;
    if (strcmp(type, "key") == 0) s = sizeof(char);
    else if (strcmp(type, "value") == 0) s = sizeof(int);
    else {
        printf("Cannot initialize static array, unknown type: %s\n", type);
        exit(1);
    }
    void* ptr = malloc(s * size);
    return ptr;
}