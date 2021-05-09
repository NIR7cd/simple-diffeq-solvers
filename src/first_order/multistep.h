/*
 * Solve a differential equation using the 4th order Adams-Bashforth formula,
 * as described in Boyce and Diprima Chapter 8.4
 *
 * Inputs:
 *   f  - Pointer to the function for which dy/dt = f(t, y)
 *   t0 - Time of initial condition
 *   y0 - y value of initial condition
 *   h  - Time increment
 *   n  - number of iterations to evaluate
 *   t  - Output array with the time values of the result
 *   y  - Output array with the y values of the result
 * 
 * Both t and y should be allocated with at least n floats
 */
void ab4(float(*f)(float, float), float t0, float y0, float h, long n, float *t, float *y);
