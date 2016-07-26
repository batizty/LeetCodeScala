#include <stdio.h>

/**

Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].

* 有序数组，所以只需要保证 i 和 i+1 没有相同的就可以，
* 如果发现 i 和 i+1 有相同的,直接跳过
* 如果 i 和 i+1 不同，那么就执行一个拷贝，讲i拷贝到index+1的位置，
* index实际上是结果数组的游标
**/

int removeDuplicateNumber(int* numbers, int size) {
    if (size == 0)
        return 0;
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[ index ] != numbers[ i ])
            numbers[ ++index ] = numbers[ i ];
    }
    return index + 1;
}

int main(int argc, char** argv) {
    int array[] = {1, 1, 2};
    int array_size = 3;
    printf(" ++++ Test removeDuplicateNumber ++++\n");
    printf("array size(%d) --> ", array_size);
    for (int i = 0; i < array_size; i++) {
        printf("\t%d", array[ i ]);
    }
    printf("\n");
    int new_size = removeDuplicateNumber( array, array_size );

    printf("new array size(%d) --> ", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("\t%d", array[ i ]);
    }
    printf("\n");
    return 0;
}
