#include <stdio.h>
#define MAXN 5999999

short collatz[MAXN + 1];

void init(int n) {
    long temp = n;
    do {
        if(temp < n) {
            collatz[n] += collatz[temp];
            return;
        }
        temp = temp & 1 ? 3 * temp + 1 : temp >> 1;
        ++collatz[n];
    } while(temp != 1);
}

int main() {
	for(int n = 1; n <= MAXN; ++n)
	    init(n);
    int L, H;
    while(scanf("%d %d", &L, &H) && L != 0) {
        if(L > H) {
            int temp = L;
            L = H;
            H = temp;
        }
        int ans = L;
        for(int i = L + 1; i <= H; ++i) {
            if(collatz[ans] < collatz[i])
                ans = i;
        }
        printf("Between %d and %d, %d generates the longest sequence of %hd values.\n", L, H, ans, collatz[ans]);
    }
	return 0;
}
