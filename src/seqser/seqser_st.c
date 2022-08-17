#include "seqser_st.h"

SequentialSearchST* init_ST()
{
    SequentialSearchST* self = (SequentialSearchST*)malloc(sizeof(SequentialSearchST));
    self->head = init_List();
    self->get = &_get;
    self->put = &_put;
    self->print = &_printst;
    return self;
}

void _get(SequentialSearchST* self, key k, Int* val)
{
    Node* n = get_node(k, self->head);
    if (n == NULL)
    {
        val->isnull = true;
        return;
    } 
    val->value = n->v;
    val->isnull = false;
}

void _put(SequentialSearchST* self, key k, int v)
{
    if (subs_node(k, v, self->head)) return;
    Node* n = init_Node(k, v);
    add_node(n, &self->head);
}

void _printst(SequentialSearchST* self)
{
    printl(self->head);
}