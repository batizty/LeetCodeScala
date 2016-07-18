#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int area = 0;
    if (heightSize <= 0)
        return 0;
    if (heightSize <= 1)
        return height[0];

    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int w = right - left;
        int h = height[ left ] > height[ right ] ? height[ right ] : height[ left ];
        int tmp = w * h;
        area = tmp > area ? tmp : area;

        if (height[ left ] > height[right])
            right--;
        else
            left++;
    }
    return area;
}

int main(int argc, char** argv) {
    int height[3] = {1, 2, 1};
    int heightSize = 3;
    printf(" max area = %d\n", maxArea(height, heightSize));
    return 0;
}
