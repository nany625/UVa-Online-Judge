#include <stdio.h>

int result[2][2], temp[2][2], mod[] = {0, 10, 100, 1000, 10000};

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

int powerMatrix(int matrix[2][2], int n, int mod) {
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
        int n, m;
        scanf("%d %d %d %d", &result[0][1], &result[0][0], &n, &m);
        if(n == 0)
            printf("%d\n", result[0][1] % mod[m]);
        else {
            int matrix[2][2] = {{1, 1}, {1, 0}};
            printf("%d\n", powerMatrix(matrix, n - 1, mod[m]));
        }
    }
    return 0;
}
