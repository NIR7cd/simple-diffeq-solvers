#include <stdlib.h>
#include <stdio.h>

#include <euler.h>
#include <test_funcs.h>

int main(int argc, char* argv[]) {
    long n;
    float *t, *y;
    float(*f)(float, float);
    long i;

    n = (long)(1.0/0.01) + 1;
    t = (float*)calloc(n, sizeof(float));
    y = (float*)calloc(n, sizeof(float));
    f = &bd_8_1_5;

    euler_var_step(f, 0.0, 2.0, 1.0, 0.01, 0.05, &n, &t, &y);
    
    printf("Iteration | Time | Numeric | Exact\n");
    for(i = 0; i < n; ++i) {
        printf("%5ld | %12.7f | %12.7f | %12.7f\n", i, t[i], y[i], bd_8_1_5_exact(t[i]));
    }

    free(t);
    free(y);
}
