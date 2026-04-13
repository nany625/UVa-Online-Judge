#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n = pow(10, n);
        long k;
        cin >> k;
        while(k >= n)
            k /= 10;
        long ans = k;
        unordered_set<long> display;
        do {
            display.insert(k);
            k *= k;
            while(k >= n)
                k /= 10;
            ans = max(ans, k);
        } while(!display.count(k));
        cout << ans << '\n';
    }
    return 0;
}
