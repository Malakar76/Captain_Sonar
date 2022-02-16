CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g 
LDFLAGS= -lSDL2
DIRLIB=../lib



all: libmodel.a main_model



libmodel.a: main_model.o carte.o sous_marin.o joueur.o
	ar -rv $(DIRLIB)/$@ $^

main_model:main_model.o carte.o sous_marin.o joueur.o test.o
	$(CC) $(CFLAGS) -c $<  -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@




clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libmodel.a

include $(wildcart .d)

