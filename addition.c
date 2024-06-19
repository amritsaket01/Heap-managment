#include"header.h"

struct BigInt__1024 addition(struct BigInt__1024 n1 ,struct BigInt__1024 n2, struct BigInt__1024 result ){
    
    long long int carry=0;
for (int i=MAX_SIZE-1; i>=0; i--){
    result.digit[i]=(n1.digit[i]+n2.digit[i]+carry)%MAX_LIMIT_FOR_BIGINT;
    carry=(carry+n1.digit[i]+n2.digit[i])/MAX_LIMIT_FOR_BIGINT;
}
return result;
}