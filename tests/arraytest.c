#include <criterion/criterion.h>

#include "../src/binser/array.h"


Test(arraytest, initstaticarray)
{
    key* keys = initstatic_Array(5, "key");
    int* values = initstatic_Array(5, "value");
}

Test(arraytest, initarray)
{
    DynamicArray* keys = init_Array("key");
    DynamicArray* values = init_Array("value");
    cr_expect(keys->n == ARRAYINITSIZE, "Dynamic array size not initialized as expected.");
}