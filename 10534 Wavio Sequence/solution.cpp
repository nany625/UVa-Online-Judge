#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N) {
        vector<int> sequence(N), LIS, pos(N);
        for(int i = 0; i < N; ++i) {
            cin >> sequence[i];
            int idx = lower_bound(LIS.begin(), LIS.end(), sequence[i]) - LIS.begin();
            if(idx == LIS.size())
                LIS.push_back(sequence[i]);
            else
                LIS[idx] = sequence[i];
            pos[i] = idx + 1;
        }
        vector<int> LDS;
        int ans = 1;
        for(int i = N - 1; i >= 0; --i) {
            int idx = lower_bound(LDS.begin(), LDS.end(), sequence[i]) - LDS.begin();
            if(idx == LDS.size())
                LDS.push_back(sequence[i]);
            else
                LDS[idx] = sequence[i];
            int temp = min(pos[i], idx + 1);
            ans = max(ans, temp);
        }
        cout << (ans << 1) - 1 << '\n';
    }
    return 0;
}
