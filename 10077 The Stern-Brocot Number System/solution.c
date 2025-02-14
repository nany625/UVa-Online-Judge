#include <stdio.h>

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) && (m != 1 || n != 1)) {
        int add[][2] = {{0, 1}, {1, 0}}, a = 1, b = 1;
        while(a != m || b != n) {
            if(a * n > b * m) {
                putchar('L');
                a = add[0][0] + (add[0][1] = a);
                b = add[1][0] + (add[1][1] = b);
            } else {
                putchar('R');
                a = (add[0][0] = a) + add[0][1];
                b = (add[1][0] = b) + add[1][1];
            }
        }
        putchar('\n');
    }
    return 0;
}
