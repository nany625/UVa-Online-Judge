#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
array<vector<pair<int, int>>, MAXN> adj;
array<int, MAXN> dist1, dist2;

int dijkstra(int n, int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist1.begin(), dist1.end(), INT_MAX);
    fill(dist2.begin(), dist2.end(), INT_MAX);
    dist1[s] = 0;
    pq.emplace(0, s);
    do {
        auto [d, u] = pq.top();
        if(u == t && d == dist2[t])
            break;
        pq.pop();
        if(d > dist2[u])
            continue;
        for(auto [v, w] : adj[u]) {
            int newDist = d + w;
            if(dist1[v] > newDist) {
                dist2[v] = dist1[v];
                dist1[v] = newDist;
                pq.emplace(dist1[v], v);
            } else if(dist1[v] < newDist && dist2[v] > newDist) {
                dist2[v] = newDist;
                pq.emplace(dist2[v], v);
            }
        }
    } while(!pq.empty());
    return dist2[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, n, r;
    while(cin >> n >> r) {
        cout << "Set #" << ++cases << '\n';
        for(int i = 0; i < n; ++i)
            adj[i].clear();
        while(r--) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int q;
        cin >> q;
        while(q--) {
            int u, v;
            cin >> u >> v;
            int ans = dijkstra(n, u, v);
            if(ans == INT_MAX)
                cout << "?\n";
            else
                cout << ans << '\n';
        }
    }
    return 0;
}
