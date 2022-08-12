CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/main
TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTOBJS=$(patsubst $(TEST)/%.c, $(TEST)/obj/%.o, $(TESTS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

all: $(BIN)

$(BIN): $(OBJS) $(BINDIR)
	$(CC) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c $(OBJS)
	$(CC) $< $(OBJS) -o $@ -lcriterion

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(BINDIR):
	mkdir $@

test: $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	rm -rf $(BINDIR)/* $(OBJ)/* $(TEST)/bin/*