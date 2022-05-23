CC=gcc
CFLAGS=-Wall -Wextra -pedantic-errors -MMD -g -coverage -I../model
LDFLAGS=  -L../lib -lmodel -lSDL2 -lcmocka -coverage -Wl,--wrap=rand

all: Run_Test UTest_modele

Run_Test : UTest_modele
	./UTest_modele
	lcov --capture --directory ./ --output-file ./Coverage_test_info/coverage_test.info
	genhtml ./Coverage_test_info/coverage_test.info --output-directory ./Coverage_test_info
	lcov --capture --directory ../model/ --output-file ./Coverage_model_info/coverage_model.info
	genhtml ./Coverage_model_info/coverage_model.info --output-directory ./Coverage_model_info
	$(MAKE) -C ../model/ clean
	rm -f *~ *.d *.o *.gcda *.gcno

UTest_modele: UTest_modele.o
	$(CC) $^ $(LDFLAGS)  -o $@
	rm -f *.d *.o


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ *.d *.o *.gcda *.gcno
	rm -f UTest_modele

include $(wildcart .d)






