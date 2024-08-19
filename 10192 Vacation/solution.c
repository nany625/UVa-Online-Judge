#include <stdio.h>
#include <string.h>

int main() {
    int cases = 0;
    char father[102], mother[102];
    while(fgets(father, sizeof(father), stdin) && father[0] != '#') {
        fgets(mother, sizeof(mother), stdin);
        int m = strlen(father) - 1, n = strlen(mother) - 1;
        int L[n + 1];
        memset(L, 0, sizeof(L));
        for(int i = 0; i < m; ++i) {
            int prev = 0;
            for(int j = 1; j <= n; ++j) {
                int temp = L[j];
                if(father[i] == mother[j - 1])
                    L[j] = prev + 1;
                else
                    L[j] = L[j] > L[j - 1] ? L[j] : L[j - 1];
                prev = temp;
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", ++cases, L[n]);
    }
	return 0;
}
