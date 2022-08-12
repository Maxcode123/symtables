#include "symtable.h"

ST* init_ST()
{
    ST* st = (ST*)malloc(sizeof(ST));
    st->head = init_List();
    return st;
}

int* get(char* key, ST* st)
{
    Node* n = get_node(key, st->head);
    if (n == NULL) return NULL;
    return &n->val;
}

void put(char* key, int val, ST* st)
{
    if (subs_node(key, val, st->head)) return;
    Node* n = init_Node(key, val);
    add_node(n, &st->head);
}

void printst(ST* st)
{
    printl(st->head);
}