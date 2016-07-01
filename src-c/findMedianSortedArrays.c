#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double findKth(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    if (nums2Size < nums1Size)
        return findKth(nums2, nums2Size, nums1, nums1Size, k);

    if (nums1Size == 0)
        return nums2[ k - 1 ];

    if (nums2Size == 0)
        return nums1[ k - 1 ];

    if (k == 1) {
        if (nums1[ 0 ] > nums2[ 0 ])
            return nums2[ 0 ];
        else
            return nums1[ 0 ];
    }

    int k1 = k / 2;
    if (k1 > nums1Size)
        k1 = nums1Size;
    int k2 = k - k1;

    if (nums1[ k1 - 1] > nums2[ k2 - 1 ])
        return findKth(nums1, nums1Size, nums2 + k2, nums2Size - k2, k - k2);
    else if (nums1[ k1 - 1 ] < nums2[ k2 - 1 ])
        return findKth(nums1 + k1, nums1Size - k1, nums2, nums2Size, k - k1);
    else
        return nums1[ k1 - 1 ];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if (total % 2) {
        return findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    } else {
        return ( findKth(nums1, nums1Size, nums2, nums2Size, total / 2 ) +
            findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1) ) / 2;
    }
}


int main(int argc, char** argv) {
    int arr1[2] = { 1, 3 };
    int arr2[1] = { 2 };
    int arr3[2] = { 1, 2 };
    int arr4[2] = { 3, 4 };
    int arr5[1] = { 1 };
    int arr6[3] = { 2, 3, 4 };

    double ret = findMedianSortedArrays(arr5, 1, arr6, 3);
    printf(" findMedianSortedArrays result = %f\n", ret);
    return 0;

}


