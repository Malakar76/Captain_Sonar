CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2





all:  view model controller main
all : LDFLAGS +=

view :
	 make -C ./view

model :
	make -C ./model

controller :
	make -C ./controller

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

