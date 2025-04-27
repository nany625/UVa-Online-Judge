#include <stdio.h>
#include <stdlib.h>

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    int prev;
    while(scanf("%d", &prev) && prev != 0) {
        int curr;
        scanf("%d", &curr);
        int ans = abs(curr - prev);
        prev = curr;
        while(scanf("%d", &curr) && curr != 0) {
            ans = GCD(ans, abs(curr - prev));
            prev = curr;
        }
        printf("%d\n", ans);
    }
	return 0;
}
