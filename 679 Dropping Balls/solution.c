#include <stdio.h>

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int D, I;
        scanf("%d %d", &D, &I);
        int ans = 1;
        while(D-- > 1) {
            if(I & 1) {
                ans <<= 1;
                I = (I + 1) >> 1;
            } else {
                ans = (ans << 1) + 1;
                I >>= 1;
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
