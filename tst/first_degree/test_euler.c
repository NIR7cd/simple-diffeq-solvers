#include <stdlib.h>
#include <stdio.h>
#include <test_funcs.h>
#include <euler.h>

#define START 0.0
#define END 2.1
#define DISPLAY_STEP 0.1

int main(int argc, char* argv[]) {
    float (*f)(float, float);
    float i, h, t0, y0, t1m, y1m, y2m;
    int m, n;
    float *t_euler, *y_euler;
    float *t_impr, *y_impr;

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

    euler(f, t0, y0, h, n, t_euler, y_euler);
    euler_improved(f, t0, y0, h, n, t_impr, y_impr);

    printf("%s %12s %12s %14s %12s\n", "Iteration", "t", "Euler", "Improved Euler", "Exact");
    for (i = START; i <= END; i += DISPLAY_STEP) {
        m = (int)(i/h);
        t1m = t_euler[m];
        y1m = y_euler[m];
        y2m = y_impr[m];
        printf("%9d %12.7f %12.7f %14.7f %12.7f\n", m, t1m, y1m, y2m, bd_8_1_5_exact(t1m));
    }
    
    free(t_euler);
    free(y_euler);
    free(t_impr);
    free(y_impr);
}
