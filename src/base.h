/* Basic header; has standard library headers and macros, to be included by all
other header files */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char* key; // key type

typedef struct {
/* This type is specifically made to be returned (manipulated via pointer) when
by the get function. In order to distinguish when a returned value is NULL 
(i.e. when the key is not in the symbol table) the boolean isnull is used. */
    int value; // value returned by get
    bool isnull; // true only if function get does not find key
} Int;
