#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> ad(N);
        for(int j = 0; j < N; ++j) {
            cin >> get<0>(ad[j]) >> get<1>(ad[j]) >> get<2>(ad[j]);
            get<1>(ad[j]) += get<0>(ad[j]);
        }
        sort(ad.begin(), ad.end(), [](auto &a, auto &b) {
            return get<1>(a) < get<1>(b);
        });
        vector<int> ends(N);
        for(int j = 0; j < N; ++j)
            ends[j] = get<1>(ad[j]);
        vector<int> dp(N);
        dp[0] = get<2>(ad[0]);
        for(int j = 1; j < N; ++j) {
            int pos = upper_bound(
                ad.begin(), 
                ad.begin() + j, 
                get<0>(ad[j]), 
                [](int val, const tuple<int, int, int> &a) {
                    return val < get<1>(a);
                }) - ad.begin();
            if(pos == 0)
                dp[j] = max(dp[j - 1], get<2>(ad[j]));
            else
                dp[j] = max(dp[j - 1], dp[pos - 1] + get<2>(ad[j]));
        }
        cout << "Case " << i << ": " << dp[N - 1] << '\n';
    }
    return 0;
}
