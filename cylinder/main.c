#include <stdio.h>

void calcCylinder(int h, int r, float *v, float *a);

int main() {

    float v;
    float a;

    calcCylinder(2, 2, &v, &a);

    printf("%f\n", a);
    printf("%f", v);

    return 0;
}

void calcCylinder(int h, int r, float *v, float *a) {
    *a = 2 * (3.14 * (r * r)) + 2 * (3.14 * r * h);
    *v = 3.14 * (r * r) * h;
}