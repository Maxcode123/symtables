#pragma once

#include "base.h"
#include "linked_list.h"

typedef struct ST {
    Node* head; // pointer to linked list head
} ST;

ST* init_ST();
int* get(char* key, ST* st);
void put(char* key, int val, ST* st);
void printst(ST* st);