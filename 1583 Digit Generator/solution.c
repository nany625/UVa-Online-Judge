#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        bool found = false;
        for(int i = N - 9 * log10(N); i < N && !found; ++i) {
            int temp = i, sumOfDigits = i;
            while(temp > 0) {
                sumOfDigits += temp % 10;
                temp /= 10;
            }
            if(sumOfDigits == N) {
                printf("%d\n", i);
                found = true;
            }
        }
        if(!found)
            puts("0");
    }
	return 0;
}
