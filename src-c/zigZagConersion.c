#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*char* convert(char* s, int numRows) {
    if (s == NULL || numRows <= 1)
        return s;
    int len = strlen( s );
    if (len <= 1)
        return s;
    int unit_sz = numRows * 2 - 2;
    int unit_count = floor(len / unit_sz);
    int i = 0;
    char* result = (char *)malloc(sizeof(char) * unit_count * numRows * numRows );
    printf(" unit_sz= %d unit_count= %d total =   \n", unit_sz, unit_sz);

    for (i = 0; i < unit_count * numRows * numRows - 1; i++)
        result[ i ] = '_';
    result[ i ] = '\0';
    for (i = 1; i < numRows ; i++)
        result[ unit_count * numRows * i - 1 ] = '\n';

     i = 0;
    while (i <= len) {
        int pos = getPosition(i, numRows, numRows * unit_count );
        printf(" pos = %d char = %c\n", pos, s[i]);
        result[ getPosition(i, numRows,  numRows * unit_count) ] = s[ i ];
        i++;
    }

    return result;
}*/

char* convert(char* s, int numRows) {
    int len = strlen( s );
    if (s == NULL || len <= 0 || numRows <= 0)
        return "";
    if (numRows == 1)
        return s;

    char* result = (char*)malloc(sizeof(char) * len);
    result[ len - 1 ] = '\0';
    int size = 2 * numRows - 2;
    int idx = 0;

    for (int i = 0; i < numRows; i++) {
        for(int j = i; j < len; j = j + size) {
            result[ idx++ ] = s[ j ];
            int j2 = (j + size- 2 * i);
            if (i != 0 && i != numRows - 1 && j2 < len ) {
                result[ idx++ ] = s[j2];
            }
        }
    }

    return result;
}

int main(int argc, char** argv) {
    char* s = "PAYPALISHIRING";
    char* s1 = "ABCDEFGHTIJ";
    char* s2 = "";
    char* s3 = "twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd";
    char* s4 = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    printf("original s = %s\n", s4);
    printf("converteds = %s\n", convert(s4, 2));


    return 0;
}
