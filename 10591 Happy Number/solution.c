// #解法一
#include <stdio.h>
#include <stdbool.h>

short table[] = {
    1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 
    49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 
    103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 
    192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 
    263, 280, 291, 293, 301, 302, 310, 313, 319, 320, 
    326, 329, 331, 338, 356, 362, 365, 367, 368, 376, 
    379, 383, 386, 391, 392, 397, 404, 409, 440, 446, 
    464, 469, 478, 487, 490, 496, 536, 556, 563, 565, 
    566, 608, 617, 622, 623, 632, 635, 637, 638, 644, 
    649, 653, 655, 656, 665, 671, 673, 680, 683, 694, 
    700, 709, 716
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
    bool isHappy[729] = {};
    for(int i = 0; i < 103; ++i)
        isHappy[table[i] - 1] = true;
    int cases;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; ++i) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: %d is %s number.\n", i, N, isHappy[squareSum(N) - 1] ? "a Happy" : "an Unhappy");
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
        bool check[729] = {};
        do {
            if(N <= 729)
                check[N - 1] = true;
            int temp = 0;
            while(N > 0) {
                temp += (N % 10) * (N % 10);
                N /= 10;
            }
            N = temp;
        } while(N != 1 && !check[N - 1]);
        puts(N == 1 ? "a Happy number." : "an Unhappy number.");
    }
    return 0;
}
