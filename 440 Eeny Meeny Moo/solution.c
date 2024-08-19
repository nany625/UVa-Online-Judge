#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int m = 2;
        while(josephus(n - 1, m) != 0)
            ++m;
        printf("%d\n", m);
    }
	return 0;
}
