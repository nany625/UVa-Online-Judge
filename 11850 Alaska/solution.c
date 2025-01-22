#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int locations[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &locations[i]);
        qsort(locations, n, sizeof(int), compare);
        bool possible = true;
        for(int i = 1; i < n && possible; ++i)
            possible = locations[i] - locations[i - 1] <= 200;
        puts(possible && locations[n - 1] >= 1322 ? "POSSIBLE" : "IMPOSSIBLE");
    }
	return 0;
}
