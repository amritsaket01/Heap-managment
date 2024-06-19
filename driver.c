#include"header.h"



int main() {
    struct BigInt__1024 n1, n2;
    n1 = intialize(n1);
    n2 = intialize(n2);

    FILE *file = fopen("inputfile.txt", "r");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char number1[310]; 
    char number2[310]; 

    if (fscanf(file, "%s %s", number1, number2) != 2) {
        printf("Error reading numbers from the file.\n");
        fclose(file);
        return 1;
    }
   compareAndSwap(number1, number2, sizeof(number1) / sizeof(number1[0]));
    

    fclose(file);

    convertStringToBigInt(number1, &n1);
    convertStringToBigInt(number2, &n2);
     printf("Number 1: ");
     print_bigint(n1);
     printf("Number 2: ");
     print_bigint(n2);


    struct BigInt__1024 result;
    result = intialize(result);
    result = multiplication(n1, n2);
    printf("Multiplication: ");
    print_bigint(result);

    struct BigInt__1024 result_add;
    result_add = intialize(result);
    result_add = addition(n1, n2,result_add);
    printf("Addition: ");
    print_bigint(result_add);

    struct BigInt__1024 result_sub;
    result_sub = intialize(result);
    result_sub = subtraction(n1, n2,result_sub);
    printf("Subtractiontion: ");
    print_bigint(result_sub);




    

    return 0;
}