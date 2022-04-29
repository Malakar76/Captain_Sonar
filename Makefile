CC=gcc
<<<<<<< HEAD
<<<<<<< HEAD
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g  -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
=======
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lcmocka
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f
=======
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lcmocka
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f
MAKE=/usr/bin/make





<<<<<<< HEAD
<<<<<<< HEAD
all:  view_Make model_Make controller_Make Launcher
=======
all:  view_Make model_Make controller_Make test main
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f
=======
all:  view_Make model_Make controller_Make test main
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f


view_Make :
	$(MAKE) -C ./view
	$(MAKE) -C ./view clean

model_Make :
	$(MAKE) -C ./model
	$(MAKE) -C ./model clean

controller_Make :
	$(MAKE) -C ./controller
	$(MAKE) -C ./controller clean

Launcher: main.o
	$(CC) $^ $(LDFLAGS) -o $@
	rm -f *~ *.d *.o

test:
	$(MAKE) -C ./cmocka-build
	$(MAKE) -C ./cmocka-build clean

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@


clean:
	rm -f *~ *.d *.o
	rm -f  Launcher
	
distclean:
	rm -f ./lib/*.a
	
clall :
	$(MAKE) -C ./ clean
	$(MAKE) -C ./ distclean	

include $(wildcart .d)

