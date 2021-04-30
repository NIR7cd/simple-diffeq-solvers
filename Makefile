CC = gcc
INCLUDE = -Isrc/first_degree
TST_INCLUDE = -Itst

test_euler : euler.o test_euler.o
	$(CC) -o test_euler euler.o test_euler.o -lm
	./test_euler

euler.o :
	$(CC) -c src/first_degree/euler.c

test_euler.o :
	$(CC) $(INCLUDE) $(TST_INCLUDE) -c tst/first_degree/test_euler.c

clean:
	rm *.o
