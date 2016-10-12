

char array[5000]



int free(ptrFree){
	
	if(ptrFree > &array[2]) short* meta = ptrFree -2;
	else return -1;
	if(meta%2==1) *meta -=1;
	else return -1;
	degfrag();
	return 1;
}

void defrag(){
	short* meta = array;
	short size;
	while((meta + size) < 5000 ){
		if((*meta%2 == 0) && (*(meta + size)%2==0)) *meta += *(meta + size);
		size = *meta - (*meta%2);
		meta += size;
		}
	}
