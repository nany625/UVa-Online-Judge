#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

vector<int> ans(MAXN + 1);

void eratosthenesSieve() {
    for(int n = 2; n <= MAXN; ++n) {
        if(ans.at(n) == n) {
            for(int i = n; i <= MAXN; i += n)
                ans.at(i) -= ans.at(i) / n;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int n = 1; n <= MAXN; ++n)
        ans.at(n) = n;
    eratosthenesSieve();
    for(int n = 2; n <= MAXN; ++n)
        ans.at(n) = (ans.at(n) << 1) + ans.at(n - 1);
    int N;
    while(cin >> N && N != 0)
        cout << ans.at(N) << '\n';
    return 0;
}
