illumigen: main.o analyse.o base.o gen.o stat.o
	$(CC) -o illumigen main.o analyse.o base.o gen.o stat.o

base.o: base.h
	$(CC) -c base.c

analyse.o: analyse.h
	$(CC) -c analyse.c

gen.o: gen.h
	$(CC) -c gen.c

stat.o: stat.h
	$(CC) -c stat.c
