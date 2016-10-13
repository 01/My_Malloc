testA(){
    int i=00,sucess_malloc=0, success_free=0, operations = 0;
    for(i=0; i<3000; i++){
        if(malloc(1)) success_malloc++;   
        operations++;
    }
    char * freeTracker= array+2;   
        
        do{
        if(free(freeTracker))success_free++
        freeTracker += *((short*)(freeTracker-2))-(*((short*)(freeTracker-2))%2)+2);
        } while(freeTracker+ *((short*)(freeTracker-2))-(*((short*)(freeTracker-2))%2)<4999)
       
        printf("Total operations: %d \n", operations);       
        printf("Successful Mallocs: %d\n", success_malloc)
        printf("Successful Frees: %d\n", success_free);
        printf("Unfreed Mallocs: %d\n", (success_malloc-success_free));
}
}

testB{
    void * test_B = malloc(1);
    int i = 0;
    for(; i<3000; i++){
        free(test_B);
    }
}

testC{
    int count = 0, random, malloc_index=0, free_index=0;
    void * current_malloc;
    char*[] malloc_pointers = new char*[3000*sizeof(char*)]
    while(count < 6000){
    random = rand() % 6000-count;
    if(random%2){
        current_malloc = malloc(1);
        if(current_malloc)malloc_pointers[index]= current_malloc;
        index++;
    }
    else