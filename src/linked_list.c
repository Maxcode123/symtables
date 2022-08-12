#include "linked_list.h"

Node* init_Node(char* key, int val)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->key = key;
    ptr->val = val;
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

Node* get_node(char* key, Node* head)
{
    Node* n = head;
    while (n != NULL) 
    {
        if (strcmp(n->key, key) == 0) return n;
        n = n->next;
    }
    return NULL;
}

int subs_node(char* key, int val, Node* head)
{
    Node* n = head;
    while (n != NULL)
    {
        if (strcmp(n->key, key) == 0)
        {
            n->val = val;
            return TRUE;
        }
        n = n->next;
    }
    return FALSE;
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