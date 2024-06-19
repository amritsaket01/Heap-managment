#include<stdio.h>
#include<math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 35
#define MAX_LIMIT_FOR_BIGINT 1000000000

struct BigInt__1024{
    long long int digit[MAX_SIZE];

};

void compareAndSwap(char *number1, char *number2, int size);

struct BigInt__1024 intialize(struct BigInt__1024 n1);

struct BigInt__1024 addition(struct BigInt__1024 n1 ,struct BigInt__1024 n2, struct BigInt__1024 result );

struct BigInt__1024 subtraction(struct BigInt__1024 n1, struct BigInt__1024 n2, struct BigInt__1024 result) ;

struct BigInt__1024 multiplication(struct BigInt__1024 n1, struct BigInt__1024 n2);

int count_digit(long long int num) ;

void print_bigint(struct BigInt__1024 n1);


long long int Atoi(char n1[], int n);

void convertStringToBigInt( char *number, struct BigInt__1024 *result) ;