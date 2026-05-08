#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;
array<int, MAXN + 1> ans;

void computePhi() {
    for(int n = 2; n <= MAXN; ++n) {
        if(ans[n] == n) {
            for(int i = n; i <= MAXN; i += n)
                ans[i] -= ans[i] / n;
        }
        ans[n] = (ans[n] << 1) + ans[n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    iota(ans.begin(), ans.end(), 0);
    computePhi();
    int N;
    while(cin >> N && N != 0)
        cout << ans[N] << '\n';
    return 0;
}
