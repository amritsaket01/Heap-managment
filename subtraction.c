#include"header.h"


struct BigInt__1024 subtraction(struct BigInt__1024 n1, struct BigInt__1024 n2, struct BigInt__1024 result)
{

    
    long long borrow = 0;
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
       
        long long int diff = n1.digit[i] - n2.digit[i] - borrow;

       
        if (diff < 0) {
            diff += MAX_LIMIT_FOR_BIGINT;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digit[i] = diff;
    }

    return result;
}
