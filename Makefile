CPP=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/main

all: $(BIN)

$(BIN): $(OBJS)
	$(CPP) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CPP) -c $< -o $@

clean:
	rm -rf $(BINDIR)/* $(OBJ)/*