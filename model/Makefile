CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g
LDFLAGS= -lSDL2
DIRLIB=../lib

ifeq ($(TEST),yes)
CFLAGS += -coverage
LDFLAGS += -coverage
endif

all: libmodel.a



libmodel.a: main_model.o carte.o joueur.o IA.o
	ar -rv $(DIRLIB)/$@ $^
	rm -f *~ *.d *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ *.d *.o *.gcda *.gcno *.gcov
	
distclean:
	rm ../lib/libmodel.a

include $(wildcart .d)

