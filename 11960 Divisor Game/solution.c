#include <stdio.h>
#define MAX_NUM 1000000

int factorCount[MAX_NUM + 1] = {0, 1}, table[MAX_NUM + 1] = {0, 1};

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        for(int j = i; j <= MAX_NUM; j += i)
            ++factorCount[j];
    }
    int max = 1;
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(max <= factorCount[i] + 1) {
            max = factorCount[i] + 1;
            table[i] = i;
        }
        else
            table[i] = table[i - 1];
    }
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N;
	    scanf("%d", &N);
	    printf("%d\n", table[N]);
	}
	return 0;
}
