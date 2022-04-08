CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./model
LDFLAGS=  -L./lib -lview -lmodel -lSDL2
DIRLIB=../lib



all: libcontroller.a



libcontroller.a: main_controller.o control_battlefield.o
	ar -rv $(DIRLIB)/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@




clean:
	rm -f *~ *.d *.o
	
distclean:
	rm ../lib/libcontroller.a

include $(wildcart .d)

