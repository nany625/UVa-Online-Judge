#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000;
array<vector<pair<int, int>>, MAXN> adj;

int dijkstra(int n, int S, int T) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n, INT_MAX);
    dist[S] = 0;
    pq.emplace(0, S);
    do {
        auto [d, u] = pq.top();
        if(u == T)
            break;
        pq.pop();
        if(d > dist[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    } while(!pq.empty());
    return dist[T];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        for(int j = 0; j < n; ++j)
            adj[j].clear();
        while(m--) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        cout << "Case #" << i << ": ";
        int ans = dijkstra(n, S, T);
        if(ans == INT_MAX)
            cout << "unreachable\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
