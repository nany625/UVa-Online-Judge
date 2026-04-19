#include <bits/stdc++.h>
using namespace std;

const int MAXN = 46341;
bitset<(MAXN >> 1) + 1> mark;
vector<int> primes;

void eulerSieve() {
    primes.push_back(2);
    for(int n = 3; n <= MAXN; n += 2) {
        if(!mark[n >> 1])
            primes.push_back(n);
        for(int i = 1, temp; (temp = primes[i] * n) <= MAXN; ++i) {
            mark[temp >> 1] = 1;
            if(n % primes[i] == 0)
                break;
        }
    }
}

int solve(int n) {
    int ans = n, limit = sqrt(n), factors = 1;
    for(int i = 0; i < primes.size() && primes[i] <= limit; ++i) {
        if(n % primes[i] == 0) {
            ans -= ans / primes[i];
            int cnt = 0;
            do {
                n /= primes[i];
                ++cnt;
            } while(n % primes[i] == 0);
            factors *= (cnt + 1);
            limit = sqrt(n);
        }
    }
    if(n > 1) {
        ans -= ans / n;
        factors <<= 1;
    }
    return ans + factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    int n;
    while(cin >> n)
        cout << n - solve(n) + 1 << '\n';
    return 0;
}
