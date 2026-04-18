#include <bits/stdc++.h>
using namespace std;

vector<bitset<100>> dp(2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin >> M;
    while(M--) {
        int N, K;
        cin >> N >> K;
        dp[0].reset();
        int num;
        cin >> num;
        num = (num % K + K) % K;
        dp[0][num] = 1;
        for(int i = 1; i < N; ++i) {
            cin >> num;
            num = (num % K + K) % K;
            dp[i & 1].reset();
            for(int j = 0; j < K; ++j) {
                if(dp[!(i & 1)][j]) {
                    dp[i & 1][(j + num) % K] = 1;
                    dp[i & 1][(j + K - num) % K] = 1;
                }
            }
        }
        cout << (dp[(N - 1) & 1][0] ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}
