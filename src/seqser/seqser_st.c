#include "seqser_st.h"

SequentialSearchST* init_ST()
{
    SequentialSearchST* st = (SequentialSearchST*)malloc(sizeof(SequentialSearchST));
    st->head = init_List();
    return st;
}

void get(char* key, SequentialSearchST* st, int* val_ptr)
{
    Node* n = get_node(key, st->head);
    if (n == NULL)
    {
        val_ptr = NULL;
        return;
    } 
    *val_ptr = n->val;
}

void put(char* key, int val, SequentialSearchST* st)
{
    if (subs_node(key, val, st->head)) return;
    Node* n = init_Node(key, val);
    add_node(n, &st->head);
}

void printst(SequentialSearchST* st)
{
    printl(st->head);
}