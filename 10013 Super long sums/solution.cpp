#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        int M;
        cin >> M;
        cin.ignore();
        string ans(M + 1, '0'), digits;
        for(int i = 1; i <= M; ++i) {
            getline(cin, digits);
            ans[i] = digits[0] + digits[2] - '0';
        }
        ans[0] = '0';
        do {
            ans[M - 1] += (ans[M] - '0') / 10;
            ans[M] = (ans[M] - '0') % 10 + '0';
        } while(--M);
        if(ans[0] == '1')
            cout << '1';
        cout << ans.substr(1) << '\n';
        if(N)
            cout << '\n';
    }
    return 0;
}
