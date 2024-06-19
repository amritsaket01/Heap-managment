#include"header.h"


int count_digit(long long int num) {
    int count=0;
    while(num!=0) {
        count++;
        num=num/10;
    }
    return count;
}

void print_bigint(struct BigInt__1024 n1){
    int i=0;
    while(i<MAX_SIZE && n1.digit[i]==0) {
        i++;
    }
    printf("%lld",n1.digit[i]);
    i++;   
    for(; i< MAX_SIZE; i++){
        if(i!=0) {
            int count=count_digit(n1.digit[i]);
            for(int j=0; j<9-count; j++) {
                printf("0");
                
        }
        printf("%lld",n1.digit[i]);
        }
        
    }
    printf("\n\n");
    
}


long long int Atoi(char n1[], int n){
    long long int ans=0;
for(int i = 0; i < n ; i++){
    ans = ans*10+n1[i]-'0';
}

return ans;
}

void convertStringToBigInt( char *number, struct BigInt__1024 *result) {
    int k = MAX_SIZE - 1;
    int count = 0;

    for (int i = strlen(number) - 1; i >= 0; i--) {
        count++;
        if (count == 9) {
            result->digit[k] = Atoi(number + i, 9);
            count = 0;
            k--;
        }
    }
      // If there are remaining digits after the loop, convert them
    if (count > 0) {
        result->digit[k] = Atoi(number, count);
    }
}
