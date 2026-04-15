#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, N, Q;
    while(cin >> N >> Q && N != 0) {
        cout << "CASE# " << ++cases << ":\n";
        vector<int> marbles(N);
        for(int i = 0; i < N; ++i)
            cin >> marbles[i];
        sort(marbles.begin(), marbles.end());
        while(Q--) {
            int query;
            cin >> query;
            int pos = lower_bound(marbles.begin(), marbles.end(), query) - marbles.begin();
            if(marbles[pos] == query)
                cout << query << " found at " << pos + 1 << '\n';
            else
                cout << query << " not found\n";
        }
    }
    return 0;
}
