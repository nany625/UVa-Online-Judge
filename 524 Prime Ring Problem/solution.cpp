#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime = {
    0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
    0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
    0, 1
};
bitset<16> used;
vector<int> num = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16
}, path(16, 1);

void backtrack(int n, int depth) {
    if(depth == n && isPrime[1 + path[n - 1]]) {
        for(int i = 0; i < n - 1; ++i)
            cout << path[i] << ' ';
        cout << path[n - 1] << '\n';
        return;
    }
    for(int i = 1; i < n; ++i) {
        if(!used[i] && isPrime[path[depth - 1] + num[i]]) {
            used[i] = 1;
            path[depth] = num[i];
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
