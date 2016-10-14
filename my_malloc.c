

char array[5000]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Sagar Patel
//Brilliance

static char myblock[5000];
static char *error = "Not Enough Space";
int first = 1;

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
int free(ptrFree){
	if(ptrFree < &array[2] || ptrFree>&array[4999]) return (-1);
	char * tracker = myblock;
	while(tracker<=(ptrFree-2)){
		if(tracker==(ptrFree-2) && (*(short *)tracker&1)){
			*(short*)tracker--;
			defrag();
			return 1;
		}
		
		tracker+=*(short*)tracker~1 + 2;
	}
	
	return (-1);

}


void defrag(){
	short meta_size = *(short*)array;
	char * tracker = array;
	short block1Size, block2Size; 
	while(!(*(short *)tracker&1 && !(*(short *)(tracker + *(short *)tracker~1 +2)&1)({
		
		*(short *)tracker+=*(short *)(tracker + *(short *)tracker~1);
		*(short *)(tracker + )
		size = *meta - (*meta%2);
		meta += size;
		}
	}

