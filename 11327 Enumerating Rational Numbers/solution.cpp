#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 200000;

vector<long> ans(MAX_NUM + 1);

void computePhi() {
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(ans[n] == n) {
            for(int i = n; i <= MAX_NUM; i += n)
                ans[i] -= ans[i] / n;
        }
        ans[n] += ans[n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans[1] = 2;
    iota(ans.begin() + 2, ans.end(), 2);
    computePhi();
    long k;
    while(cin >> k && k != 0) {
        if(k <= 2)
            cout << k - 1 << "/1\n";
        else {
            int idx = lower_bound(ans.begin() + 2, ans.end(), k) - ans.begin();
            if(k << 1  <= ans[idx - 1] + ans[idx]) {
                long cnt = ans[idx - 1];
                for(int i = 1; i < idx; ++i) {
                    cnt += gcd(i, idx) == 1;
                    if(cnt == k) {
                        cout << i << '/' << idx << '\n';
                        break;
                    }
                }
            } else {
                long cnt = ans[idx] + 1;
                for(int i = idx - 1; i >= 1; --i) {
                    cnt -= gcd(i, idx) == 1;
                    if(cnt == k) {
                        cout << i << '/' << idx << '\n';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
