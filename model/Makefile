CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g 
LDFLAGS= -lSDL2
DIRLIB=../lib



all: libmodel.a



libmodel.a: main_model.o carte.o joueur.o
	ar -rv $(DIRLIB)/$@ $^

%.o: %.c
<<<<<<< HEAD
	$(CC) $(CFLAGS) -c $< -o $@
=======
	$(CC) $(CFLAGS) -c $<  -o $@


<<<<<<< HEAD
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f
=======
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f

clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libmodel.a

include $(wildcart .d)

