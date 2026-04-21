#include <bits/stdc++.h>
using namespace std;

const int MAXN = 13;
vector<vector<vector<long>>> dp(MAXN + 1, vector<vector<long>>(MAXN + 1, vector<long>(MAXN + 1)));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1][1][1] = 1;
    for(int i = 2; i <= MAXN; ++i) {
        for(int j = 1; j <= i; ++j) {
            for(int k = 1; k <= i; ++k)
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + (i - 2) * dp[i - 1][j][k];
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int N, P, R;
        cin >> N >> P >> R;
        cout << dp[N][P][R] << '\n';
    }
    return 0;
}
