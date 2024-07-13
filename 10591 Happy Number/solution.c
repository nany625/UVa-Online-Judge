#include <stdio.h>
#include <stdbool.h>

int main() {
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: %d is ", i, N);
        bool table[401] = {};
        do {
            if(N <= 401)
                table[N - 1] = true;
            int temp = 0;
            while(N > 0) {
                temp += (N % 10) * (N % 10);
                N /= 10;
            }
            N = temp;
        } while(N != 1 && !table[N - 1]);
        puts(N == 1 ? "a Happy number." : "an Unhappy number.");
    }
    return 0;
}
