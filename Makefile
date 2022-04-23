CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -I./view -I./model -I./controller
LDFLAGS=  -L./lib -lview -lmodel -lcontroller  -lSDL2 -lcmocka
MAKE=/usr/bin/make





all:  view_Make model_Make controller_Make test main


view_Make :
	$(MAKE) -C ./view
	$(MAKE) -C ./view clean

model_Make :
	$(MAKE) -C ./model
	$(MAKE) -C ./model clean

controller_Make :
	$(MAKE) -C ./controller
	$(MAKE) -C ./controller clean

main: main.o
	$(CC) $^ $(LDFLAGS) -o $@
	rm -f *~ *.d *.o

test:
	$(MAKE) -C ./cmocka-build
	$(MAKE) -C ./cmocka-build clean

%.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@


clean:
	rm -f *~ *.d *.o
	rm -f  main
	
distclean:
	rm ./lib/*.a
	
clall :
	$(MAKE) -C ./ clean
	$(MAKE) -C ./ distclean	

include $(wildcart .d)

