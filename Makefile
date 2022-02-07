CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g
LDFLAGS= -lSDL2


all:  main
all: LDFLAGS += -lm

main: main.o
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@




clean:
	rm -f *~ *.d *.o
	rm -f  main
	
include $(wildcart .d)

