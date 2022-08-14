#include "binser_st.h"

BinarySearchST* init_ST()
{
    BinarySearchST* st = (BinarySearchST*)malloc(sizeof(BinarySearchST));
    st->i = -1;
    st->keys = init_Array(ARRAYINITSIZE);
    st->values = init_Array(ARRAYINITSIZE);
    return st;
}

BinarySearchST* sinit_ST(int size)
{
    BinarySearchST* st = (BinarySearchST*)malloc(sizeof(BinarySearchST));
    st->i = -1;
    st->keys = init_Array(size);
    st->values = init_Array(size);
    return st;
}

int compare(key k1, key k2)
{
    return strcmp(k1, k2);
}

bool isempty(BinarySearchST* st)
{
    return st->i == -1;
}

int rank(key k, BinarySearchST* st)
{
    int lo = 0;
    int hi = st->i;
    int mid, cmp;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        cmp = compare(k, get_key(st->keys, mid));
        if (cmp < 0) hi = mid - 1;
        else if (cmp > 0) lo = mid + 1;
        else return mid;
    }
    return lo;
}

void shift_kv(BinarySearchST* st, int i, int j)
{
    shift_value(st->values, i, j);
    shift_key(st->keys, i, j);
}

void resize_arrays(BinarySearchST* st)
{
    resize_array(&st->keys);
    resize_array(&st->values);
}

void get(key k, BinarySearchST* st, Int* val)
{
    if (isempty(st))
    {
        val->isnull = true;
        return;
    }
    int i = rank(k, st);
    if (i < st->i + 1 & compare(k, get_key(st->keys, i)) == 0)
    {
        val->value = get_value(st->values, i);
        val->isnull = false;
        return;
    }
    val->isnull = true;
}

void put(key k, int val, BinarySearchST* st)
{
    int i = rank(k, st);
    if (i < st->i + 1 & compare(k, get_key(st->keys, i)) == 0)
    {
        put_value(st->values, val, i);
        return;
    }
    if (st->i == st->values->n) // underlying static arrays are full
    {
        resize_arrays(st);
    }
    for (int j = st->i; j > i; j--)
    {
        shift_kv(st, j, j-1);
    }
    put_key(st->keys, k, i);
    put_value(st->values, val, i);
    st->i++;
}