#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool board[501][501];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int W, H, N;
    while(scanf("%d %d %d", &W, &H, &N) && W != 0) {
        memset(board, 0, sizeof(board));
        int ans = W * H;
        while(N--) {
            int X1, Y1, X2, Y2;
            scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
            if(X1 > X2)
                swap(&X1, &X2);
            if(Y1 > Y2)
                swap(&Y1, &Y2);
            for(int i = X1; i <= X2; ++i) {
                for(int j = Y1; j <= Y2; ++j) {
                    if(!board[i][j]) {
                        --ans;
                        board[i][j] = true;
                    }
                }
            }
        }
        if(ans == 0)
            puts("There is no empty spots.");
        else if(ans == 1)
            puts("There is one empty spot.");
        else
            printf("There are %d empty spots.\n", ans);
    }
    return 0;
}
