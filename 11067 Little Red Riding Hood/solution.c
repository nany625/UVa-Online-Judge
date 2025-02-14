#include <stdio.h>
#include <string.h>

int ways[101][101];

int main() {
    int w, h;
    while(scanf("%d %d", &w, &h) && w != 0) {
        memset(ways, 0, sizeof(ways));
        int n;
        scanf("%d", &n);
        while(n--) {
            int x, y;
            scanf("%d %d", &x, &y);
            ways[x][y] = -1;
        }
        if(ways[0][0] == 0)
            ways[0][0] = 1;
        for(int i = 1; i <= w; ++i) {
            if(ways[i][0] == 0)
                ways[i][0] = ways[i - 1][0];
        }
        for(int i = 1; i <= h; ++i) {
            if(ways[0][i] == 0)
                ways[0][i] = ways[0][i - 1];
        }
        int x = 1, y = 1;
        while(x <= w && y <= h) {
            for(int i = x; i <= w; ++i) {
                if(ways[i][y] == 0) {
                    if(ways[i - 1][y] == -1 && ways[i][y - 1] == -1)
                        ways[i][y] = -1;
                    else if(ways[i - 1][y] == -1)
                        ways[i][y] = ways[i][y - 1];
                    else if(ways[i][y - 1] == -1)
                        ways[i][y] = ways[i - 1][y];
                    else
                        ways[i][y] = ways[i - 1][y] + ways[i][y - 1];
                }
            }
            for(int i = y + 1; i <= h; ++i) {
                if(ways[x][i] == 0) {
                    if(ways[x][i - 1] == -1 && ways[x - 1][i] == -1)
                        ways[x][i] = -1;
                    else if(ways[x][i - 1] == -1)
                        ways[x][i] = ways[x - 1][i];
                    else if(ways[x - 1][i] == -1)
                        ways[x][i] = ways[x][i - 1];
                    else
                        ways[x][i] = ways[x][i - 1] + ways[x - 1][i];
                }
            }
            ++x;
            ++y;
        }
        if(ways[w][h] <= 0)
            puts("There is no path.");
        else if(ways[w][h] == 1)
            puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
        else
            printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n", ways[w][h]);
    }
    return 0;
}
