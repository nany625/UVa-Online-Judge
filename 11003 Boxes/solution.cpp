#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<pair<int, int>> box(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N && N != 0) {
        for(int i = N - 1; i >= 0; --i)
            cin >> box[i].first >> box[i].second;
        vector<int> dp = {0};
        for(int i = 0; i < N; ++i) {
            if(dp.back() <= box[i].second)
                dp.push_back(dp.back() + box[i].first);
            for(int j = dp.size() - 2; j >= 0; --j) {
                if(dp[j] <= box[i].second)
                    dp[j + 1] = min(dp[j + 1], dp[j] + box[i].first);
            }
        }
        cout << dp.size() - 1 << '\n';
    }
    return 0;
}
