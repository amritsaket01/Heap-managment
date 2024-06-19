#include "header.h"

struct BigInt__1024 multiplication(struct BigInt__1024 n1, struct BigInt__1024 n2)
{
    // Initialize result to 0

    struct BigInt__1024 result;
    result = intialize(result);

    int error = 0;
    long long int carry = 0;
    for (int i = 34; i >= 0; i--)
    {
        for (int j = 34; j >= 0; j--)
        {
            int index = i + j - 34;
            if (index >= 0)
            {
                result.digit[index] = (result.digit[index] + (n1.digit[j] * n2.digit[i]) % MAX_LIMIT_FOR_BIGINT) % MAX_LIMIT_FOR_BIGINT;
                carry = (n1.digit[j] * n2.digit[i]) / MAX_LIMIT_FOR_BIGINT;

                if (index != 0)
                {
                    result.digit[index - 1] = result.digit[index - 1] + carry;
                    carry = 0;
                }

                else
                {
                    if (carry != 0)
                    {
                        carry = 0;
                        error = 1;
                    }
                }
            }
            else
            {
                error = 1;
            }
        }
    }
    if (error == 1 && result.digit[0] != 0)
    {
        printf("Limit is extended to 1024 bits\n");
    }
    return result;
}