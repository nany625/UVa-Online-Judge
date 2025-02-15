#include <stdio.h>
#include <string.h>

int main() {
    int bottles[9], total[6];
    char color[6][4] = {"BGC", "GCB", "CBG", "CGB", "GBC", "BCG"};
    while(scanf("%d", &bottles[0]) == 1) {
        for(int i = 1; i < 9; ++i)
            scanf("%d", &bottles[i]);
        total[0] = bottles[0] + bottles[4] + bottles[8];
        total[1] = bottles[1] + bottles[5] + bottles[6];
        total[2] = bottles[2] + bottles[3] + bottles[7];
        total[3] = bottles[2] + bottles[4] + bottles[6];
        total[4] = bottles[1] + bottles[3] + bottles[8];
        total[5] = bottles[0] + bottles[5] + bottles[7];
        int maxTotal = 0, maxIndex;
        for(int i = 0; i < 6; ++i) {
            if(total[i] > maxTotal)
                maxTotal = total[maxIndex = i];
            else if(total[i] == maxTotal && strcmp(color[i], color[maxIndex]) < 0)
                maxIndex = i;
        }
        printf("%s %d\n", color[maxIndex], total[0] + total[1] + total[2] - maxTotal);
    }
	return 0;
}
