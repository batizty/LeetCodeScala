#include <stdio.h>

/**
Remove Duplicates from Sorted Array II

Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice? For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]

下面能够保证：
 1 可以出现2次
 2 最多出现2次

**/

int removeDuplicates(int* numbers, int size) {
    if (size == 0)
        return size;

    int index = 0;
    for (int i = 0; i < size; i++) {
        // 这里需要处理下，如果是多次计算的话，需要判断多个
        if (i > 0
            && i < size - 1
            && numbers[ i ] == numbers[ i - 1 ]
            && numbers[ i ] == numbers[ i + 1 ])
            continue;
        numbers[ index++ ] = numbers[ i ];
    }
    return index;
}

int main( int argc, char** argv ) {
    int array[] = { 1, 1, 1, 2, 3};
    int array_size = 5;
    printf(" ++++ Test removeDuplicateNumber ++++\n");
    printf("array size(%d) --> ", array_size);
    for (int i = 0; i < array_size; i++) {
        printf("\t%d", array[ i ]);
    }
    printf("\n");
    int new_size = removeDuplicates( array, array_size );

    printf("new array size(%d) --> ", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("\t%d", array[ i ]);
    }
    printf("\n");
    return 0;
}
