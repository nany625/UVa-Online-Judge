#include <stdio.h>
#define MAX_NUM 1000000

short factorCount[MAX_NUM + 1] = {0, 1};
int table[MAX_NUM / 2 + 1] = {2};

int main() {
    for(int i = 3; i <= MAX_NUM; ++i) {
        for(int j = i; j <= MAX_NUM; j += i)
            ++factorCount[j];
    }
    short max = 2;
    for(int i = 4; i <= MAX_NUM; i += 2) {
        if(max <= factorCount[i] + 2) {
            max = factorCount[i] + 2;
            table[i / 2 - 1] = i;
        } else
            table[i / 2 - 1] = table[i / 2 - 2];
    }
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N;
	    scanf("%d", &N);
	    if(N == 1 || N == 3)
	        printf("%d\n", N);
	    else
	        printf("%d\n", table[N / 2 - 1]);
	}
	return 0;
}
