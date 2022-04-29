CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g  -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf









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

