#include <stdio.h>

int findMin(int a, int b) {
    return a < b ? a : b;
}

int findMax(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int l, n;
        scanf("%d %d", &l, &n);
        int pos, min = 0, max = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &pos);
            min = findMax(min, findMin(pos, l - pos));
            max = findMax(max, findMax(pos, l - pos));
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}
