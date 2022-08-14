CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/seqser/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/seqser/%.c, $(OBJ)/%.o, $(SRCS))
TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTOBJS=$(patsubst $(TEST)/%.c, $(TEST)/obj/%.o, $(TESTS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

test: test-list test-seqser test-array test-binser


$(OBJ)/llist.o: $(SRC)/seqser/llist.c
	$(CC) -c $< -o $@

$(TEST)/bin/llisttest: $(TEST)/llisttest.c $(OBJ)/llist.o
	$(CC) $^ -o $@ -lcriterion

test-list: $(TEST)/bin/llisttest
	$<

$(OBJ)/seqser_st.o: $(SRC)/seqser/seqser_st.c
	$(CC) -c $< -o $@

$(TEST)/bin/seqsersttest: $(TEST)/seqsersttest.c $(OBJ)/seqser_st.o $(OBJ)/llist.o
	$(CC) $^ -o $@ -lcriterion

test-seqser: $(TEST)/bin/seqsersttest
	$<


$(OBJ)/array.o: $(SRC)/binser/array.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/arraytest: $(TEST)/arraytest.c $(OBJ)/array.o
	$(CC) $^ -o $@ -lcriterion

test-array: $(TEST)/bin/arraytest
	$<


$(OBJ)/binser_st.o: $(SRC)/binser/binser_st.c $(OBJ)
	$(CC) -c $< -o $@ 

$(TEST)/bin/binsersttest: $(TEST)/binsersttest.c $(OBJ)/binser_st.o $(OBJ)/array.o
	$(CC) $^ -o $@ -lcriterion

test-binser: $(TEST)/bin/binsersttest
	$<


clean:
	rm -r tests/bin/* obj/*