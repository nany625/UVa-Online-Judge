#include <stdio.h>

int main() {
	int twinTowers = 0, N1, N2;
	while(scanf("%d %d", &N1, &N2) && N1 != 0 && N2 != 0) {
	    int tiles1[N1], tiles2[N2];
	    for(int i = 0; i < N1; ++i)
	        scanf("%d", &tiles1[i]);
	    for(int i = 0; i < N2; ++i)
	        scanf("%d", &tiles2[i]);
	    int L[N1 + 1][N2 + 1];
	    for(int i = 0; i <= N1; ++i) {
	        for(int j = 0; j <= N2; ++j) {
	            if(i == 0 || j == 0)
	                L[i][j] = 0;
	            else if(tiles1[i - 1] == tiles2[j - 1])
	                L[i][j] = L[i - 1][j - 1] + 1;
	            else
	                L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
	        }
	    }
	    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++twinTowers, L[N1][N2]);
	}
	return 0;
}
