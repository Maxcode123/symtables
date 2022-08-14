#include <criterion/criterion.h>

#include "../src/seqser/llist.h"

Test(llisttest, initnode)
{
    Node* n = init_Node("abc", 10);
    cr_expect(strcmp(n->k, "abc") == 0, "Node key not initialized as expected.");
    cr_expect(n->v == 10, "Node val not initialized as expected.");
    Node* n2 = init_Node("def", 20);
    cr_expect(strcmp(n->k, n2->k) != 0 & n->v != n2->v, "init_Node Initializes the same Node on each call.");
}

Test(llisttest, initlist)
{
    Node* head = init_List();
    cr_expect(head == NULL, "List head not initialized to NULL.");
}

Test(llisttest, addnode)
{
    Node* n = init_Node("ABC", 417);
    Node* h = init_List();
    add_node(n, &h);
    cr_assert(strcmp(h->k, "ABC") == 0, "add_Node does not add Node key.");
    cr_assert(h->v == 417, "add_Node does not add Node value.");
}

Test(llisttest, getnode)
{
    Node* n = init_Node("DEF", 1543);
    Node* h = init_List();
    h = n;
    n->next = NULL;
    Node* n2 = get_node("DEF", h);
    cr_assert(strcmp(n2->k, n->k) == 0 & n2->v == n->v, "get_Node does not return correct Node.");
}

Test(llisttest, subsnode)
{
    Node* n = init_Node("DEF", 1543);
    Node* h = init_List();
    h = n;
    n->next = NULL;
    cr_assert(subs_node("DEF", 10, h), "subs_node does not return true when substituting.");
    cr_assert(h->v == 10, "subs_node does not substitute value.");
    cr_assert(!subs_node("ADA", 198, h), "subs_node does not return false when not substituting.");

}