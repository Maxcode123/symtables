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
    DynamicArray* keys = init_Array(5);
    cr_assert(keys->n == 5, "Dynamic array size not initialized as expected.");
}

Test(arraytest, getvalue)
{
    DynamicArray* a = init_Array(5);
    int val = 10;
    item i = {.v=val};
    a->array[1] = i;
    cr_assert(get_value(a, 1) == val, "get_value does not return correct value.");
}

Test(arraytest, getkey)
{
    DynamicArray* a = init_Array(5);
    key k = "ABC";
    item i = {.k=k};
    a->array[1] = i;
    cr_assert(strcmp(get_key(a, 1), k) == 0, "get_key does not return correct key.");
}

Test(arraytest, putvalue)
{
    DynamicArray* a = init_Array(5);
    int val = 10;
    put_value(a, val, 2);
    cr_assert(a->array[2].v == val, "put_value does not insert value.");
}

Test(arraytest, putkey)
{
    DynamicArray* a = init_Array(20);
    key k ="ABC";
    put_key(a, k, 15);
    cr_assert(strcmp(a->array[15].k, k) == 0, "put_key does not insert key.");
}

Test(arraytest, shiftvalue)
{
    DynamicArray* a = init_Array(10);
    item it1 = {.v=10};
    item it2 ={.v=25};
    a->array[3] = it1;
    a->array[5] = it2;
    shift_value(a, 3, 5);
    cr_assert(a->array[3].v == it2.v, "shift_value does not shift values.");
}

Test(arraytest, shiftkey)
{
    DynamicArray* a = init_Array(30);
    item it1 = {.k="ABC"};
    item it2 = {.k="DEF"};
    a->array[13] = it1;
    a->array[27] = it2;
    shift_key(a, 13, 27);
    cr_assert(strcmp(a->array[13].k, it2.k) == 0, "shift_key does not shift values.");
}

Test(arraytest, resizearray)
{
    DynamicArray* a = init_Array(3);
    for (int i = 0; i < 3; i++) 
    {
        item it = {.v=i}; 
        a->array[i] = it;
    }
    resize_array(&a);
    cr_assert(a->n != 3, "resize_array did not change array size.");
    cr_assert(a->n == 6, "resize_array did not resize array correctly.");
    for (int i = 0; i < 3; i++) cr_assert(a->array[i].v == i, "resize_array did not copy items correctly.");
}