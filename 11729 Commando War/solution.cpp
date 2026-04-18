#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, N;
    while(cin >> N && N != 0) {
        vector<pair<int, int>> soldiers(N);
        for(int i = 0; i < N; ++i)
            cin >> soldiers[i].first >> soldiers[i].second;
        sort(soldiers.begin(), soldiers.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        int ans = soldiers[0].first + soldiers[0].second;
        for(int i = 1; i < N; ++i) {
            soldiers[i].first += soldiers[i - 1].first;
            ans = max(ans, soldiers[i].first + soldiers[i].second);
        }
        cout << "Case " << ++cases << ": " << ans << '\n';
    }
    return 0;
}
