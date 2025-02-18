#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        int M;
        scanf("%d", &M);
        int maxX1 = -10000, maxY1 = -10000, minX2 = 10000, minY2 = 10000;
        while(M--) {
            int X1, Y1, X2, Y2;
            scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
            maxX1 = maxX1 > X1 ? maxX1 : X1;
            maxY1 = maxY1 > Y1 ? maxY1 : Y1;
            minX2 = minX2 < X2 ? minX2 : X2;
            minY2 = minY2 < Y2 ? minY2 : Y2;
        }
        printf("Case %d: %d\n", i, minX2 <= maxX1 || minY2 <= maxY1 ? 0 : (minX2 - maxX1) * (minY2 - maxY1));
    }
    return 0;
}
