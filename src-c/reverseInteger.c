#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int reverse(int x) {
    int y = 0;
    int x1 = x;
    while (x != 0) {
        int z = x % 10;
        if ((y * 10 / 10) != y) {
            return 0;
            }
        y = y * 10 + z;
        x = x / 10;
//        printf(" y = %d, x = %d\n", y, x);
    }
    return y;
}

int main (int argc, char** argv) {
    int x1 = 123;
    int x2 = -123;
    int x3 = 1534236469;
    printf("x1 = %d r = %d\n", x1, reverse(x1));
    printf("x2 = %d r = %d\n", x2, reverse(x2));
    printf("x3 = %d r = %d\n", x3, reverse(x3));

	return 0;
}