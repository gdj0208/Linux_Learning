
CC = gcc
CFLAGS=
OBJS=mainCode.o subnum.o
LIBS=
all:    subnum

subnum :   $(OBJS)
	$(CC) $(CFLAGS) -o subnum $(OBJS) $(LIBS)

mainCode.o: 	  mainCode.c
	$(CC) $(FLAGS) -c mainCode.c

subnum.o : 	  subnum.c
	$(CC) $(FLAGS) -c subnum.c
clean :
	rm -f $(OBJS) subnum
