objects = main.o matrix_mul.o matrix_mul_test.o
options = -O2

mul: main.o matrix_mul.o Makefile
	gcc $(options) -o mul main.o matrix_mul.o

check: matrix_mul_test.o matrix_mul.o
	gcc $(options) -o test matrix_mul_test.o matrix_mul.o
	./test

main.o: main.c matrix_mul.h  Makefile
	gcc $(options) -c main.c

matrix_mul.o: matrix_mul.c matrix_mul.h Makefile
	gcc $(options) -c matrix_mul.c

matrix_mul_test.o: matrix_mul_test.c
	gcc $(options) -c matrix_mul_test.c

clean:
	rm -rf mul test $(objects)
