

#include "mymalloc.h"

int arrayIntialized =0;

typedef meta meta;

/*
 * The Defrag method is a method called each time a pointer is successfully freed. its purpose is to combine neighboring free memory blocks into a single memory
 * blocks. The method checks a memory block to see if it is free or allocated. If it is free, a loop begins combining the consecective free memory blocks until 
 * neighbor memory block is not a free memory block This defrag method takes in no inputs, and assumess access to the memory it is going to defrag.
 * Though be more efficient to end the method once two free neighboring memory blocks are combined and posssibly a 3rd, since in this implementation 
 * there is no scenario where more then 3 consequtive memory blocks are all free, the method continues through the whole memory so that this method can 
 * defrag an array
*/

void defrag(){
	
	char * tracker = myblock;
  	meta meta_size1 = * (meta *) tracker;
  	meta block_size1 = (meta_size1 - (meta_size1%2));
  	meta meta_size2 = * (meta *) (tracker +2 + block_size1);
  	meta block_size2 = (meta_size2 - (meta_size2%2));
  
  	while((tracker + 2 + block_size1)< &myblock[4998]){											// Conditional loop to cycle through all memory blocks in the main memory
  		meta_size1 = * (meta *) tracker;
  		block_size1 = (meta_size1 - (meta_size1%2));
  		meta_size2 = * (meta *) (tracker +2 + block_size1);
  		block_size2 = (meta_size2 - (meta_size2%2));
  		
  		while(!(meta_size1%2) && !(meta_size2) && (tracker + 2 + block_size1)< &myblock[4998]){ // Conditional loop to continue combining neighboring free memory blocks until 
    		*(meta *)tracker += (block_size2 + 2);												// the free memory block does nto have a free neighbor 
    		meta_size1 = * (meta *) tracker;
  			block_size1 = (meta_size1 - (meta_size1%2));
  			meta_size2 = * (meta *) (tracker +2 + block_size1);
  			block_size2 = (meta_size2 - (meta_size2%2));
    	}

 		tracker += (2 + *(meta *)tracker + block_size1);
    }
}

/*
 * myFree is a custom replacement method to replace the C standard Library's Free method for freeing dynamocially allocated memory
 */

void myfree(void * ptrFree){
  
	char * ptrFree1 = (char *) ptrFree;
  
  	if(ptrFree1 < &myblock[2] || ptrFree1>&myblock[4999]) return;
  
  	char * tracker = myblock;
  	while(tracker<=(ptrFree1-2)){
   		if(tracker==(ptrFree1-2) && !(*(meta *)tracker & ~1)){
    		*(meta*)tracker = *(meta *)tracker-1;
      		defrag();
      		return;
    	}

    	tracker+=(*(meta *)tracker-= (*(meta *)tracker %2));
  	}
  
  return;

}

void * mymalloc (unsigned int size) {;
	if (!arrayInitialized){
  		*(meta *) myblock = (meta) 4998;
    	arrayInitialized = 1;
    }
  
  	if (size < 0){
    	printf("Must be greater than 0\n");
    	return 0;
  	}
  
  	if(size >4998){
    	printf("Memory request larger then size of heap\n");
    	return 0;
  	}
  
  	if(!size) size = 2;

  	if (size%2) size++;

  	meta short_size= size;
  	char *track= myblock;
  	meta currBlocksize;

  	while(track< &myblock[4999]){
 	
 		currBlocksize = (*(meta*)track- (*(meta *)curr%2));
 
 		if (!(*(meta *)curr%2) && currBlocksize >= short_size){  //check if location is free

        	*(meta *)track= short_size+1;   //+1 to signify allocated space 
        	*(meta *)(curr+short_size+2) = currBlocksize - short_size-2;
        	return (void *) curr+2;
        }
        
        curr+=currBlocksize +2;
    }
  
  printf("Not Enough Space - 0 signifies unallocated\n");
  return NULL;
}



int main(int argc, char *argv[]) {


  return 0;
}