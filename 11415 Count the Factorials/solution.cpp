#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;
vector<int> cnt(MAXN + 1), primes;

void eulerSieve() {
    for(int n = 2; n <= MAXN; ++n) {
        if(!cnt[n]) {
            primes.push_back(n);
            cnt[n] = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAXN; ++i) {
            cnt[temp] = 1 + cnt[n];
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    for(int n = 3; n <= MAXN; ++n)
        cnt[n] += cnt[n - 1];
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << upper_bound(cnt.begin() + 3, cnt.end(), n) - cnt.begin() << '\n';
    }
    return 0;
}
