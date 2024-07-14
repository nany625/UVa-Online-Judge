#include <stdio.h>

typedef struct {
    long x, y;
} Coordinate;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        Coordinate src, dest;
        scanf("%ld %ld %ld %ld", &src.x, &src.y, &dest.x, &dest.y);
        printf("Case %d: %ld\n", i, (src.x + src.y + dest.x + dest.y + 2) * (dest.x + dest.y - src.x - src.y - 1) / 2 + src.y + dest.x + 1);
    }
    return 0;
}
