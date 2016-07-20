#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int myAtoi(char* s) {
    if (s == NULL || s[0] == '\0')
        return 0;

    while (*s == ' ') s++;
    int sign = 1;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    else if (*s == '+') {
        s++;
    }
    long r = 0;
    while (*s >= '0' && *s <= '9') {
        r = r * 10 + *s - '0';
        if (r > INT_MAX)
            return sign < 0 ? INT_MIN : INT_MAX;
        s++;
    }
    r = r * sign;
    return (int)r;
}

int main (int argc, char** argv) {

	return 0;
}