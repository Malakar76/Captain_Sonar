CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g 
LDFLAGS= -lSDL2 -lcmocka
DIRLIB=../lib

all: libmodel.a UTest_modele

EBUG=no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

libmodel.a: main_model.o carte.o joueur.o
	ar -rv $(DIRLIB)/$@ $^

UTest_modele: LDFLAGS+= -lcmocka -coverage
UTest_modele: CFLAGS+= -coverage
UTest_modele: UTest_modele.o joueur.o carte.o main_model.o
	$(CC) $^ $(LDFLAGS)  -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ *.d *.o *.gcda *.gcno

distclean:
	rm ../lib/libmodel.a

include $(wildcart .d)






