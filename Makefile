$CC=gcc

test_euler : euler.o test_euler.o
	${CC} -o test_euler euler.o test_euler.o -lm
	./test_euler

euler.o :
	${CC} -c src/first_degree/euler.c

test_euler.o :
	${CC} -c tst/first_degree/test_euler.c

clean:
	rm *.o
