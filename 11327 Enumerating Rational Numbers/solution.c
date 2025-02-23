#include <stdio.h>
#define MAX_NUM 200000

long ans[MAX_NUM + 1] = {0, 2};

void eratosthenesSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(ans[n] == n) {
            for(int i = n; i <= MAX_NUM; i += n)
                ans[i] -= ans[i] / n;
        }
        ans[n] += ans[n - 1];
    }
}

int binarySearch(long key) {
    int left = 2, right = MAX_NUM;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(ans[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
    for(int n = 2; n <= MAX_NUM; ++n)
        ans[n] = n;
    eratosthenesSieve();
    long k;
    while(scanf("%ld", &k) && k != 0) {
        if(k <= 2)
            printf("%ld/1\n", k - 1);
        else {
            int pos = binarySearch(k);
            if(k << 1 <= ans[pos - 1] + ans[pos]) {
                long count = ans[pos - 1];
                for(int i = 1; i < pos; ++i) {
                    count += GCD(i, pos) == 1;
                    if(count == k) {
                        printf("%d/%d\n", i, pos);
                        break;
                    }
                }
            } else {
                long count = ans[pos] + 1;
                for(int i = pos - 1; i >= 1; --i) {
                    count -= GCD(i, pos) == 1;
                    if(count == k) {
                        printf("%d/%d\n", i, pos);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
