#include <stdio.h>
#include <math.h>

int main() {
    int SZ, P;
    while(scanf("%d %d", &SZ, &P) && SZ != 0) {
        if(P == 1)
            printf("Line = %d, column = %d.\n", SZ + 1 >> 1, SZ + 1 >> 1);
        else {
            int center = SZ + 1 >> 1;
            int level = (int)ceil((1 + sqrt(P)) / 2);
            int length = level - 1 << 1;
            int dist = P - pow(((level << 1) - 3), 2);
            int sideNum = (int)ceil((double)dist / length);
            int elementNum = (dist - 1) % length;
            switch(sideNum) {
                case 1:
                    printf("Line = %d, column = %d.\n", center + level - 1, center + level - 2 - elementNum);
                    break;
                case 2:
                    printf("Line = %d, column = %d.\n", center + level - 2 - elementNum, center - level + 1);
                    break;
                case 3:
                    printf("Line = %d, column = %d.\n", center - level + 1, center - level + 2 + elementNum);
                    break;
                case 4:
                    printf("Line = %d, column = %d.\n", center - level + 2 + elementNum, center + level - 1);
            }
        }
    }
	return 0;
}
