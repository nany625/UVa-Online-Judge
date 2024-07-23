#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int n;
        scanf("%*s %*s %d", &n);
        int size = n * n;
        long M[n * n];
        bool isSymmetric = true;
        for(int j = 0; j < size; ++j) {
            scanf("%ld", &M[j]);
            if(M[j] < 0)
                isSymmetric = false;
        }
        for(int j = 0; j < size / 2 && isSymmetric; ++j)
            isSymmetric = M[j] == M[size - 1 - j];
        printf("Test #%d: %symmetric.\n", i, isSymmetric ? "S" : "Non-s");
    }
    return 0;
}
