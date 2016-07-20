#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "all_test.h"


int main(int argc, char** argv) {
    runReverseStringTest();
    runCanWinNimTest();

    return 0;
}

void showInfo(char* test_name) {
    printf("++++ run test %s ++++\n", test_name);
}
