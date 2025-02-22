// #解法一(正規演算法)
#include <stdio.h>

int josephus(int n, int k) {
    int ans = 0;
    for(int i = 2; i <= n; ++i)
        ans = (ans + k) % i;
    return ans;
}

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        int m = 1;
        while(josephus(N - 1, m) != 11)
            ++m;
        printf("%d\n", m);
    }
	return 0;
}

// #解法二(正規演算法)
#include <stdio.h>

int josephus(int n, int k) {
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        int m = 1;
        while(josephus(N - 1, m) != 11)
            ++m;
        printf("%d\n", m);
    }
	return 0;
}

// #解法三(捷徑)
#include <stdio.h>

short ans[] = {
    1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 
    21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 
    42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 
    38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 
    38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 
    72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 
    67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 
    137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 
    49, 5, 22, 54, 52, 113, 15, 66
};

int main() {
    int N;
	while(scanf("%d", &N) && N != 0)
	   printf("%hd\n", ans[N - 13]);
	return 0;
}
