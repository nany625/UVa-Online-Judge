#include <stdio.h>
#include <stdbool.h>

int square[1000][1000];

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                scanf("%d", &square[i][j]);
        }
        bool homogeneous = true;
        for(int i = 0; i < n - 1 && homogeneous; ++i) {
            for(int j = 0; j < n - 1 && homogeneous; ++j)
                homogeneous = square[i][j] + square[i + 1][j + 1] == square[i + 1][j] + square[i][j + 1];
        }
        puts(homogeneous ? "homogeneous" : "not homogeneous");
    }
	return 0;
}
