CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./modele -I./controller
LDFLAGS= -lSDL2 -L./lib -lnomdelib.a -lnomdelibmodele.a



all:  view model controller main
all: LDFLAGS += -lm

view :
	$(MAKE) -C ./view

model :
	$(MAKE) -C ./model

controller :
	$(MAKE) -C ./controller

main: main.o
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@




clean:
	rm -f *~ *.d *.o
	rm -f  main
	
distclean:
	rm ./lib/*.a

include $(wildcart .d)

