#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
const int MAXK = 100;
vector<int> X(MAXN + 1), prevPos(MAXK + 1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    iota(X.begin(), X.begin() + 4, 0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int N, M, K;
        cin >> N >> M >> K;
        if(K <= 3)
            cout << "Case " << i << ": " << K << '\n';
        else if(M < K)
            cout << "Case " << i << ": sequence nai\n";
        else {
            iota(prevPos.begin(), prevPos.begin() + 4, 0);
            fill(prevPos.begin() + 4, prevPos.end(), 0);
            int ans = N, start = 1, cnt = 3;
            for(int j = 4; j <= N; ++j) {
                X[j] = (X[j - 1] + X[j - 2] + X[j - 3]) % M + 1;
                if(X[j] <= K) {
                    if(prevPos[X[j]] == 0)
                        ++cnt;
                    else {
                        if(prevPos[X[j]] == start) {
                            start = j;
                            for(int k = 1; k <= K; ++k) {
                                if(prevPos[k] != 0 && k != X[j])
                                    start = min(start, prevPos[k]);
                            }
                        }
                    }
                    prevPos[X[j]] = j;
                    if(cnt == K)
                        ans = min(ans, j - start + 1);
                }
            }
            if(cnt == K)
                cout << "Case " << i << ": " << ans << '\n';
            else
                cout << "Case " << i << ": sequence nai\n";
        }
    }
    return 0;
}
