void rk4(float(*f)(float, float), float t0, float y0, float h, long n, float *t, float *y) {
    long i;
    float k1, k2, k3, k4;
    float ti, yi;
    t[0] = t0;
    y[0] = y0;

    for(i = 0; i < n - 1; ++i) {
        ti = t[i];
        yi = y[i];
        k1 = f(ti, yi);
        k2 = f(ti + 0.5*h, yi + 0.5*h*k1);
        k3 = f(ti + 0.5*h, yi + 0.5*h*k2);
        k4 = f(ti + h, yi + h*k3);
        y[i+1] = yi + h*(k1 + 2.*k2 + 2.*k3 + k4)/6.;
        t[i+1] = t0 + h*(i+1);
    }
}
