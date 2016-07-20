#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>


char* getLongestCommonPrefix(char* str1, char* str2) {
    int str1_len = strlen( str1 );
    int str2_len = strlen( str2 );

    if (str1_len == 0 || str2_len == 0)
        return "";

    printf(" str1_len = %d str2_len = %d\n", str1_len, str2_len);
    int len = str1_len > str2_len ? str2_len : str1_len;
    char* ptr = (char *)malloc(sizeof(char) * len);
    int i = 0;
    int j = 0;
    while (i < len) {
        if (str1[ i ] == str2[ i ]) {
            ptr[j++] = str1[i];
            i++;
        }
        else
            break;
    }
    ptr[j] = '\0';
    return ptr;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    if (strsSize == 1)
        return strs[ 0 ];

    char *common_str = getLongestCommonPrefix( strs[ 0 ], strs[ 1 ] );
    int max_str_len = strlen( common_str );
    if (common_str == NULL)
        return common_str;
    int i = 2;

    while ( i < strsSize )  {
        char *tmp = getLongestCommonPrefix( common_str, strs[i] );
        if (tmp == NULL) {
            free( common_str );
            return NULL;
        }
        else if (strlen( tmp ) < max_str_len ) {
            max_str_len = strlen( tmp );
            free(common_str);
            common_str = tmp;
        }
        i++;
    }
    return common_str;
}

int main(int argc, char** argv) {
    char* strs[3] = { "", "", "" };
    char* result = longestCommonPrefix(strs, 3);
    printf("result = %s\n", result);
    return 0;
}
