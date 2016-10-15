#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Sagar Patel
//Brilliance

static char myblock[5000];
static char *error = "Not Enough Space";
int initializedArray = 0;

void *malloc1 (int size) {
  if (!intializedArray){
      *(short*) myblock = 4998 +1;
    initializedArray=1;
  }
  if (size < 0){
    printf("Must be greater than 0\n");
    return error;
  }
  
  if(size >4998){
    printf("Memory request larger then size of heap")
    return error
  }
  if(!size)size=2;

  if (size%2) size++;

  unsigned short short_size= (unsigned short) size;
  char *curr = myblock;
  short currBlockSize;

  while(curr < &myblock[4999]){
  if(*(short *) curr) currBlockSize = *(short*)curr &-1;
  else{
    printf("FUBAR\n");
  }

  if (currBlockSize%2 == 0 && currBlockSize >= short_size){  //check if location is free
          *(short*)(curr) = short_size+1;   //+1 to signify allocated space 
          *(short*)(curr+short_size+2) = currBlocksize - short_size-2;
          return curr+2;
        }
        curr+=currBlockSize;
    }
  
  printf("Not Enough Space - 0 signifies unallocated\n");
  return NULL;
}

 



int main(int argc, char *argv[]) {
	char *  p= malloc1(10);
  short v = *(short*)(p-2);
  printf("%u\n", v );

  char *  c= malloc1(20);
  short v1 = *(short*)(c-2);
  printf("%u\n", v1 );

  char *  b= malloc1(12);
  short v2 = *(short*)(b-2);
  printf("%u\n", v2 );

	//printf("pointer\n",p);
	return 0;

}