#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int L, W, H;
        scanf("%d %d %d", &L, &W, &H);
        printf("Case %d: %s\n", i, L <= 20 && W <= 20 && H <= 20 ? "good" : "bad");
    }
	return 0;
}
