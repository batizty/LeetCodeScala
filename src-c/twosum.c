#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j = 0;
	int* result = (int*)malloc(sizeof(int)*2);

	for (i = 0; i < numsSize; i++ )
		for (j = i + 1; j < numsSize; j++ ) { 
			if ( (nums[i] + nums[ j ]) == target ) {
				result[ 0 ] = i;
				result[ 1 ] = j;
				return result;
			}
		}

	free( result );
	return NULL; 
}


int main (int argc, char** argv) {
	int array[] = {2, 7, 11, 15};
    size_t n = sizeof(array)/sizeof(int);
    int target = 9;

    int* ret = twoSum(array, n, target);
    if (ret != NULL)
    	printf("result = %d %d\n", ret[0], ret[1]);
    else
    	printf(" no result\n");

	return 0; 
}
