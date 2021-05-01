#ifndef H_EULER
#define H_EULER

/*
 * Euler solver
 *
 * Solves a 1st order differential equation using the basic Euler method.
 *
 * Inputs:
 *   f  - pointer to the function f such that dy/dt = f(t,y)
 *   t0 - starting time
 *   y0 - initial value of y
 *   h  - size of time step
 *   n  - number of time steps to execute
 *   t  - array that will store the time values
 *   y  - array that will store the y values
 */
void euler(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y);

/*
 * Improved Euler solver
 *
 * Same interface as the Euler solver, but uses the improved formula from Boyce
 * and Diprima Chapter 8.2
 */
void euler_improved(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y);

/*
 * Euler solver with variable step size. This function uses the Euler method
 * and estimates error by comparing to the improved Euler method. Since the
 * step size can change, there number of steps is not known before the solution
 * is found. For this function a time range is specified, and the output arrays
 * are automatically resized as needed in the course of solving the problem.
 * Once the calculation is complete, n is set to point to the exact number of
 * time steps used
 *
 * Inputs:
 *   f       - pointer to the function f such that dy/dt = f(t, y)
 *   t0      - starting time
 *   tf      - final time
 *   y0      - value of y at t0
 *   h       - maximum time step size
 *   epsilon - maximum error between the more and less accurate estimate
 *   n       - pointer which gets set to the number of steps used
 *   t       - pointer to an array which holds the time of each step
 *   y       - pointer to the array of y values
 */
void euler_var_step(float(*f)(float, float), float t0, float tf, float y0, float h, float epsilon, long *n, float **t, float **y);

#endif
