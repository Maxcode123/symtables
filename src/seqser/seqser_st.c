#include "seqser_st.h"

SequentialSearchST* init_ST()
{
    SequentialSearchST* st = (SequentialSearchST*)malloc(sizeof(SequentialSearchST));
    st->head = init_List();
    return st;
}

void get(key k, SequentialSearchST* st, Int* val)
{
    Node* n = get_node(k, st->head);
    if (n == NULL)
    {
        val->isnull = true;
        return;
    } 
    val->value = n->v;
    val->isnull = false;
}

void put(key k, int v, SequentialSearchST* st)
{
    if (subs_node(k, v, st->head)) return;
    Node* n = init_Node(k, v);
    add_node(n, &st->head);
}

void printst(SequentialSearchST* st)
{
    printl(st->head);
}