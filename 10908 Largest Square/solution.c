#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int M, N, Q;
        scanf("%d %d %d", &M, &N, &Q);
        printf("%d %d %d\n", M, N, Q);
        char rec[M][N + 1];
        for(int i = 0; i < M; ++i)
            scanf("%s", rec[i]);
        while(Q--) {
            int r, c;
            scanf("%d %d", &r, &c);
            bool isSquare = true;
            int range = 0;
            do {
                ++range;
                if(r - range < 0 || r + range >= M || c - range < 0 || c + range >= N)
                    isSquare = false;
                else {
                    for(int col = c - range; col < c + range && isSquare; ++col) {
                        if(rec[r - range][col] != rec[r][c])
                            isSquare = false;
                    }
                    for(int row = r - range; row < r + range && isSquare; ++row) {
                        if(rec[row][c + range] != rec[r][c])
                            isSquare = false;
                    }
                    for(int col = c + range; col >= c - range + 1 && isSquare; --col) {
                        if(rec[r + range][col] != rec[r][c])
                            isSquare = false;
                    }
                    for(int row = r + range; row >= r - range + 1 && isSquare; --row) {
                        if(rec[row][c - range] != rec[r][c])
                            isSquare = false;
                    }
                }
		    } while(isSquare);
            printf("%d\n", 2 * range - 1);
        }
    }
    return 0;
}
