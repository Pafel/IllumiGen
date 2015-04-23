illumigen: src/main.o src/analyse.o src/base.o src/gen.o src/stat.o
	$(CC) -o illumigen src/main.o src/analyse.o src/base.o src/gen.o src/stat.o

base.o: base.h
	$(CC) -c src/base.c

analyse.o: analyse.h
	$(CC) -c src/analyse.c

gen.o: gen.h
	$(CC) -c src/gen.c

stat.o: stat.h
	$(CC) -c src/stat.c
