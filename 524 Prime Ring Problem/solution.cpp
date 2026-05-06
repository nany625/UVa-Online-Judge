#include <bits/stdc++.h>
using namespace std;

bitset<32> isPrime("10100000100010100010100010101100");
bitset<16> used;
array<int, 16> path = {1};

void backtrack(int n, int depth) {
    if(depth == n && isPrime[1 + path[n - 1]]) {
        for(int i = 0; i < n - 1; ++i)
            cout << path[i] << ' ';
        cout << path[n - 1] << '\n';
        return;
    }
    for(int i = 1; i < n; ++i) {
        if(!used[i] && isPrime[path[depth - 1] + i + 1]) {
            used[i] = 1;
            path[depth] = i + 1;
            backtrack(n, depth + 1);
            used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, n;
    while(cin >> n) {
        if(cases)
            cout << '\n';
        cout << "Case " << ++cases << ":\n";
        backtrack(n, 1);
    }
    return 0;
}
