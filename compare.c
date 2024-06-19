#include "header.h"

void compareAndSwap(char *number1, char *number2, int size) {
    char temp[310];
    
    if (strlen(number1) < strlen(number2)) {
        strcpy(temp, number1);
        strcpy(number1, number2);
        strcpy(number2, temp);
    } else if (strlen(number1) == strlen(number2)) {
        int a = number1[0] - '0';
        int b = number2[0] - '0';
        
        if (a < b) {
            strcpy(temp, number1);
            strcpy(number1, number2);
            strcpy(number2, temp);
        }
    }
}
