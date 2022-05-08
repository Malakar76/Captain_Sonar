CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g  -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lAll  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
LDFLAGS_UT=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
MAKE=/usr/bin/make





all:  view_Make model_Make controller_Make Launcher


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
	ar -rcT ./lib/libAll.a ./lib/libmodel.a ./lib/libview.a ./lib/libcontroller.a
	$(CC) $^ $(LDFLAGS) -o $@
	rm -f *~ *.d *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@


clean:
	rm -f  Launcher
	
distclean:
	rm -f ./lib/*.a
	
clall :
	$(MAKE) -C ./ clean
	$(MAKE) -C ./ distclean	

include $(wildcart .d)

