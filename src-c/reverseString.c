#include "reverseString.h"

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

void runReverseString() {
    char* s = "hello world";
    printf(" original str = %s\n", s);
    printf(" reversed str = %s\n", reverseString(s));
}
