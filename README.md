# symtables
### *Symbol table implementations*</br>
Symbol tables (a.k.a. dictionaries, maps) are data structures that hold key-value pairs.</br>
The symbol tables implemented in this project have strings as keys and integers as values.</br>
Algorithms taken from: [Robert Sedgewick, Kevin Wayne, Algorithms, 4th edition.](https://www.goodreads.com/book/show/10803540-algorithms?from_search=true&from_srp=true&qid=6vTB9QpdFv&rank=2)

## project tree
![image](https://user-images.githubusercontent.com/64724733/185734501-34845367-da34-419d-97cd-2cfdd1fd8fe7.png)

##
seqser contains the code for a linked-list sequential search symbol table implementation.</br>
binser contains the code for a binary search symbol table that uses dynamically-sized arrays.</br>
tests contains tests for all modules.</br>
All functions and structs are documented in their corresponding header files.</br>
Once you meet all below requirements you should be able to run `make test` and check that everything is working correctly.</br>

## requirements
* C compiler (I used gcc 12.1.1)
* make
* [criterion lib](https://github.com/Snaipe/Criterion)

