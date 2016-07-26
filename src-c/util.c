#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void printfIntArray(int* array, int sz) {
    printf(" array (%d) ->", sz);
    for( int i = 0; i < sz; i++ )
        printf("\t%d", array[ i ] );
    printf("\n");
    return;
    }
