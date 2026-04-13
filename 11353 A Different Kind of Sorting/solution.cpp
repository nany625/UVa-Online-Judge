#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 2000000;
const int MAX_CNT = 20;
unsigned int mark[(MAX_NUM >> 5) + 1];
vector<int> primes, pf(MAX_NUM + 1), order;
vector<vector<int>> bucket(MAX_CNT + 1);

void setBit(int n) {
    mark[n >> 5] |= 1u << (n & 31);
}

void eulerSieve() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(pf[n] == 0) {
            primes.push_back(n);
            pf[n] = 1;
        }
        for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
            setBit(temp);
            pf[temp] = 1 + pf[n];
            if(n % primes[i] == 0)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eulerSieve();
    for(int i = 1; i <= MAX_NUM; ++i)
        bucket[pf[i]].push_back(i);
    for(int i = 0; i <= MAX_CNT; ++i) {
        for(int num : bucket[i])
            order.push_back(num);
    }
    int cases = 0, n;
    while(cin >> n && n != 0)
        cout << "Case " << ++cases << ": " << order[n - 1] << '\n';
    return 0;
}
