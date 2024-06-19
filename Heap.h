
#include <stdio.h>
char HeapMemory[40000];

#define HEAP_SIZE 40000

typedef struct metaBlock {
  size_t size;
  int free;
  struct metaBlock *next;
} metaBlock;

metaBlock *freelist=(void*)HeapMemory;
void heap_initialize();
void heap_split(metaBlock *fitting_slot, size_t size);
void *heap_Allocate(size_t noOfBytes);
void heap_merge();
void heap_My_free(void *ptr);
void heap_print_size();


void heap_initialize() {

  freelist->size = sizeof(HeapMemory) - sizeof(metaBlock);
  freelist->free = 1;
  freelist->next = NULL;
}

void heap_split(metaBlock *fitting_slot, size_t size) {
  metaBlock *new = (void *)(((void *)fitting_slot) + size + sizeof(metaBlock));
  new->free = 1;
  new->next = fitting_slot->next;
  new->size = (fitting_slot->size) - size - sizeof(metaBlock);
  fitting_slot->size = size;
  fitting_slot->free = 0;
  fitting_slot->next = new;
}

void *heap_Allocate(size_t noOfBytes) {
  metaBlock *current, *previous;
  void *result;

  if (!(freelist->size)) {
    heap_initialize();
  }

  current = freelist;
  while ((current->size < noOfBytes) || (current->free == 0) && current->next != NULL) {
    previous = current;
    current = current->next;
  }

  if (current->size == noOfBytes) {
    current->free = 0;
    result = current; 
    printf("Exact Fitting metaBlock is allocated from \n#starting address: %p\n#ending address: %p\n#size: %lu \n", result+8 ,result + 8 +(noOfBytes + sizeof(metaBlock)),noOfBytes );
  } 
  else if ((current->size) > (noOfBytes + sizeof(metaBlock))) {
    heap_split(current, noOfBytes);
    result = current; 
    printf("Fitting metaBlock is allocated with splitting from \n#starting address: %p\n#ending address: %p\n#size: %lu \n", result+8 ,result + 8 +(noOfBytes + sizeof(metaBlock)),noOfBytes);
  } 
  else {
    result = NULL;
    printf("No enough space in memory...");
  }
  return result;
}



void heap_merge() {
    metaBlock *curr, *prev;
    curr = freelist;
    while (curr != NULL && curr->next != NULL) {
        if (curr->free && curr->next->free) {
            curr->size += (curr->next->size) + sizeof(metaBlock);
            printf("#Memory of size %lu is merged successfully....\n",(curr->size));
            curr->next = curr->next->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void heap_My_free(void *ptr) {
    if (ptr >= (void *)HeapMemory && ptr <= (void *)(HeapMemory + HEAP_SIZE)) {
        metaBlock *curr = (metaBlock *)ptr;
       
        curr->free = 1;
        curr--; 
        heap_merge();
    } else {
        printf("Please provide a valid pointer allocated by heap_Allocate\n");
    }
}

void heap_print_size(){
    metaBlock* current = freelist;
    int i=1;
    size_t total_free=0;
    size_t total_n_free=0;
    printf("\n---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    while(current != NULL){
        printf("size of block %d in HeapMemory is %lu",i,current->size);
        if(current->free){
            printf(" - this block is free\n");
            total_free+=current->size;
        } else {
            printf(" - this block is not free\n");
            total_n_free+=current->size;
        }
        i++;
        current=current->next;
        
    }
       printf("\n---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Total free memory is %lu\n",total_free);
    printf("Total accupied memory is %lu\n",total_n_free);
     printf("\n---------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------\n");

}

