#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        int h1, m1, h2, m2, h3, m3, h4, m4;
        scanf("%d:%d %d:%d %d:%d %d:%d", &h1, &m1, &h2, &m2, &h3, &m3, &h4, &m4);
        h1 = 60 * h1 + m1;
        h2 = 60 * h2 + m2;
        h3 = 60 * h3 + m3;
        h4 = 60 * h4 + m4;
        printf("Case %d: %ss Meeting\n", i, h1 > h4 || h2 < h3 ? "Hit" : "Mr");
    }
	return 0;
}
