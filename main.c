#include "Heap.h"

int main()
{
    
    printf("\n--------------------1 st address------------------- \n");
    int *p = (int *)
    heap_Allocate(150 * sizeof(int));
    printf("\n--------------------2 st address------------------- \n");
    char *q = (char *)heap_Allocate(19999 * sizeof(char));
     printf("\n--------------------3 st address------------------- \n");
    int *r = (int *)heap_Allocate (4800* sizeof(int));
    r=r+8;
    for(int i=0; i<50; i++) {
        r[i]=i;
    }
    for(int i=0; i<50; i++) {
        printf("%d ", r[i]);
    }
     printf("\n ");

    heap_My_free(p);
    heap_My_free(q);
    heap_My_free(r);
    printf("\n--------------------4 st address------------------- \n");
    int *l = (int *)heap_Allocate (400* sizeof(int));
    printf("\n--------------------5 st address------------------- \n");
    char *w = (char *)heap_Allocate(700);
    printf("\n--------------------6 st address------------------- \n");
    int *k = (int *)heap_Allocate(500 * sizeof(int));

    //freeing all address allocated
    heap_print_size();
    heap_My_free(l);
    heap_My_free(w);
    heap_My_free(k);
    
    heap_print_size();


    
    printf("\nAllocation and deallocation is done successfully!\n");
}
