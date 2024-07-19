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
	    char word[31];
	    int count = 0;
        while(n--) {
            scanf("%s", word);
            int frequency[26] = {}, len = strlen(word);
            for(int i = 0; i < len; ++i)
                ++frequency[word[i] - 'a'];
            bool ans[26] = {}, isCool = true;
            int found = 0, diff = 0;
            for(int i = 0; i < 26 && found < len && isCool; ++i) {
                if(frequency[i] > 0) {
                    if(!ans[frequency[i] - 1]) {
                        diff += ans[frequency[i] - 1] = true;
                        found += frequency[i];
                    } else
                        isCool = false;
                }
            }
            count += (isCool && diff > 1);
        }
        printf("Case %d: %d\n", ++cases, count);
    }
    return 0;
}
