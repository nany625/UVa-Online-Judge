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
	for(int i = 3; i <= MAX_NUM; i += 2) {
	    if(!mark[i >> 1]) {
	        appendAlmostPrimes(i);
	        if(i <= 999) {
	            for(int j = i * i; j <= MAX_NUM; j += i << 1)
	                mark[j >> 1] = 1;
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
