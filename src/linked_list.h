#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

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
void printn(Node* n);
void printl(Node* head);

