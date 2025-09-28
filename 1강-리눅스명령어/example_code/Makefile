# Makefile

CC = gcc
CFLAGS=
OBJS=File1.o test3.o
LIBS=
all:    add 

add:    $(OBJS)
     $(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)

File1.o:        File1.c
     $(CC) $(CFLAGS) -c File1.c
test3.o:        test3.c
     $(CC) $(CFLAGS) -c test3.c
clean:
     rm -f $(OBJS) add 