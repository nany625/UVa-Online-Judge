#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 999999;
bitset<500000> mark;
vector<long> almostPrimes;

void appendAlmostPrimes(int i) {
    long p = (long)i * i;
    while(p < 1000000000000) {
	    almostPrimes.push_back(p);
	    p *= i;
    }
}

void eratosthenesSieve() {
    appendAlmostPrimes(2);
	for(int n = 3; n <= MAX_NUM; n += 2) {
	    if(!mark[n >> 1]) {
	        appendAlmostPrimes(n);
	        if(n <= 999) {
	            for(int i = n * n; i <= MAX_NUM; i += n << 1)
	                mark[i >> 1] = 1;
	        }
	    }
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    eratosthenesSieve();
    sort(almostPrimes.begin(), almostPrimes.end());
    int N;
    cin >> N;
    while(N--) {
        long low, high;
        cin >> low >> high;
        int posLow = lower_bound(almostPrimes.begin(), almostPrimes.end(), low) - almostPrimes.begin();
        int posHigh = upper_bound(almostPrimes.begin(), almostPrimes.end(), high) - almostPrimes.begin();
        cout << posHigh - posLow << '\n';
    }
    return 0;
}
