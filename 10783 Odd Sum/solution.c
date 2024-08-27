#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a += (a + 1) & 1;
	 	b -= (b + 1) & 1;
        printf("Case %d: %d\n", i, (-a * a + b * b + (a << 1) + (b << 1)) >> 2);
    }
    return 0;
}
