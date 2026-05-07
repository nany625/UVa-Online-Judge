#include <bits/stdc++.h>
using namespace std;

array<int, 10> cnt1, cnt2;

void solve(int n, array<int, 10>& cnt) {
    int base = 1;
    do {
        int high = n / (base * 10);
        int cur = n / base % 10;
        int low = n % base;
        for(int i = 1; i < cur; ++i)
            cnt[i] += (high + 1) * base;
        for(int i = cur + 1; i <= 9; ++i)
            cnt[i] += high * base;
        if(cur != 0) {
            cnt[cur] += high * base + low + 1;
            cnt[0] += high * base;
        } else {
            if(high > 0)
                cnt[0] += (high - 1) * base + low + 1;
        }
        if(high == 0)
            break;
        base *= 10;
    } while(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    while(cin >> a >> b && a != 0) {
        if(a > b)
            swap(a, b);
        cnt1.fill(0);
        cnt2.fill(0);
        solve(a - 1, cnt1);
        solve(b, cnt2);
        for(int i = 0; i < 9; ++i)
            cout << cnt2[i] - cnt1[i] << ' ';
        cout << cnt2[9] - cnt1[9] << '\n';
    }
    return 0;
}
