#include <stdio.h>
#define MAXN 100000

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int n;
        scanf("%d", &n);
        int snowflake[MAXN + 1] = {}, ans = 0, top = 1;
        for(int i = 1; i <= n; ++i) {
            int num;
            scanf("%d", &num);
            if(top <= snowflake[num]) {
                ans = ans > i - top ? ans : i - top;
                top = snowflake[num] + 1;
            }
            snowflake[num] = i;
        }
        printf("%d\n", ans > n + 1 - top ? ans : n + 1 - top);
    }
    return 0;
}
