/*
 * Classic fourth order four-stage Runge-Kutta method, as described in Boyce
 * and Diprima chapter 8.3.
 *
 * Inputs:
 *   f -  Pointer to the function where dy/dt = f(t, y)
 *   t0 - Time of initial condition
 *   y0 - y value of initial condition
 *   h  - Time step
 *   n  - Number of iterations to run
 *   t  - Array that will hold the t result
 *   y  - Array that will hold the y result
 */
void rk4(float(*f)(float, float), float t0, float y0, float h, long n, float *t, float *y);
