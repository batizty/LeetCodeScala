#include <stdio.h>


int isPalindrome(int x) {
    if ( x < 0 )
        return 0;
    
    if (x < 10 )
        return 1;
    
    int len = 1;
    while (x / len >= 10) {
        len *= 10;
    }
    
    while ( x != 0 ) {
        int left = x / len;
        int right = x % 10;
        if (left != right)
            return 0;
        
        x = x - left * len;
        x = x / 10;
        len = len / 100;
    }
    
    return 1;
}

int main( int argc, char** argv) {
	int x = 42;
	int ret = isPalindrome(x);
	if (ret == 0)
		printf(" x = %d is not isPalindrome number", x );
	else 
		printf(" x = %d is not isPalindrome number", x );
	return 0;
}
