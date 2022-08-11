#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    char* key;
    int val;
    struct Node* next;
} Node;

Node* init_Node(char* key, int val);
void add_node(Node* n, Node** head_ptr);
void printn(Node* n);
void printl(Node* head);

