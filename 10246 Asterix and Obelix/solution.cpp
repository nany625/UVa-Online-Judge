#include <bits/stdc++.h>
using namespace std;

const int MAXC = 80;
vector<vector<int>> dist(MAXC + 1, vector<int>(MAXC + 1)), ans(MAXC + 1, vector<int>(MAXC + 1));
vector<int> feast(MAXC + 1);

void floydWarshall(int V) {
    vector<int> order(V);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return feast[a] < feast[b];
    });
    for(int k : order) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
                int mx = max({feast[i], feast[j], feast[k]});
                ans[i][j] = min(ans[i][j], dist[i][j] + mx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, C, R, Q;
    while(cin >> C >> R >> Q && C != 0) {
        if(cases)
            cout << '\n';
        cout << "Case #" << ++cases << '\n';
        for(int i = 1; i <= C; ++i) {
            for(int j = 1; j <= C; ++j)
                dist[i][j] = ans[i][j] = i == j ? 0 : 1e9;
        }
        for(int i = 1; i <= C; ++i) {
            cin >> feast[i];
            ans[i][i] = feast[i];
        }
        while(R--) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            dist[c1][c2] = dist[c2][c1] = d;
        }
        floydWarshall(C);
        while(Q--) {
            int c1, c2;
            cin >> c1 >> c2;
            if(ans[c1][c2] >= 1e9)
                cout << "-1\n";
            else
                cout << ans[c1][c2] << '\n';
        }
    }
    return 0;
}
