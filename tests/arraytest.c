#include <criterion/criterion.h>

#include "../src/binser/array.h"


Test(arraytest, initstaticarray)
{
    item* keys = initstatic_Array(5);
    item* values = initstatic_Array(5);
    key k = "ABC";
    item i = {.k=k};
    keys[1] = i;
    cr_assert(strcmp(keys[1].k, k) == 0, "item not initialized");
}

Test(arraytest, initarray)
{
    DynamicArray* keys = init_Array();
    DynamicArray* values = init_Array();
    cr_assert(keys->n == ARRAYINITSIZE, "Dynamic array size not initialized as expected.");
}

Test(arraytest, full)
{
    DynamicArray* a = init_Array();
    cr_assert(!full(a), "full function is wrong.");
}

Test(arraytest, getvalue)
{
    DynamicArray* a = init_Array();
    int val = 10;
    item i = {.v=val};
    a->array[1] = i;
    cr_assert(get_value(a, 1) == val, "get_value does not return correct value.");
}

Test(arraytest, getkey)
{
    DynamicArray* a = init_Array();
    key k = "ABC";
    item i = {.k=k};
    a->array[1] = i;
    cr_assert(strcmp(get_key(a, 1), k) == 0, "get_key does not return correct key.");
}

Test(arraytest, putvalue)
{
    DynamicArray* a = init_Array();
    int val = 10;
    put_value(a, val, 2);
    cr_assert(a->array[2].v == val, "put_value does not insert value.");
}

Test(arraytest, putkey)
{
    DynamicArray* a = init_Array();
    key k ="ABC";
    put_key(a, k, 15);
    cr_assert(strcmp(a->array[15].k, k) == 0, "put_key does not insert key.");
}