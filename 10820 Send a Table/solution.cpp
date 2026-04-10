#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

vector<int> ans(MAXN + 1);

void computePhi() {
    for(int n = 2; n <= MAXN; ++n) {
        if(ans[n] == n) {
            for(int i = n; i <= MAXN; i += n)
                ans[i] -= ans[i] / n;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    iota(ans.begin(), ans.end(), 0);
    computePhi();
    for(int n = 2; n <= MAXN; ++n)
        ans[n] = (ans[n] << 1) + ans[n - 1];
    int N;
    while(cin >> N && N != 0)
        cout << ans[N] << '\n';
    return 0;
}
