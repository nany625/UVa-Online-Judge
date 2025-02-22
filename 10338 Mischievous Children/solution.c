#include <stdio.h>
#include <string.h>

long fac[21] = {1, 1};

int main() {
    for(int i = 2; i < 21; ++i)
        fac[i] = fac[i - 1] * i;
    int dataSets;
    scanf("%d", &dataSets);
    char s[21];
    for(int i = 1; i <= dataSets; ++i) {
        scanf("%s", s);
        int count[26] = {}, len = strlen(s);
        for(int j = 0; j < len; ++j)
            ++count[s[j] - 'A'];
        long ans = fac[len];
        for(int j = 0; j < 26; ++j)
            ans /= fac[count[j]];
        printf("Data set %d: %ld\n", i, ans);
    }
	return 0;
}
