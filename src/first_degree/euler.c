#include <math.h>
#include <stddef.h>
#include <stdlib.h>

float euler_step(float(*f)(float, float), float t, float y, float h) {
    return y + f(t, y)*h;
}

float euler_imp_step(float(*f)(float, float), float t, float y, float h) {
    float fn;
    fn = f(t, y);
    return y + ((fn + f(t, y + h*fn))/2.)*h;
}

void euler(float(*f)(float, float), float t0, float y0, float h, int n, float* t, float* y) {
    int i;
    *t = t0;
    *y = y0;
    for(i = 1; i < n; ++i) {
        t[i] = t0 + h*i;
        y[i] = y[i-1] + f(t[i-1], y[i-1]) * h;
    }
}

void euler_improved(float(*f)(float, float), float t0, float y0, float h, int n, float* t, float* y) {
    int i;
    float delta, fn;
    *t = t0;
    *y = y0;
    for(i = 1; i < n; ++i) {
        t[i] = t0 + h*i;
        fn = f(t[i-1], y[i-1]);
        delta = (fn + f(t[i], y[i-1] + h*fn))/2.;
        y[i] = y[i-1] + delta*h;
    }
}

long resize(float** buf, long n) {
    long i;
    long new_n = n + n/2;
    float* newbuf = (float*)calloc(new_n, sizeof(float));
    if (newbuf == NULL) {
        return n;
    }
    for (i = 0; i < n; ++i) {
        newbuf[i] = (*buf)[i];
    }
    free(*buf);
    *buf = newbuf;
    return new_n;
}

void euler_var_step(float(*f)(float, float), float t0, float tf, float y0, float h, float epsilon, long *n, float **t, float **y) {
    float delta;
    long i;
    float ti, yi;
    float ep2 = epsilon * epsilon;
    float newh;
    float y_euler;
    float y_euler_imp;

    ti = t0;
    (*t)[0] = t0;
    (*y)[0] = y0;
    i = 1;

    while (ti < tf) {
        ti = (*t)[i-1];
        yi = (*y)[i-1];
        y_euler = euler_step(f, ti, yi, h);
        y_euler_imp = euler_imp_step(f, ti, yi, h);
        delta = y_euler_imp - y_euler;
        newh = h;
        while (delta*delta > ep2) {
            newh = sqrt(epsilon/delta)*newh;
            y_euler = euler_step(f, ti, yi, newh);
            y_euler_imp = euler_imp_step(f, ti, yi, newh);
            delta = y_euler_imp - y_euler;
        }
        
        if (i >= *n) {
            int n_new;
            n_new = resize(t, *n);
            if (n_new == *n) return;
            n_new = resize(y, *n);
            if (n_new == *n) return;
            *n = n_new;
        }

        (*t)[i] = (*t)[i-1] + newh;
        (*y)[i] = y_euler;
        i += 1;
    }
    *n = i;
}
