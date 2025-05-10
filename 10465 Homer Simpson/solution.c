#include <stdio.h>

int main() {
    int m, n, t;
    while(scanf("%d %d %d", &m, &n, &t) == 3) {
        if(m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
        int a = t / m, beer = t, ans = 0;
        while(beer > 0 && a >= 0) {
            int b = (t - m * a) / n, temp = (t - m * a) % n;
            if(temp < beer) {
                beer = temp;
                ans = a + b;
            } else if(temp == beer) {
                if(beer == 0)
                    break;
                else
                    ans = ans > a + b ? ans : a + b;
            }
            --a;
        }
        if(beer == 0)
            printf("%d\n", ans);
        else
            printf("%d %d\n", ans, beer);
    }
	return 0;
}
