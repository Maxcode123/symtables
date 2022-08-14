#include <criterion/criterion.h>

#include "../src/seqser/llist.h"

Test(llisttest, initnode)
{
    Node* n = init_Node("abc", 10);
    cr_expect(strcmp(n->k, "abc") == 0, "init_Node: Node (field: key) not initialized as expected.");
    cr_expect(n->v == 10, "init_Node: Node (field: val) not initialized as expected.");
    Node* n2 = init_Node("def", 20);
    cr_expect(strcmp(n->k, n2->k) != 0 & n->v != n2->v, "init_Node: Initializes the same Node on each call.");
}

Test(llisttest, initlist)
{
    Node* head = init_List();
    cr_expect(head == NULL, "init_List: List head not initialized as expected.");
}


