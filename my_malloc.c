
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static char myblock[5000];
static char *error = "Not Enough Space";
int first =0;

void defrag();
int free1(void * ptrFree);
void * malloc1(unsigned int size);
/*void defrag(){
  
  short meta_size = *(short*)myblock;
  char * tracker = myblock;
  short block1Size =*(short *)tracker~- , block2Size; 
  while(!(*(short *)tracker&1 && !(*(short *)(tracker + *(short *)tracker~1 +2)&1)))
  {  
    *(short *)tracker+=*(short *)(tracker + *(short *)tracker~1+2);
  
    }
    
  }

*/

int free1(void * ptrFree){
  char * blockptr =  &myblock[2];
  char * ptrFree1 = ptrFree;
  if(ptrFree1 < &myblock[2] || ptrFree1>&myblock[4999]) 
    return 0;
  
  char * tracker = myblock;
  while(tracker<=(ptrFree1-2)){
    if(tracker==(ptrFree1-2) && (*(short *)tracker&1)){
    	printf("Free makes it here\n");
      *(short*)tracker = *(short *)tracker;
      //defrag();
      return 1;
    }
   
   short size =*(short *)tracker;
    tracker+=(size - (size%2) +2);
  }
  
  return 0;

}

void * malloc1 (unsigned int size) {
  if (first == 0){
  	printf("makes it here\n");
    *(short*) myblock = 4998;
    first=1;
  }

  if (size < 0){
    printf("Must be greater than 0\n");
    return 0;
  }
  
  if(size >4998){
    printf("Memory request larger then size of heap");
    return 0;
  }
  if(!size)size=2;

  if (size%2) size++;

  unsigned short short_size= (unsigned short) size;
  char *curr = myblock;
  short currBlocksize =0;

  while(curr < &myblock[4999]){
  if(*(short *) curr) currBlocksize = *(short*)curr &-1;
  else{
    printf("FUBAR\n");
  }

  if (currBlocksize%2 == 0 && currBlocksize >= short_size){  //check if location is free
          *(short*)(curr) = short_size+1;   //+1 to signify allocated space 
          *(short*)(curr+short_size+2) = currBlocksize - short_size-2;
          return curr+2;
        }
        curr+=currBlocksize;
    }
  
  printf("Not Enough Space - 0 signifies unallocated\n");
  return NULL;
}

int main(int argc, char *argv[]) {

  char * p= malloc1(10);
  short v = *(short*)(p-2);
  printf("%u\n", v );
  free1(p);
  v = *(short *)(p-2);
  printf("%u\n", v);

  return 0;
}