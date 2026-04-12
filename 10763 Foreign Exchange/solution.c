#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int original[n], target[n];
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &original[i], &target[i]);
        qsort(original, n, sizeof(int), compare);
        qsort(target, n, sizeof(int), compare);
        int i = 0;
        while(i < n && original[i] == target[i])
            ++i;
        puts(i == n ? "YES" : "NO");
    }
    return 0;
}
