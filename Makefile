CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/seqser/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/seqser/%.c, $(OBJ)/%.o, $(SRCS))
TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTOBJS=$(patsubst $(TEST)/%.c, $(TEST)/obj/%.o, $(TESTS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

all: $(BIN)

$(BIN): $(OBJS) $(BINDIR)
	$(CC) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/seqser/%.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c $(OBJS)
	$(CC) $< $(OBJS) -o $@ -lcriterion

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

test: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

$(OBJ)/array.o: $(SRC)/binser/array.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/arraytest: $(TEST)/arraytest.c $(OBJ)/array.o
	$(CC) $^ -o $@ -lcriterion

test-array: $(TEST)/bin/arraytest
	$<