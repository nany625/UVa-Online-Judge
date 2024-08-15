#include <stdio.h>
#include <string.h>

int main() {
	int twinTowers = 0, N1, N2;
	while(scanf("%d %d", &N1, &N2) && N1 != 0 && N2 != 0) {
	    int tiles1[N1], tiles2[N2];
	    for(int i = 0; i < N1; ++i)
	        scanf("%d", &tiles1[i]);
	    for(int i = 0; i < N2; ++i)
	        scanf("%d", &tiles2[i]);
	    int L[N2 + 1];
	    memset(L, 0, sizeof(L));
	    for(int i = 0; i < N1; ++i) {
	        int prev = 0;
	        for(int j = 1; j <= N2; ++j) {
	            int temp = L[j];
	            if(tiles1[i] == tiles2[j - 1])
	                L[j] = prev + 1;
	            else
	                L[j] = L[j] > L[j - 1] ? L[j] : L[j - 1];
	            prev = temp;
	        }
	    }
	    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++twinTowers, L[N2]);
	}
	return 0;
}
