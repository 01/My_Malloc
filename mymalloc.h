#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define extern char *error = "Not Enough Space";
#define malloc(x) mymalloc(x, __FILE__, __LINE__) 
#define free(x) myfree(x , __FILE__, __LINE__ )

#define ERROR_NOT_ALLOCATED printf("ERROR: Attempted to free an unallocated block. Line: %d File: %s\n", __LINE__, __FILE__);
#define ERROR_NOT_ENOUGH_SPACE printf("ERROR: Attempting to malloc too much space. Line: %d File: %s\n", __LINE__, __FILE__);

typedef unsigned short meta;
extern char myblock[5000];

void defrag();
void testA();
void * mymalloc(unsigned short x, char * file, int line);
void myfree(void * x, char * file, int line);

#endif