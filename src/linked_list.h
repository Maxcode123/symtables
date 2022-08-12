#pragma once

#include "base.h"

typedef struct Node
{
    char* key;
    int val;
    struct Node* next;
} Node;

Node* init_Node(char* key, int val);
Node* init_List();
void add_node(Node* n, Node** head_ptr);
int equal_nodes(Node* n1, Node* n2);
int has_node(char* key, Node* head);
void printn(Node* n);
void printl(Node* head);

