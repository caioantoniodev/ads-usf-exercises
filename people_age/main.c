#include <stdio.h>

int main() {

    int ages[2], old = 0;

    for (int i = 0; i < sizeof(ages) / sizeof(int); i++) {
        printf("Insert age %d: ", i);
        scanf("%d", &ages[i]);

        if (ages[i] > old) old = ages[i];
    }

    for (int i = 0; i < sizeof(ages) / sizeof(int); i++)
        printf("age %d \n", ages[i]);

    printf("\nThe age old is: %d\n", old);
    return 0;
}