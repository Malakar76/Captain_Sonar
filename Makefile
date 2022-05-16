CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g  -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lAll  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
MAKE=/usr/bin/make

all:  view_Make model_Make controller_Make Launcher
MEM=no
TEST=no
ifeq ($(TEST),yes)
all +:Test_Make
CFLAGS += -coverage
LDFLAGS += -coverage
endif


ifeq ($(MEM),yes)
all +:Mem_Leak
endif


view_Make :
	$(MAKE) -C ./view


model_Make :
	$(MAKE) -C ./model


controller_Make :
	$(MAKE) -C ./controller


Test_Make :
	$(MAKE) -C ./Test_Unitaires

Mem_Leak : Launcher
	valgrind --leak-check=yes ./Launcher


Launcher : main.o
	ar -rcT ./lib/libAll.a ./lib/libmodel.a ./lib/libview.a ./lib/libcontroller.a
	$(CC) $^ $(LDFLAGS) -o $@
	rm -f *~ *.d *.o *.gcno

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@


clean :
	rm -f  Launcher
	rm -f *~ *.d *.o *.gcno
libClean :
	rm -f ./lib/*.a

testClean:
	$(MAKE) -C ./Test_Unitaires clean

allClean :
	$(MAKE) -C ./ clean
	$(MAKE) -C ./controller clean
	$(MAKE) -C ./model clean
	$(MAKE) -C ./view clean
	$(MAKE) -C ./ libClean

include $(wildcart .d)

