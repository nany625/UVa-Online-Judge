#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100000

bool used[MAX];

bool isGood(int step, int mod) {
    memset(used, 0, sizeof(used));
    used[0] = true;
    int seed = 0;
    for(int i = 1; i < mod; ++i) {
        seed = (seed + step) % mod;
        if(used[seed])
            return false;
        used[seed] = true;
    }
    return true;
}

int main() {
	int step, mod;
	while(scanf("%d %d", &step, &mod) == 2)
	    printf("%10d%10d    %s Choice\n\n", step, mod, isGood(step, mod) ? "Good" : "Bad");
	return 0;
}
