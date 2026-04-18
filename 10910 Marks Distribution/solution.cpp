#include <bits/stdc++.h>
using namespace std;

const int MAX = 70;
vector<vector<int>> ans(MAX + 1, vector<int>(MAX + 1));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= MAX; ++i) {
        ans[i][0] = 1;
        for(int j = 1; j <= MAX; ++j)
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
    }
    int K;
    cin >> K;
    while(K--) {
        int N, T, P;
        cin >> N >> T >> P;
        if(T - N * P < 0)
            cout << "0\n";
        else
            cout << ans[N][T - N * P] << '\n';
    }
    return 0;
}
