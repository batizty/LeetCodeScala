#include <stdio.h>
#include "util.h"

/**
基本上就是一个二分查找
这里数组是循环数组，循环大小
如果直接找到 OK
如果没有找到，先判断哪半个数组是正常序列数组
找到正常序列数组，然后判断是否target在这个数组中
进行减枝操作，减少判断次数
**/
int searchInRotatedSortedArray(int *numbers, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left != right) {
        int mid = (right - left) / 2 + left;
        // printf("left = %d right = %d mid = %d value = %d\n", left, right, mid, numbers[ mid ] );
        if ( numbers[ mid ] == target )
            return mid;

        if (numbers[ left ] <= numbers[ mid ]) {
            if (numbers[ left ] <= target && target < numbers[ mid ] )
                right = mid;
            else
                left = mid + 1;
        } else {
            if (numbers[ right ] >= target && target > numbers[ mid ] )
                left = mid + 1;
            else
                right = mid;
        }
    }

    return -1;
}

int main( int argc, char** argv ) {
    int array[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int array_size = 8;
    int target = 2;
    printf(" ++++ Test searchInRotatedSortedArray ++++\n");
    printfIntArray(array, array_size);
    int index = searchInRotatedSortedArray( array, array_size, target );
    printf(" find target = %d in index = %d\n", target, index );
    return 0;
}
