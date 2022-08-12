#include "linked_list.h"

void main()
{
    Node* n = init_Node("key1", 1);
    Node* n2 = init_Node("key2", 2);
    Node* h = init_List();
    add_node(n, &h);
    add_node(n2, &h);
    printl(h);
    if (has_node("key1", h)) printf("list has node n.\n");
}