#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 2703663;
bitset<MAX_NUM + 1> mark;
vector<int> primes, pf(MAX_NUM + 1);

void eulerSieve() {
	for(int n = 2; n <= MAX_NUM; ++n) {
		if(!mark[n]) {
			primes.push_back(n);
			pf[n] = 1;
		}
		for(int i = 0, temp; (temp = primes[i] * n) <= MAX_NUM; ++i) {
			mark[temp] = 1;
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
    for(int i = 2; i <= MAX_NUM; ++i)
        pf[i] += pf[i - 1];
    int cases = 0, N;
    while(cin >> N && N >= 0) {
        if(N == 0)
            cout << "Case " << ++cases << ": 0!\n";
        else {
            int idx = lower_bound(pf.begin() + 2, pf.end(), N) - pf.begin();
            if(pf[idx] == N)
                cout << "Case " << ++cases << ": " << idx << "!\n";
            else
                cout << "Case " << ++cases << ": Not possible.\n";
        }
    }
    return 0;
}
