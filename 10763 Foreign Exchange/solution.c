#include <stdio.h>
#define MAXN 500000

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int exchange[MAXN + 1] = {}, count = 0;
        while(n--) {
            int a, b;
            scanf("%d %d", &a, &b);
            ++exchange[a];
            --exchange[b];
            if(exchange[a] == 1)
                ++count;
            if(exchange[b] == -1)
                ++count;
            if(exchange[a] == 0)
                --count;
            if(exchange[b] == 0)
                --count;
        }
        puts(count == 0 ? "YES" : "NO");
    }
	return 0;
}
