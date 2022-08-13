#include <criterion/criterion.h>

#include "../src/binser/array.h"


Test(arraytest, initstaticarray)
{
    key* keys = initstatic_Array(5, "key");
    int* values = initstatic_Array(5, "value");
    strcpy(keys[0], "key1");
}