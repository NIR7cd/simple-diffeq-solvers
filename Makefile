CC = gcc
INCLUDE = -Isrc/first_order
TST_INCLUDE = -Itst

test_solvers : euler.o runge_kutta.o multistep.o test_solvers.o
	$(CC) -o test_solvers euler.o runge_kutta.o multistep.o test_solvers.o -lm

test_euler_var : euler.o test_euler_var.o
	$(CC) -o test_euler_var euler.o test_euler_var.o -lm

euler.o :
	$(CC) -c src/first_order/euler.c

runge_kutta.o :
	$(CC) -c src/first_order/runge_kutta.c

multistep.o :
	$(CC) -c src/first_order/multistep.c

test_solvers.o :
	$(CC) $(INCLUDE) $(TST_INCLUDE) -c tst/first_order/test_solvers.c

test_euler_var.o :
	$(CC) $(INCLUDE) $(TST_INCLUDE) -c tst/first_order/test_euler_var.c

clean :
	rm *.o

.PHONY: clean
