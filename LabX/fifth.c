#include <stdio.h>


int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x = 10, y = 20, z = 30;
    int result = add(&x, &y, &z);
    printf("The sum of %d, %d, and %d is %d\n", x, y, z, result);
    return 0;
}
