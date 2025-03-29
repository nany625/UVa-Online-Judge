#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(short*)a > *(short*)b;
}

int main() {
    int n, d, r;
    while(scanf("%d %d %d", &n, &d, &r) && n != 0) {
        short morning[n], evening[n];
        for(int i = 0; i < n; ++i)
            scanf("%hd", &morning[i]);
        for(int i = 0; i < n; ++i)
            scanf("%hd", &evening[i]);
        qsort(morning, n, sizeof(short), compare);
        qsort(evening, n, sizeof(short), compare);
        int pay = 0;
        for(int i = 0; i < n; ++i) {
            short route = morning[i] + evening[n - 1 - i];
            pay += (route > d) ? (route - d) * r : 0;
        }
        printf("%d\n", pay);
    }
    return 0;
}
