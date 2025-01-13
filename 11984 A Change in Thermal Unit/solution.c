#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int C, d;
        scanf("%d %d", &C, &d);
        printf("Case %d: %.2lf\n", i, (C * 1.8 + d) * 5 / 9);
    }
	return 0;
}
