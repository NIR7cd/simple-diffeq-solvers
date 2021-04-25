#include <stdlib.h>
#include <stdio.h>
#include "../test_funcs.h"

#define START 0.0
#define END 2.0
#define DISPLAY_STEP 0.1

void euler(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y); 

int main(int argc, char* argv[]) {
    float (*f)(float, float);
    float i, t0, y0, h, t_m, y_m;
    int m, n;
    float *t, *y;

    t0 = START;
    y0 = 1.;
    f = &bd_8_1_5;

    if (argc > 1) {
        h = atof(argv[1]);
    } else {
        h = 0.05;
    }

    n = (int)((END - START + 2*h)/h);
    t = (float*)calloc(n, sizeof(float));
    y = (float*)calloc(n, sizeof(float));

    euler(f, t0, y0, h, n, t, y);

    for (i = START; i <= END; i += DISPLAY_STEP) {
        m = (int)(i/h);
        t_m = t[m];
        y_m = y[m];
        printf("%5d %12.7f %12.7f %12.7f\n", m, t_m, y_m, bd_8_1_5_exact(t_m));
    }
    printf("%5d %12.7f %12.7f %12.7f\n", n-1, t[n-1], y[n-1], bd_8_1_5_exact(t[n-1]));
    
    free(t);
    free(y);
}
