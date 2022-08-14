#include "binser_st.h"

BinarySearchST* init_ST()
{}

int compare(key k1, key k2)
{
    return strcmp(k1, k2);
}

bool isempty(BinarySearchST* st)
{
    return st->i == 0;
}

int rank(key k, BinarySearchST* st)
{
    int lo = 0;
    int hi = st->i - 1;
    int mid, cmp;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        cmp = compare(k, get_key(&st->keys, mid));
        if (cmp < 0) hi = mid - 1;
        else if (cmp > 0) lo = mid + 1;
        else return mid;
    }
    return lo;
}

int* get(key k, BinarySearchST* st)
{
    if (isempty(st)) return NULL;
    int i = rank(k, st);
    if (i < st->i & compare(k, get_key(&st->keys, i)) == 0) return get_value(&st->values, i);
    else return NULL;
}

void put(key k, int val, BinarySearchST* st)
{
    int i = rank(k, st);
    if (i < st->i & compare(k, get_key(&st->keys, i)) == 0)
    {
        put_value(&st->values, val, i);
        return;
    }
    if (st->i == st->values.i) // underlying static array is full
    {
        resize_array(&st->keys);
        resize_array(&st->values);
    }
    for (int j = st->i; j > i; j--)
    {
        put_key(&st->keys, get_key(&st->keys, j-1), j);
        put_value(&st->values, get_value(&st->values, j-1), j);
    }
    put_key(&st->keys, k, i);
    put_value(&st->values, val, i);
    st->i++;
}