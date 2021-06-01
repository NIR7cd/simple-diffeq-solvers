float runge_kutta_step(float(*f)(float, float), float t, float y, float h) {
    float k1, k2, k3, k4;
    k1 = f(t, y);
    k2 = f(t + 0.5*h, y + 0.5*h*k1);
    k3 = f(t + 0.5*h, y + 0.5*h*k2);
    k4 = f(t + h, y + h*k3);
    return y + h*(k1 + k2 + k3 + k4)/6.;
}

float adams_bashforth_step(float(*f)(float, float), long i, float h, const float *t, const float *y) {
    float f1, f2, f3, f4;
    f1 = f(t[i-1], y[i-1]);
    f2 = f(t[i-2], y[i-2]);
    f3 = f(t[i-3], y[i-3]);
    f4 = f(t[i-4], y[i-4]);
    return y[i-1] + h*(55.*f1 - 59.*f2 + 37.*f3 - 9.*f4)/24.;
}

float adams_moulton_step(float(*f)(float, float), long i, float h, const float *t, const float *y, float yi) {
    float f0, f1, f2, f3;
    f0 = f(t[i], yi);
    f1 = f(t[i-1], y[i-1]);
    f2 = f(t[i-2], y[i-2]);
    f3 = f(t[i-3], y[i-3]);
    return y[i-1] + h*(9.*f0 + 19.*f1 - 5.*f2 + f3)/24.;
}

void ab4(float(*f)(float, float), float t0, float y0, float h, long n, float *t, float *y) {
    long i;
    float f1, f2, f3, f4;

    t[0] = t0;
    y[0] = y0;

    for (i = 1; i < 3 && i < n; ++i) {
        t[i] = t0 + h*i;
        y[i] = runge_kutta_step(f, t[i-1], y[i-1], h);
    }

    for (i = 3; i < n; ++i) {
        t[i] = t0 + h*i;
        f1 = f(t[i-1], y[i-1]);
        f2 = f(t[i-2], y[i-2]);
        f3 = f(t[i-3], y[i-3]);
        f4 = f(t[i-4], y[i-4]);
        y[i] = y[i-1] + h*(55.*f1 - 59.*f2 + 37.*f3 - 9.*f4)/24.;
    }
}

void pcabam(float(*f)(float, float), float t0, float y0, float h, long n, float maxerror, float *t, float *y) {
    long i;
    float f1, f2, f3, f4;
    float predicted, corrected;
    float error;
    float me2 = maxerror*maxerror;

    t[0] = t0;
    y[0] = y0;

    for (i = 1; i < 4 && i < n; ++i) {
        t[i] = t0 + h*i;
        y[i] = runge_kutta_step(f, t[i-1], y[i-1], h);
    }

    for (i = 4; i < n; ++i) {
        t[i] = t0 + h*i;
        predicted = adams_bashforth_step(f, i, h, t, y);
        corrected = adams_moulton_step(f, i, h, t, y, predicted);
        error = (corrected-predicted)/corrected;
        while (error*error > me2) {
            predicted = corrected;
            corrected = adams_moulton_step(f, i, h, t, y, predicted);
            error = (corrected - predicted)/corrected;
        }
        y[i] = corrected;
    }
}

