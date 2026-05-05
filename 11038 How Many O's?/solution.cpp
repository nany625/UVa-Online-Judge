#include <bits/stdc++.h>
using namespace std;

long solve(long n) {
    if(n < 0)
        return 0;
    long ans = 1, base = 1;
    do {
        long high = n / (base * 10);
        long cur = n / base % 10;
        long low = n % base;
        if(cur != 0)
            ans += high * base;
        else {
            if(high > 0)
                ans += (high - 1) * base + low + 1;
        }
        if(high == 0)
            return ans;
        base *= 10;
    } while(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long m, n;
    while(cin >> m >> n && m >= 0)
        cout << solve(n) - solve(m - 1) << '\n';
    return 0;
}
