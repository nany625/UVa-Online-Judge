#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int n;
        scanf("%*s %*s %d", &n);
        long M[n][n];
        bool isSymmetric = true;
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                scanf("%ld", &M[j][k]);
                if(M[j][k] < 0)
                    isSymmetric = false;
            }
        }
        for(int j = 0; j < (n + 1) / 2 && isSymmetric; ++j) {
            for(int k = 0; k < n && isSymmetric; ++k)
                isSymmetric = M[j][k] == M[n - 1 - j][n - 1 - k];
        }
        printf("Test #%d: %s.\n", i, isSymmetric ? "Symmetric" : "Non-symmetric");
    }
    return 0;
}
