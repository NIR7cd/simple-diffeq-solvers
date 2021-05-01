CC = gcc
INCLUDE = -Isrc/first_degree
TST_INCLUDE = -Itst

test_euler : euler.o test_euler.o
	$(CC) -o test_euler euler.o test_euler.o -lm
	./test_euler

test_euler_var : euler.o test_euler_var.o
	$(CC) -o test_euler_var euler.o test_euler_var.o -lm

euler.o :
	$(CC) -c src/first_degree/euler.c

test_euler.o :
	$(CC) $(INCLUDE) $(TST_INCLUDE) -c tst/first_degree/test_euler.c

test_euler_var.o :
	$(CC) $(INCLUDE) $(TST_INCLUDE) -c tst/first_degree/test_euler_var.c

clean:
	rm *.o

.PHONY: clean 
