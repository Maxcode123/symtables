CC=gcc
SRC=src
OBJ=obj
TEST=tests
BIN=$(TEST)/bin


$(OBJ):
	mkdir -p $@

test: test-list test-seqser test-array test-binser


$(OBJ)/llist.o: $(SRC)/seqser/llist.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/llisttest: $(TEST)/llisttest.c $(OBJ)/llist.o
	mkdir -p $(BIN)
	$(CC) $^ -o $@ -lcriterion

test-list: $(TEST)/bin/llisttest
	$<

$(OBJ)/seqser_st.o: $(SRC)/seqser/seqser_st.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/seqsersttest: $(TEST)/seqsersttest.c $(OBJ)/seqser_st.o $(OBJ)/llist.o
	mkdir -p $(BIN)
	$(CC) $^ -o $@ -lcriterion

test-seqser: $(TEST)/bin/seqsersttest
	$<


$(OBJ)/array.o: $(SRC)/binser/array.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/arraytest: $(TEST)/arraytest.c $(OBJ)/array.o
	mkdir -p $(BIN)
	$(CC) $^ -o $@ -lcriterion

test-array: $(TEST)/bin/arraytest
	$<


$(OBJ)/binser_st.o: $(SRC)/binser/binser_st.c $(OBJ)
	$(CC) -c $< -o $@ 

$(TEST)/bin/binsersttest: $(TEST)/binsersttest.c $(OBJ)/binser_st.o $(OBJ)/array.o
	mkdir -p $(BIN)
	$(CC) $^ -o $@ -lcriterion

test-binser: $(TEST)/bin/binsersttest
	$<


clean:
	rm -rf tests/bin/* obj/*
	rmdir tests/bin obj