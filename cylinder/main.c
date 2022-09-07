#include <stdio.h>

void cylinderOperation(int height, int radius, float *bulk, float *area);

int main() {

    float bulk, area;
    int height, radius;

    printf("Insert height: ");
    scanf("%d", &height);

    printf("Insert radius: ");
    scanf("%d", &radius);

    cylinderOperation(height, radius, &bulk, &area);

    printf("Area: %.2f\n", area);
    printf("Bulk: %.2f", bulk);

    return 0;
}

void cylinderOperation(int height, int radius, float *bulk, float *area) {
    *area = 2 * (3.14 * (radius * radius)) + 2 * (3.14 * radius * height);
    *bulk = 3.14 * (radius * radius) * height;
}