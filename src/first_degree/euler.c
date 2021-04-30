void euler(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y) {
    int i;
    *t = t0;
    *y = y0;
    for(i = 1; i < n; ++i) {
        t[i] = t0 + h*i;
        y[i] = y[i-1] + f(t[i-1], y[i-1]) * h;
    }
}

void euler_improved(float(*f)(float t, float y), float t0, float y0, float h, int n, float* t, float* y) {
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
