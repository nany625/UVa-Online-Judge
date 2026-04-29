#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
bitset<MAXN + 1> reach[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N && N != 0) {
        for(int i = 1; i <= N; ++i) {
            reach[i].reset();
            int T;
            cin >> T;
            while(T--) {
                int j;
                cin >> j;
                reach[i][j] = 1;
            }
        }
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(reach[j][i])
                    reach[j] |= reach[i];
            }
        }
        int ans = 0, mx = 0;
        for(int i = 1; i <= N; ++i) {
            int sum = 0;
            for(int j = 1; j <= N; ++j)
                sum += reach[i][j];
            if(mx < sum) {
                mx = sum;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
