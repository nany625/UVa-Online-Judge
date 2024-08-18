#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dRow[] = {1, 0, 0, -1}, dCol[] = {0, 1, -1, 0};

typedef struct {
    char language;
    int states;
} Rank;

void dfs(char **map, int row, int rowLimit, int col, int colLimit, char language) {
    if(map[row][col] == language) {
        map[row][col] = ' ';
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                dfs(map, newRow, rowLimit, newCol, colLimit, language);
        }
    }
}

int compare(const void *a, const void *b) {
    Rank *r1 = (Rank*)a;
    Rank *r2 = (Rank*)b;
    if(r1->states == r2->states)
        return r1->language > r2->language;
    return r1->states < r2->states;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        printf("World #%d\n", i);
        int H, W;
        scanf("%d %d", &H, &W);
        char **map = (char**)malloc(H * sizeof(char*));
        for(int j = 0; j < H; ++j) {
            map[j] = (char*)malloc((W + 1) * sizeof(char));
            scanf("%s", map[j]);
        }
        Rank ranks[26];
        for(int j = 0; j < 26; ++j) {
            ranks[j].language = 'a' + j;
            ranks[j].states = 0;
        }
        for(int j = 0; j < H; ++j) {
            for(int k = 0; k < W; ++k) {
                if(islower(map[j][k])) {
                    ++ranks[map[j][k] - 'a'].states;
                    dfs(map, j, H, k, W, map[j][k]);
                }
            }
        }
        qsort(ranks, 26, sizeof(Rank), compare);
        for(int j = 0; j < 26 && ranks[j].states > 0; ++j)
            printf("%c: %d\n", ranks[j].language, ranks[j].states);
        for(int j = 0; j < H; ++j)
            free(map[j]);
        free(map);
    }
	return 0;
}
