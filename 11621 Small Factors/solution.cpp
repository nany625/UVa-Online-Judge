#include <bits/stdc++.h>
using namespace std;

vector<int> C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long i = 1;
    while(i <= INT_MAX) {
        long temp = i;
        do {
            C.push_back(temp);
            temp *= 3;
        } while(temp <= INT_MAX);
        i <<= 1;
    }
    sort(C.begin(), C.end());
    int m;
    while(cin >> m && m != 0) {
        int idx = lower_bound(C.begin(), C.end(), m) - C.begin();
        cout << (idx < C.size() ? C[idx] : 2147483648) << '\n';
    }
    return 0;
}
