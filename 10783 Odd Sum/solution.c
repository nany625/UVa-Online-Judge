#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a += (a + 1) % 2;
	 	b -= (b + 1) % 2;
        printf("Case %d: %d\n", i, (-a * a + b * b + 2 * a + 2 * b) / 4);
    }
    return 0;
}
