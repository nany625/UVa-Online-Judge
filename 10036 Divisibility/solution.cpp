#include <bits/stdc++.h>
using namespace std;

vector<vector<unsigned int>> dp(2, vector<unsigned int>(4));

bool get(int row, int num) {
    return dp[row][num >> 5] & (1u << (num & 31));
}

void setBit(int row, int num) {
    dp[row][num >> 5] |= 1u << (num & 31);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin >> M;
    while(M--) {
        int N, K;
        cin >> N >> K;
        fill(dp[0].begin(), dp[0].end(), 0);
        int num;
        cin >> num;
        num = (num % K + K) % K;
        setBit(0, num);
        for(int i = 1; i < N; ++i) {
            cin >> num;
            num = (num % K + K) % K;
            fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
            for(int j = 0; j < K; ++j) {
                if(get(!(i & 1), j)) {
                    setBit(i & 1, (j + num) % K);
                    setBit(i & 1, (j + K - num) % K);
                }
            }
        }
        cout << (get((N - 1) & 1, 0) ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}
