#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int a = 0, b = 0, count = 0, term = 1;
        while(n > 0) {
            if(n & 1) {
                if(!(count & 1))
                    a += term;
                else
                    b += term;
                ++count;
            }
            n >>= 1;
            term <<= 1;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
