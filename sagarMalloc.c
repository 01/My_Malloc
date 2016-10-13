#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Sagar Patel
//Brilliance

static char myblock[50];
static char *error = "Not Enough Space";
int first = 1;

char *malloc1 (int size) {

  if (size == 0){
    printf("Must be greater than 0\n");
    return error;
  }

  if (size%2 != 0){
    printf("Only Even Sizes\n");
    exit(0);
  }

	char* p;
  p=myblock;
  
  unsigned short short_size= size;

  if (first == 1){
    *(short*)(p) = short_size;
    first=0;
    return p+2;
  }

  int i =0; char *curr = myblock;
  for (i=0;i<=50;i++){
    short val = *(short*)(curr+i);
    if (val != 0){ //check if location has value
      if (val%2 != 0){  //check if location is free
        if (val >= size){ //check if block is large enough
          *(short*)(curr+i) = short_size; //+1 to signify allocated space 
          return curr+i+2;
        }
      }
      else{
        i=i+val+2;
          } 
    }
    else{ //if location does not have value, try to add here
      char *temp_ptr = curr+i; 
      int j=0; int run =0;
      for (j=0;j<val;j++){ //check if space is big enough for allocation
        short temp_val = *(short*)(temp_ptr+j);
        if (val != 0){  //if any space has value then move pointer to new location
          i=i+temp_val;
          run =1;
          break;
      }
    } //space available for malloc 
    if (run == 0){
      *(short*)(curr+i) = short_size;
      return curr+i+2;
      }
    }
  }

  printf("Not Enough Space - 0 signifies unallocated\n");
  return error;
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