#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;
array<array<unsigned long, MAXN>, MAXN + 1> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= MAXN; ++i) {
        dp[i][0] = 1;
        for(int j = 1; j < i; ++j)
            dp[i][j] = dp[i - 1][j - 1] * (i - 1) + dp[i - 1][j];
    }
    int N, K;
    while(cin >> N >> K && N != 0)
        cout << dp[N][K] << '\n';
    return 0;
}
