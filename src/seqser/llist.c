#include "llist.h"

Node* init_Node(key k, int v)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->k = k;
    ptr->v = v;
    ptr->next = NULL;
    return ptr;
}

Node* init_List()
{
    return NULL;
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

Node* get_node(key k, Node* head)
{
    Node* n = head;
    while (n != NULL) 
    {
        if (strcmp(n->k, k) == 0) return n;
        n = n->next;
    }
    return NULL;
}

bool subs_node(key k, int v, Node* head)
{
    Node* n = head;
    while (n != NULL)
    {
        if (strcmp(n->k, k) == 0)
        {
            n->v = v;
            return true;
        }
        n = n->next;
    }
    return false;
}

void printn(Node* n)
{
    printf("key: %s, value: %d\n", n->k, n->v);
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