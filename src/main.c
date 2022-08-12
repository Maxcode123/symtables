#include "linked_list.h"
#include "symtable.h"

void main()
{
    ST* st = init_ST();
    put("a_", 0, st);
    put("b_", 2, st);
    printst(st);
    int* c = get("c_", st);
    if (c == NULL) printf("c is NULL\n");
}