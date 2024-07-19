#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int cases = 0, n;
	while(scanf("%d", &n) == 1) {
	    char word[12];
	    int count = 0;
        while(n--) {
            scanf("%s", word);
            int frequency[26] = {}, len = strlen(word);
            for(int i = 0; i < len; ++i)
                ++frequency[word[i] - 'a'];
            qsort(frequency, 26, sizeof(int), compare);
            bool isCool = frequency[1] > 0;
            for(int i = 0; i < 26 && frequency[i] > 0 && isCool; ++i)
                isCool = frequency[i] > frequency[i + 1];
            count += isCool;
        }
        printf("Case %d: %d\n", ++cases, count);
    }
    return 0;
}
