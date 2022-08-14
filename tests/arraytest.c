#include <criterion/criterion.h>

#include "../src/binser/array.h"


Test(arraytest, initstaticarray)
{
    item* keys = initstatic_Array(5);
    item* values = initstatic_Array(5);
    item i = {.k="key1"};
    keys[1] = i;
    cr_expect(strcmp(keys[1].k, "key1") == 0, "item not initialized");
}

Test(arraytest, initarray)
{
    DynamicArray* keys = init_Array();
    DynamicArray* values = init_Array();
    cr_expect(keys->n == ARRAYINITSIZE, "Dynamic array size not initialized as expected.");
}

Test(arraytest, full)
{
    DynamicArray* a = init_Array();
    cr_expect(!full(a), "full function is wrong.");
}

Test(arraytest, getvalue)
{
    DynamicArray* a = init_Array();
    int val = 10;
    item i = {.v=val};
    a->array[1] = i;
    cr_expect(get_value(a, 1) == val, "get_value does not return correct value.");
}