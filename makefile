

#Variable definition
CC  = gcc 
CCFLAGS = -Wall 

#rules definition
mymalloc : mymalloc.c mymalloc.h
	$(CC) $(CCFLAGS) -o mymalloc mymalloc.c

#This rule cleans up executable file


all: mymalloc memgrind

main: mymalloc.c
	gcc -g mymalloc.c mymalloc.h memgrindc.c -o mymalloc

clean: 
	rm -f mymalloc 