#include <bits/stdc++.h>
using namespace std;

vector<long> ans(20);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans[1] = 1;
    for(int n = 2; n < 20; ++n)
        ans[n] = (ans[n - 1] << 1) * ((n << 1) - 1) / (n + 1);
    int n;
    while(cin >> n)
        cout << upper_bound(ans.begin(), ans.end(), n) - ans.begin() - 1 << '\n';
    return 0;
}
