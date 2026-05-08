#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
array<vector<pair<int, int>>, MAXN> adj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        int n, m;
        cin >> n >> m;
        vector<int> unit(n);
        for(int j = 0; j < n; ++j) {
            adj[j].clear();
            cin >> unit[j];
        }
        while(m--) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, unit[v]);
        }
        int u = 0, gain = 0;
        while(!adj[u].empty()) {
            pair<int, int> mx = {0, 0};
            for(auto [v, w] : adj[u]) {
                if(mx.second < w) 
                    mx = {v, w};
            }
            gain += mx.second;
            u = mx.first;
        }
        cout << "Case " << i << ": " << gain << ' ' << u << '\n';
    }
    return 0;
}
