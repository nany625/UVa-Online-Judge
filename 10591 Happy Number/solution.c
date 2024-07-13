// #解法一
#include <stdio.h>
#include <stdbool.h>

int table[] = {
    1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 
    49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 
    103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 
    192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 
    263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 
    326, 329, 331, 338, 356, 362, 365, 367, 368, 376, 
    379, 383, 386, 391, 392, 397
};

int squareSum(int n) {
    int result = 0;
    while(n > 0) {
        result += (n % 10) * (n % 10);
        n /= 10;
    }
    return result;
}

int main() {
    bool happy[397] = {};
    for(int i = 0; i < 66; ++i)
        happy[table[i] - 1] = true;
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: %d is ", i, N);
        while(N > 397)
            N = squareSum(N);
        puts(happy[N - 1] ? "a Happy number." : "an Unhappy number.");
    }
    return 0;
}

// #解法二
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
