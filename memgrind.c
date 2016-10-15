testA(){
    int i=0,sucess_malloc=0, success_free=0, operations = 0;
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


testB(){
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
            malloc_pointers[count] = malloc1(1);
            count++;
         
        }
        else if(j) {
            malloc_pointers[count] = malloc1(1);
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
            malloc_pointers[count] = malloc1(rand()%6000);
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

     
