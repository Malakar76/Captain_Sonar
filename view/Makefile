CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g
LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
DIRLIB=../lib



all: libview.a



libview.a: main_view.o Battlefield.o Menu.o rules_and_credit.o Music.o
	ar -rv $(DIRLIB)/$@ $^
	rm -f *~ *.d *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libview.a

include $(wildcart .d)

