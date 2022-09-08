#include <stdio.h>

void cylinderOperation(int radius, float *bulk, float *area);

int main() {

    float bulk, area;
    int radius;

    printf("Insert radius: ");
    scanf("%d", &radius);

    cylinderOperation(radius, &bulk, &area);

    printf("Area: %.2f\n", area);
    printf("Bulk: %.2f", bulk);

    return 0;
}

void cylinderOperation(int radius, float *bulk, float *area) {
    *area = 4 * 3.14 * radius * radius;
    *bulk = 4 * 3.14 * radius * radius * radius / 3;
}