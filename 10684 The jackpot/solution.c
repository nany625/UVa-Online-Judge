#include <stdio.h>

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        int max = 0, currMax = 0, temp;
        while(N--) {
            scanf("%d", &temp);
            currMax = temp > currMax + temp ? temp : currMax + temp;
            max = max > currMax ? max : currMax;
        }
        if(max > 0)
            printf("The maximum winning streak is %d.\n", max);
        else
            puts("Losing streak.");
    }
	return 0;
}
