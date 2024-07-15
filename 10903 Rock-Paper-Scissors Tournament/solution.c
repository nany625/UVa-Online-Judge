#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int win, lose;
} Player;

int main() {
    int n;
    bool firstCase = true;
    while(scanf("%d", &n) && n != 0) {
        if(!firstCase)
            puts("");
        Player table[n];
        for(int i = 0; i < n; ++i)
            table[i].win = table[i].lose = 0;
        int k;
        scanf("%d", &k);
        int games = k * n * (n - 1) / 2, p1, p2;
        char m1[9], m2[9];
        while(games--) {
            scanf("%d %s %d %s", &p1, m1, &p2, m2);
            if((m1[0] == 'r' && m2[0] == 's') || (m1[0] == 'p' && m2[0] == 'r') || (m1[0] == 's' && m2[0] == 'p')) {
                ++table[p1 - 1].win;
                ++table[p2 - 1].lose;
            } else if((m1[0] == 'r' && m2[0] == 'p') || (m1[0] == 'p' && m2[0] == 's') || (m1[0] == 's' && m2[0] == 'r')) {
                ++table[p2 - 1].win;
                ++table[p1 - 1].lose;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(table[i].win + table[i].lose == 0)
                puts("-");
            else
                printf("%.3f\n", (float)table[i].win / (table[i].win + table[i].lose));
        }
        firstCase = false;
    }
    return 0;
}
