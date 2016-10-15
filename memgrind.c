#include "mymalloc.h"

void testA();
void testB();
void testC();
void testD();
void testE();
void testF();

void testA(){
    int i=0, sucess_malloc = 0, success_free = 0;
    void * malloc_ptrs [3000];
    for(i=0; i<3000; i++){
        
        malloc_ptrs[i] = malloc(1);
        if(malloc_ptrs[i]) success_malloc++;   
        operations++;
    }
    for(i=0;i<3000; i++){
        if(malloc_ptrs[i]) success_free++;
        free(malloc_ptrs[i]);
        operations++;
    }
        printf("Total operations: %d \n", operations);       
        printf("Successful Mallocs: %d\n", success_malloc)
        printf("Successful Frees: %d\n", success_free);
        printf("Unfreed Mallocs: %d\n", (success_malloc-success_free));
}


void testB(){
    int i = 0;
    for(; i<3000; i++){
       free(malloc(1))
    }
}

void testC(){
    int count = 0, random, operations = 0;
    void * current_malloc;
    void* malloc_pointers [3000];
    int i, j;


   srand ( time(NULL) );
    for (i = 6000; i > 0; i--)
    {   
        j = rand()%2;
        printf("J: %d\n", j);
         if(count == i){
            free1(malloc_pointers[count]);
            count--;
          
        }
         else if(count==0){
            malloc_pointers[count] = mymalloc(1);
            count++;
         
        }
        else if(j) {
            malloc_pointers[count] = mymalloc(1);
            count++;
         
        }
        else{
            free1(malloc_pointers[count]);
            count--;
            
        }

        printf("Count %d: %d\n", i, count);
}
printf("Final Count: %u\n", count);
}


void testD(){
    int count = 0;
    void* malloc_pointers [3000];
    int i, j;
    srand ( time(NULL) );
    for (i = 6000; i > 0; i--)
    {    j =rand()%2;
         printf("J : %d\n", j);
         if(count==0 || (j && count!=i)){
            malloc_pointers[count] = mymalloc(rand()%6000);
            if(malloc_pointers[count])printf("Size of malloc: %u\n\n", *(unsigned short *)(malloc_pointers[count]-2));
            count++;
        }
        else{
            free1(malloc_pointers[count]);
            printf("Free\n");
            count--;
        }
        printf("Count %d: %d\n", i, count);
}
printf("Final Count %d\n", count);
}


/*void testE(){
    meta * track = myblock;
    while(track <= &myblock[4998]){
        *track = rand()%10000;
        track++;

}*/
     

int main(int argc, char *argv[]) {
  
    struct timeval begin, end ;   int i = 0;
   float time [100];
   for(; i<100; i++){
        gettimeofday(&begin, NULL);
        testA();
        testB();
        testC();
        testD();
        gettimeofday(&end, NULL);
        time[i]= (end.tv_sec * 1000000 + end.tv_usec)
         - (begin.tv_sec * 1000000 + begin.tv_usec);
        printf("\n%ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)
         - (begin.tv_sec * 1000000 + begin.tv_usec)));

   }
  
  return 0;
}