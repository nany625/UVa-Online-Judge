#include <stdio.h>

int GCD(int A, int B, int *X, int *Y) {
    if(A % B == 0) {
        *X = 0;
        *Y = 1;
        return B;
    }
    if(B % A == 0) {
        *X = 1;
        *Y = 0;
        return A;
    }
    if(A >= B) {
        int x, y;
        int value = GCD(A + B * (-A / B), B, &x, &y);
        *X = x;
        *Y = y + x * (-A / B);
        return value;
    }
    int x, y;
    int value = GCD(A, B + A * (-B / A), &x, &y);
    *X = x + y * (-B / A);
    *Y = y;
    return value;
}

int main() {
    int A, B;
    while(scanf("%d %d", &A, &B) == 2) {
        int X, Y, D = GCD(A, B, &X, &Y);
        printf("%d %d %d\n", X, Y, D);
    }
    return 0;
}
