CC=gcc
CFLAGS=-std=c17
DEPENDENCIES=mmult.h memfree.h memalloc.h print.h
OBJECT_DEPENDENCIES=main.o mmult.o memfree.o memalloc.o print.o
LIBRARIES=-lm
.DEFAULT_GOAL=main

%.o: %.c $(DEPENDENCIES)
	$(CC) $(CFLAGS) -c -o $@ $<

main:$(OBJECT_DEPENDENCIES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)