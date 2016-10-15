
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "mymalloc.h"

static char myblock[5000];
static char *error = "Not Enough Space";
int first =0;

void defrag();

int free1(void * ptrFree);
void * mymalloc(unsigned int size);
void defrag();
void defrag(){
  
  
  char * tracker = myblock;
  unsigned short meta_size1 = * (unsigned short *) tracker;
  unsigned short block_size1 = (meta_size1 - (meta_size1%2));
  unsigned short meta_size2 = * (unsigned short *) (tracker +2 + block_size1);
  unsigned short block_size2 = (meta_size2 - (meta_size2%2));
  while((tracker + 2 + block_size1)< &myblock[4998]){
  	meta_size1 = * (unsigned short *) tracker;
  	block_size1 = (meta_size1 - (meta_size1%2));
  	meta_size2 = * (unsigned short *) (tracker +2 + block_size1);
  	block_size2 = (meta_size2 - (meta_size2%2));
  while(!(meta_size1%2) && !(meta_size2) && (tracker + 2 + block_size1)< &myblock[4998]){  
    *(unsigned short *)tracker += (block_size2 + 2);
    meta_size1 = * (unsigned short *) tracker;
  	block_size1 = (meta_size1 - (meta_size1%2));
  	meta_size2 = * (unsigned short *) (tracker +2 + block_size1);
  	block_size2 = (meta_size2 - (meta_size2%2));
    }

    tracker += (2 + *(unsigned short *)tracker + block_size1);


    }
  }
int free1(void * ptrFree){
  char * ptrFree1 = (char *) ptrFree;
  //printf("Begining of Array: %p, End of Array: %p, ptrFree: %p", &myblock[0], &myblock[4999], ptrFree);
  if(ptrFree1 < &myblock[2] || ptrFree1>&myblock[4999]){ printf("Makes free1\n"); return 0;}
  printf("Makes it here 22222\n");
  char * tracker = myblock;
  while(tracker<=(ptrFree1-2)){
    if(tracker==(ptrFree1-2) && !(*(unsigned short *)tracker%2)){
    	printf("Free makes it here\n");
      *(unsigned short*)tracker = *(unsigned short *)tracker-1;
      defrag();
      return 1;
    }
   
   unsigned short size = *(unsigned short *)tracker;
    tracker+=(size - (size%2) +2);
  }
  
  return 0;

}

void * mymalloc (unsigned int size) {
  printf("Size of this malloc %u\n", size );
  if (first == 0){
  	printf("makes it here\n"); 
    *(unsigned short *) myblock = (unsigned short) 4998;
    first=1;
  }

  if (size < 0){
    printf("Must be greater than 0\n");
    return 0;
  }
  
  if(size >4998){
    printf("Memory request larger then size of heap\n");
    return 0;
  }
  if(!size)size=2;

  if (size%2) size++;

  unsigned short short_size= size;
  char *curr = myblock;
  unsigned short currBlocksize =0;

  while(curr < &myblock[4999]){
 	currBlocksize = (*(unsigned short*)curr - (*(unsigned short *)curr%2));
 	//printf("Current Block Size: %u\n", currBlocksize);
  

  if (*(unsigned short *) curr%2 == 0 && currBlocksize >= short_size){  //check if location is free
          *(unsigned short *)curr = short_size+1;   //+1 to signify allocated space 
          *(unsigned short *)(curr+short_size+2) = currBlocksize - short_size-2;
          return (void *) curr+2;
        }
        curr+=currBlocksize +2;
    }
  
  printf("Not Enough Space - 0 signifies unallocated\n");
  return NULL;
}



int main(int argc, char *argv[]) {

testD();

  /*char * track = myblock;
  while(track<&myblock[4999]){
  	unsigned short meta = *(unsigned short *)track;
  	unsigned short blockSize = (meta - (meta%2));
  	printf("unsi: %u\n", meta);
  	printf("Actual size: %u", blockSize);
  	printf("Size of meta: %u\n", meta);
  	printf("Pointer %p\n", track);
  	track += (2 + blockSize);
  	//+ (*(unsigned short *)track - (*(unsigned short *)track%2));
  	printf("Pointer %p\n", track);
  }

*/
  return 0;
}