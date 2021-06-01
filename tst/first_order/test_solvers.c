#include <stdlib.h>
#include <stdio.h>
#include <test_funcs.h>
#include <euler.h>
#include <runge_kutta.h>
#include <multistep.h>

#define START 0.0
#define END 2.1
#define DISPLAY_STEP 0.1
#ifndef MAXERR
#define MAXERR 0.001
#endif

int main(int argc, char* argv[]) {
    float (*f)(float, float);
    float i, h, t0, y0, t1m, y1m, y2m, y3m;
    int m, n;
    float *t_euler, *y_euler;
    float *t_impr, *y_impr;
    float *t_rk4, *y_rk4;
    float *t_ab4, *y_ab4;
    float *t_pcabam, *y_pcabam;

    t0 = START;
    y0 = 1.;
    f = &bd_8_1_5;

    if (argc > 1) {
        h = atof(argv[1]);
    } else {
        h = 0.05;
    }

    n = (int)((END - START)/h) + 1;
    t_euler = (float*)calloc(n, sizeof(float));
    y_euler = (float*)calloc(n, sizeof(float));
    t_impr  = (float*)calloc(n, sizeof(float));
    y_impr  = (float*)calloc(n, sizeof(float));
    t_rk4   = (float*)calloc(n, sizeof(float));
    y_rk4   = (float*)calloc(n, sizeof(float));
    t_ab4   = (float*)calloc(n, sizeof(float));
    y_ab4   = (float*)calloc(n, sizeof(float));
    t_pcabam = (float*)calloc(n, sizeof(float));
    y_pcabam = (float*)calloc(n, sizeof(float));

    euler(f, t0, y0, h, n, t_euler, y_euler);
    euler_improved(f, t0, y0, h, n, t_impr, y_impr);
    rk4(f, t0, y0, h, n, t_rk4, y_rk4);
    ab4(f, t0, y0, h, n, t_ab4, y_ab4);
    pcabam(f, t0, y0, h, n, MAXERR, t_pcabam, y_pcabam);

    printf("%s %12s %12s %14s %14s %12s\n", "Iteration", "t", "Euler", "Improved Euler", "Runge-Kutta", "Exact");
    for (i = START; i <= END; i += DISPLAY_STEP) {
        m = (int)(i/h);
        t1m = t_euler[m];
        y1m = y_euler[m];
        y2m = y_impr[m];
        y3m = y_rk4[m];
        printf("%9d %12.7f %12.7f %14.7f %14.7f %12.7f\n", m, t1m, y1m, y2m, y3m, bd_8_1_5_exact(t1m));
    }

    printf("\n");
    printf("%s %12s %15s %15s %12s\n", "Iteration", "t", "Adams-Bashforth", "Pred-Corr AB AM", "Exact");
    for (i = START; i <= END; i += DISPLAY_STEP) {
        m = (int)(i/h);
        t1m = t_ab4[m];
        y1m = y_ab4[m];
        y2m = y_pcabam[m];
        printf("%9d %12.7f %15.7f %15.7f %12.7f\n", m, t1m, y1m, y2m,  bd_8_1_5_exact(t1m));
    }
    
    free(t_euler);
    free(y_euler);
    free(t_impr);
    free(y_impr);
    free(t_rk4);
    free(y_rk4);
    free(t_ab4);
    free(y_ab4);
    free(t_pcabam);
    free(y_pcabam);
}
