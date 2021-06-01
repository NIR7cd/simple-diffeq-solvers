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

/*
 * This solver uses a predictor-corrector method with the 4th order
 * Adams-Bashforth formula as the predictor and the Adams-Moulton method as the
 * corrector.
 * Inputs:
 *   f        - Pointer to the function for which dy/dt = f(t, y)
 *   t0       - Time of initial condition
 *   y0       - y value of initial condition
 *   h        - Time increment
 *   n        - number of iterations to evaluate
 *   maxerror - The maximum relative error between the predicted and corrected
 *              values; if exceeded the corrector is run again with the average
 *              of the current predicted and corrected values
 *   t        - Output array with the time values of the result
 *   y        - Output array with the y values of the result
 */
void pcabam(float(*f)(float, float), float t0, float y0, float h, long n, float maxerror, float *t, float *y);
