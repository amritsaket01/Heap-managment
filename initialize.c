#include"header.h"

struct BigInt__1024 intialize(struct BigInt__1024 n1){
for (int i=0; i < MAX_SIZE ; i++){
    n1.digit[i]=0;
      
}
return n1;
}