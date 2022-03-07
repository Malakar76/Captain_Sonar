CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g 
LDFLAGS= -lSDL2
DIRLIB=../lib



all: libmodel.a



libmodel.a: main_model.o carte.o joueur.o
	ar -rv $(DIRLIB)/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@



clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libmodel.a

include $(wildcart .d)

