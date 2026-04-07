#include <bits/stdc++.h>
using namespace std;

int MAXN = 999999;

vector<short> collatz(MAXN + 1);

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
    collatz[1] = 1;
    for(int n = 2; n <= MAXN; ++n)
        init(n);
    int min, max;
    while(cin >> min >> max) {
        cout << min << ' ' << max << ' ';
        if(min > max)
            swap(min, max);
        cout << max_element(collatz + min, collatz + max + 1) << '\n';
    }
    return 0;
}
