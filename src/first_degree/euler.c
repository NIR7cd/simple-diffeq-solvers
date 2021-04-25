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
void euler(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y) {
    int i;
    *t = t0;
    *y = y0;
    for(i = 1; i < n; ++i) {
        t[i] = t0 + h*i;
        y[i] = y[i-1] + f(t[i-1], y[i-1]) * h;
    }
}
