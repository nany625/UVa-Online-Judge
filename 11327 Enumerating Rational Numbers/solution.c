#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 200000
#define MAX_PRIME 443

bool isComposite[(MAX_PRIME >> 1) + 1];
short *primes;
int size = 1;
long ans[MAX_NUM + 1] = {0, 2};

void eulerSieve() {
    primes = (short*)malloc(sizeof(short));
    primes[0] = 2;
    for(short n = 3; n <= MAX_PRIME; n += 2) {
        if(!isComposite[n >> 1]) {
            primes = (short*)realloc(primes, (size + 1) * sizeof(short));
            primes[size++] = n;
        }
        for(int i = 1, temp; i < size && (temp = primes[i] * n) <= MAX_PRIME; ++i) {
            isComposite[temp >> 1] = true;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int eulerTotient(int n) {
    int result = n, limit = sqrt(n);
    for(int i = 0; i < size && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            result -= result / primes[i];
            do {
                n /= primes[i];
            } while(n % primes[i] == 0);
            limit = sqrt(n);
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
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
    eulerSieve();
    for(int n = 2; n <= MAX_NUM; ++n)
        ans[n] = ans[n - 1] + eulerTotient(n);
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
    free(primes);
    return 0;
}
