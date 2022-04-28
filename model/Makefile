CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g 
LDFLAGS= -lSDL2 -lcmocka
DIRLIB=../lib


DEBUG=no
ifeq ($(DEBUG),yes)
CFLAGS+=-g
endif

all: libmodel.a

MYTEST=no
ifeq ($(MYTEST),yes)
all: UTest_modele
endif

libmodel.a: main_model.o carte.o joueur.o
	ar -rv $(DIRLIB)/$@ $^

UTest_modele: LDFLAGS+= -lcmocka -coverage
UTest_modele: CFLAGS+= -coverage
UTest_modele: UTest_modele.o joueur_gcov.o
	$(CC) $^ $(LDFLAGS)  -o $@

UTest_modele.o: UTest_modele.c
	$(CC) -c $(LDFLAGS) $< -o $@

joueur_gcov.o: joueur.c
	$(CC) -c $(LDFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

include $(wildcart .d)

clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libmodel.a


