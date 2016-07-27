#include "util.h"


void reverseBigInterger(char* str, int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        char tmp = str[ left ];
        str[ left ] = str[ right ];
        str[ right ] = tmp;
        left++;
        right--;
    }
}

char* multiplyBigInteger(char* number1, char* number2) {
    if (number1 == NULL || number2 == NULL)
        return NULL;

    int len1 = strlen( number1 );
    int len2 = strlen( number2 );

    if (len1 == 0 || len2 == 0)
        return NULL;

    char* result = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    memset(result, '0', len1 + len2);
    result[ len1 + len2 ]= '\0';

    reverseBigInterger(number1, len1);
    reverseBigInterger(number2, len2);

    int multiFlag = 0;
    int addFlag = 0;
    for (int i = 0; i < len2; i++) {
        // 循环计算 A * B[i]
        multiFlag = 0;
        addFlag = 0;
        for (int j = 0; j < len1; j++) {
            int temp = (number1[ j ] - '0') * (number2[ i ] - '0') + multiFlag;
            multiFlag = temp / 10;
            temp = temp % 10;
            int temp2 = temp + (result[ i + j ] - '0') + addFlag;
            addFlag = temp2 / 10;
            temp2 = temp2 % 10;
            result[ i + j ] = '0' + temp2;
        }
        result[ i + len1 ] = addFlag + multiFlag + '0';
    }
    reverseBigInterger(result, len1 + len2);

    return result;
}


int main(int argc, char** argv) {
    printfTestInfo("BigIntegerMultply");
    char A[] = "9999";
    char B[] = "9999";
    char* C = multiplyBigInteger(A, B);
    printf("A * B = C\n");
    printf("A = %s\n", A);
    printf("B = %s\n", B);
    printf("C = %s\n", C);
    return 0;
}
