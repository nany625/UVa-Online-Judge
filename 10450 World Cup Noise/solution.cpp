#include <bits/stdc++.h>
using namespace std;

array<long, 51> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans[0] = 1;
    ans[1] = 2;
    for(int n = 2; n < 51; ++n)
        ans[n] = ans[n - 2] + ans[n - 1];
    int scenarios;
    cin >> scenarios;
    for(int i = 1; i <= scenarios; ++i) {
        int n;
        cin >> n;
        cout << "Scenario #" << i << ":\n" << ans[n] << "\n\n";
    }
    return 0;
}
