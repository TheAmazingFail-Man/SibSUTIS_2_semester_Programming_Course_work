.PHONY: clean

all: program test

program: bin/tournament-grid

bin/tournament-grid: build/src/main.o build/src/graphics.o build/src/functions.o
	gcc build/src/main.o build/src/graphics.o build/src/functions.o -o bin/tournament-grid

build/src/functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/src/functions.o

build/src/graphics.o: src/graphics.c
	gcc -Wall -Werror -c src/graphics.c -o build/src/graphics.o

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

test: t-g-test

t-g-test: build/test/main.o build/test/t_g_test.o build/src/functions.o build/src/graphics.o
	gcc build/test/main.o build/test/t_g_test.o build/src/functions.o build/src/graphics.o -o bin/t-g-test

build/test/t_g_test.o: test/test.c
	gcc -I thirdparty -I src -Wall -Werror -c test/test.c -o build/test/t_g_test.o

build/test/main.o: test/main.c
	gcc -I thirdparty -I src -Wall -Werror -c test/main.c -o build/test/main.o

clean:
	rm -rf build/src/*.o build/test/*.o bin/tournament-grid bin/t-g-test bin/matchhistory.txt bin/goalshistory.txt