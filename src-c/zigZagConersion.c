#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int getPosition(int i, int row, int width) {
    int sz = row * 2 - 2;
    int u_index = i / sz;
    int i_index = i % sz;
    int x = i_index % row;
    int y = 0;
    if (i_index >= row) {
        x = i_index + 1 - row;
        y = i_index + 1 - row;
    }
    y = u_index * row + y - u_index;
    int pos = x * width + y;
    printf("i = %d u_idx = %d i_indx = %d x = %d y = %d pos = %d\n", i, u_index, i_index, x, y, pos);
    return pos;
}

char* convert(char* s, int numRows) {
    if (s == NULL || numRows <= 1)
        return s;
    int len = strlen( s );
    if (len <= 1)
        return s;
    int unit_sz = numRows * 2 - 2;
    int unit_count = floor(len / unit_sz);
//    printf(" len = %d numRows = %d unit_sz = %d unit_count = %d\n", len, numRows, unit_sz, unit_count);
    int i = 0;
    char* result = (char *)malloc(sizeof(char) * unit_count * numRows * numRows );

    for (i = 0; i < unit_count * numRows * numRows - 1; i++)
        result[ i ] = ' ';
    result[ i ] = '\0';
    for (i = 1; i < numRows ; i++)
        result[ unit_count * numRows * i - 1 ] = '\n';

    i = 0;
    while (i <= len) {
        result[ getPosition(i, numRows,  numRows * unit_count) ] = s[ i ];
        i++;
    }

    return result;
}

int main(int argc, char** argv) {
    char* s = "PAYPALISHIRING";
    char* s2 = "";
    char* s3 = "twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd";
    char* r = convert(s, 14);
    printf("\t original s = %s\n\t converted s = \n%s\n", s, r);

    return 0;
}