#include "all_test.h"

char*  reverseString(char *s) {
    int len = strlen( s );
    if (len <= 0 || s == NULL)
        return "";

    char tmp = ' ';
    int left = 0;
    int right = len - 1;
    while (left < right) {
        tmp = s[ left ];
        s[ left ] = s[ right ];
        s[ right ] = tmp;
        left++;
        right--;
    }
    return s;
}

void runReverseStringTest() {
    printf("++++ RUN TEST %s ++++\n", __FUNCTION__);
    char* s = "hello world";
    printf(" original str = %s\n", s);
    // char* s0 = reverseString(s);
    // printf(" reversed str = %s\n", s0);
    return;
}
