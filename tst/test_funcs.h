#include <math.h>

/*
 * Equation 5 from Chapter 8.1 of Boyce and Diprima Elementary Differential
 * Equations and Boundary Value Problems seventh edition
 *
 * y' = 1 - t + 4y
 *
 */
float bd_8_1_5(float t, float y) {
    return 1.0 - t + 4.0*y;
}

float bd_8_1_5_exact(float t) {
    return 0.25*t - (3./16.) + (19./16.)*exp(4.*t);
}
