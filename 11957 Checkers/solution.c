#include <stdio.h>
#include <string.h>
#define MOD 1000007

int dRow[] = {-1, -1}, dCol[] = {1, -1};
char board[100][101];

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; ++j)
            scanf("%s", board[j]);
        int startRow = 0, startCol = 0;
        while(board[startRow][startCol] != 'W') {
            ++startCol;
            if(startCol == N) {
                ++startRow;
                startCol = 0;
            }
        }
        int paths[startRow + 1][N];
        memset(paths, 0, sizeof(paths));
        paths[startRow][startCol] = 1;
        for(int j = startRow; j > 0; --j) {
            for(int k = 0; k < N; ++k) {
                for(int l = 0; l < 2; ++l) {
                    int newRow = j + dRow[l], newCol = k + dCol[l];
                    if(newRow >= 0 && newCol >= 0 && newCol < N) {
                        if(board[newRow][newCol] == '.')
                            paths[newRow][newCol] = (paths[newRow][newCol] + paths[j][k]) % MOD;
                        else if(board[newRow][newCol] == 'B') {
                            newRow = j + (dRow[l] << 1);
                            newCol = k + (dCol[l] << 1);
                            if(newRow >= 0 && newCol >= 0 && newCol < N && board[newRow][newCol] == '.')
                                paths[newRow][newCol] = (paths[newRow][newCol] + paths[j][k]) % MOD;
                        }
                    }
                }
            }
        }
        int totalPaths = 0;
        for(int j = (startRow + startCol) & 1; j < N; j += 2)
            totalPaths += paths[0][j];
        printf("Case %d: %d\n", i, totalPaths %= MOD);
    }
	return 0;
}
