#include <stdio.h>


int recursive(int i);

int main() {
    int i;

    scanf("%d", &i);
    printf("%d\n", recursive(i));

    return 0;
}

int recursive(int i) {
    if (i == 1 || i == 2) return i;

    return 2 * recursive(i - 1) +
        3 * recursive(i - 2);
}
