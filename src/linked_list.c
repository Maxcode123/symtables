#include "linked_list.h"

Node* init_Node(char* key, int val)
{
    Node n = {.key = key, .val = val};
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr = &n;
    return ptr;
}

void add_node(Node* n, Node** head_ptr)
{
    if (*head_ptr == NULL)
    {
        *head_ptr = n;
        n->next = NULL;
    }
    else
    {
        n->next = *head_ptr;
        *head_ptr = n;
    }
}

void printn(Node* n)
{
    printf("key: %s, value: %d\n", n->key, n->val);
}

void printl(Node* head)
{
    Node* n;
    n = head;
    while (n != NULL) 
    {
        printn(n);
        n = n->next;
    }
}