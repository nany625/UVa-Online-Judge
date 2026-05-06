#include <bits/stdc++.h>
using namespace std;

const int MAXN = 999999;
array<short, MAXN + 1> collatz = {0, 1};

void init(int n) {
    collatz[n] = 1;
    long temp = n;
    while(temp != 1) {
        if(temp < n) {
            collatz[n] += collatz[temp] - 1;
            return;
        }
        temp = temp & 1 ? 3 * temp + 1 : temp >> 1;
        ++collatz[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int n = 2; n <= MAXN; ++n)
        init(n);
    int min, max;
    while(cin >> min >> max) {
        cout << min << ' ' << max << ' ';
        auto [l, r] = minmax(min, max);
        cout << *max_element(collatz.begin() + l, collatz.begin() + r + 1) << '\n';
    }
    return 0;
}
