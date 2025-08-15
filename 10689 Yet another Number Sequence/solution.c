#include <stdio.h>

int temp[2][2], mod[] = {0, 10, 100, 1000, 10000};

void multiplyMatrix(int a[2][2], int b[2][2], int mod) {
    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    temp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    a[0][0] = temp[0][0];
    a[0][1] = temp[0][1];
    a[1][0] = temp[1][0];
    a[1][1] = temp[1][1];
}

int powerMatrix(int a, int b, int matrix[2][2], int n, int mod) {
    int result[2][2] = {};
    result[0][0] = b;
    result[0][1] = a;
    while(n > 0) {
        if(n & 1)
            multiplyMatrix(result, matrix, mod);
        multiplyMatrix(matrix, matrix, mod);
        n >>= 1;
    }
    return result[0][0];
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int a, b, n, m;
        scanf("%d %d %d %d", &a, &b, &n, &m);
        if(n == 0)
            printf("%d\n", a % mod[m]);
        else {
            int matrix[2][2] = {{1, 1}, {1, 0}};
            printf("%d\n", powerMatrix(a, b, matrix, n - 1, mod[m]));
        }
    }
    return 0;
}
