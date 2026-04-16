#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int n;
        cin >> n;
        unordered_map<int, int> snowflake;
        int ans = 0, top = 1;
        for(int i = 1; i <= n; ++i) {
            int num;
            cin >> num;
            if(top <= snowflake[num]) {
                ans = max(ans, i - top);
                top = snowflake[num] + 1;
            }
            snowflake[num] = i;
        }
        cout << max(ans, n + 1 - top) << '\n';
    }
    return 0;
}
