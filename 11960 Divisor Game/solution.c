#include <stdio.h>
#define MAXN 1000000

short factorCount[MAXN + 1] = {0, 1};
int table[MAXN >> 1] = {2};

int main() {
    for(int i = 3; i <= MAXN; ++i) {
        for(int j = i; j <= MAXN; j += i)
            ++factorCount[j];
    }
    short max = 2;
    for(int i = 4; i <= MAXN; i += 2) {
        if(max <= factorCount[i] + 2) {
            max = factorCount[i] + 2;
            table[(i >> 1) - 1] = i;
        } else
            table[(i >> 1) - 1] = table[(i >> 1) - 2];
    }
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N;
	    scanf("%d", &N);
	    if(N == 1 || N == 3)
	        printf("%d\n", N);
	    else
	        printf("%d\n", table[(N >> 1) - 1]);
	}
	return 0;
}
