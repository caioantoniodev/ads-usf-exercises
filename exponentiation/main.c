#include <stdio.h>

int exponentialRecursive(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * exponentialRecursive(base, exponent - 1);
}


int main() {

    int base, exponent;

    printf("Base: ");
    scanf("%d", &base);

    printf("Exponent: ");
    scanf("%d", &exponent);


    printf("%d ^ %d = %d\n", base, exponent, exponentialRecursive(base, exponent));

    return 0;
}