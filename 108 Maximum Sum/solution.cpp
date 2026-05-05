#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<vector<int>> rec(MAXN, vector<int>(MAXN));

int maxSubarraySum(vector<int> a) {
    int ans = a[0], temp = a[0];
    for(int i = 1; i < a.size(); ++i) {
        temp = max(a[i], temp + a[i]);
        ans = max(ans, temp);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j)
                cin >> rec[i][j];
        }
        int ans = -127;
        for(int i = 0; i < N; ++i) {
            vector<int> temp(N);
            for(int j = i; j < N; ++j) {
                for(int k = 0; k < N; ++k)
                    temp[k] += rec[j][k];
                ans = max(ans, maxSubarraySum(temp));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
