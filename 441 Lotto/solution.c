#include <stdio.h>
#include <stdbool.h>

int main() {
    int k;
    bool firstCase = true;
    while(scanf("%d", &k) && k != 0) {
        if(!firstCase)
            putchar('\n');
        int S[k];
        for(int i = 0; i < k; ++i)
            scanf("%d", &S[i]);
        for(int i = 0; i < k - 5; ++i) {
            for(int j = i + 1; j < k - 4; ++j) {
                for(int l = j + 1; l < k - 3; ++l) {
                    for(int m = l + 1; m < k - 2; ++m) {
                        for(int n = m + 1; n < k - 1; ++n) {
                            for(int o = n + 1; o < k; ++o)
                                printf("%d %d %d %d %d %d\n", S[i], S[j], S[l], S[m], S[n], S[o]);
                        }
                    }
                }
            }
        }
        firstCase = false;
    }
	return 0;
}
