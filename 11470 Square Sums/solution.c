#include <stdio.h>

int findMin(int a, int b, int c, int d) {
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min < d ? min : d;
}

int main() {
    int cases = 0, n;
    while(scanf("%d", &n) && n != 0) {
        int squares = (n + 1) / 2;
        short sum[squares];
        for(int i = 0; i < squares; ++i)
            sum[i] = 0;
        short num;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%hd", &num);
                sum[findMin(i, j, n - 1 - i, n - 1 - j)] += num;
            }
        }
        printf("Case %d:", ++cases);
        for(int i = 0; i < squares; ++i)
            printf(" %hd", sum[i]);
        puts("");
    }
    return 0;
}
