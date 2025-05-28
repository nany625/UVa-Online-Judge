#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        long k;
        scanf("%ld", &k);
        if(k == 0)
            puts("3");
        else {
            k = abs(k);
            int n = ceil((sqrt((k << 3) + 1) - 1) / 2);
            long temp = n * (n + 1) >> 1;
            while((temp - k) & 1)
                temp += ++n;
            printf("%d\n", n);
        }
        if(cases)
            putchar('\n');
    }
	return 0;
}
