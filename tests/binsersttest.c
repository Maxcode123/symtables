#include <criterion/criterion.h>

#include "../src/binser/binser_st.h"

Test(binsersttest, initst)
{
    BinarySearchST* st = init_ST();
    cr_assert(st->i == -1, "init_ST: current index not initialized properly.");
}

Test(binsersttest, _compare)
{
    key k1 = "ABC";
    key k2 = "DEF";
    cr_assert(compare(k1, k2) < 0, "compare does not return expected result (<0).");
    cr_assert(compare(k2, k1) > 0, "compare does not return expected result (>0).");
    cr_assert(compare(k1, k1) == 0, "compare does not return expected result (==0)."); 
}

Test(binsersttest, _isempty)
{
    BinarySearchST* st = init_ST();
    cr_assert(isempty(st), "isempty does not return expected result.");
}

Test(binsersttest, _rank)
{
    BinarySearchST* st = sinit_ST(3);
    put_key(st->keys, "A", 0);
    put_key(st->keys, "B", 1);
    put_key(st->keys, "C", 2);
    st->i = 2;
    cr_assert(rank("C", st) == 2, "rank does not return expected result (2).");
    cr_assert(rank("D", st) == 3, "rank does not return expected result (3).");
}

Test(binsersttest, shiftkv)
{
    BinarySearchST* st = sinit_ST(3);
    put_key(st->keys, "A", 0);
    put_key(st->keys, "C", 2);
    put_value(st->values, 10, 0);
    put_value(st->values, 30, 2);
    shift_kv(st, 0, 2);
    cr_assert(strcmp(st->keys->array[0].k, "C") == 0, "shift_kv does not shift key.");
    cr_assert(st->values->array[0].v == 30, "shift_kv does not shift value.");
}

Test(binsersttest, resizearrays)
{
    BinarySearchST* st = sinit_ST(3);
    resize_arrays(st);
    cr_assert(st->keys->n == 6, "Key array not resized as expected.");
    cr_assert(st->values->n == 6, "Value array not resized as expected.");
}

Test(binsersttest, _get)
{
    BinarySearchST* st = sinit_ST(2);
    put_key(st->keys, "A", 0);
    put_key(st->keys, "C", 1);
    put_value(st->values, 10, 0);
    put_value(st->values, 30, 1);
    st->i = 1;
    Int val;
    get("A", st, &val);
    cr_assert(val.value == 10 & !val.isnull, "get does not return expected value.");
    get("B", st, &val);
    cr_assert(val.isnull, "get does not return NULL as expected.");
}

Test(binsersttest, _put)
{
    BinarySearchST* st = sinit_ST(2);
    put("ABC", 15, st);
    cr_assert(st->i == 0, "put does not increase current index.");
    cr_assert(strcmp(st->keys->array[0].k, "ABC") == 0, "put does not insert key.");
    cr_assert(st->values->array[0].v == 15, "put does not insert value.");
    put("ABC", 25, st);
    cr_assert(st->i == 0, "put increases index incorrectly");
    cr_assert(strcmp(st->keys->array[0].k, "ABC") == 0, "put removes existent key.");
    cr_assert(st->values->array[0].v == 25, "put does not substitute value.");
}