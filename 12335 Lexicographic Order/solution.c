#include <stdio.h>
#include <string.h>
#include <stdbool.h>

long factorials[] = {
    1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 
    39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000
};

int main() {
    int T;
    scanf("%d", &T);
    char s[21];
    for(int i = 1; i <= T; ++i) {
        printf("Case %d: ", i);
        long k;
        scanf("%s %ld", s, &k);
        int len = strlen(s);
        --k;
        char original[len];
        bool put[len];
        for(int j = 0; j < len; ++j)
            put[j] = false;
        for(int j = len - 2; j >= 0; --j) {
            int index = k / factorials[j], count = -1;
            for(int l = 0; l < len; ++l) {
                count += !put[l];
                if(count == index) {
                    original[l] = s[len - 2 - j];
                    put[l] = true;
                    break;
                }
            }
            k %= factorials[j];
        }
        for(int j = 0; j < len; ++j) {
            putchar(put[j] ? original[j] : s[len - 1]);
        }
        putchar('\n');
    }
	return 0;
}
