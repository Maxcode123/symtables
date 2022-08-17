#include <criterion/criterion.h>

#include "../src/seqser/seqser_st.h"

Test(seqsersttest, initst)
{
    SequentialSearchST* st = init_ST();
    cr_assert(st->head == NULL, "Sequential ST head not iniatialized to NULL.");
}

Test(seqsersttest, gettest)
{
    SequentialSearchST* st = init_ST();
    Node* n = init_Node("KAJ", 9321);
    add_node(n, &st->head);
    Int val;
    st->get(st, "KAJ", &val);
    cr_assert(val.value == 9321 & !val.isnull, "get does not return correct Int");
    st->get(st, "ALALA", &val);
    cr_assert(val.isnull, "get does not return correct NULL Int.");
}

Test(seqsersttest, puttest)
{
    SequentialSearchST* st = init_ST();
    st->put(st, "A", 191);
    st->put(st, "BPA", 65);
    st->put(st, "A", 10);
    cr_assert(get_node("A", st->head)->v == 10, "put does not substitute existing value.");
    cr_assert(get_node("BPA", st->head)->v == 65, "put does not insert value.");
}