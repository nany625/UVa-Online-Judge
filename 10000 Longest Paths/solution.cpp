#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<vector<int>> adj(MAXN + 1);
vector<int> indeg(MAXN + 1);

pair<int, int> topo_sort(int n, int s) {
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    do {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
        topo.push_back(u);
    } while(!q.empty());
    vector<int> dist(n + 1, -1);
    dist[s] = 0;
    for(int u : topo) {
        if(dist[u] == -1)
            continue;
        for(int v : adj[u])
            dist[v] = max(dist[v], dist[u] + 1);
    }
    int ans = 1;
    for(int i = 2; i <= n; ++i) {
        if(dist[ans] < dist[i])
            ans = i;
    }
    return {dist[ans], ans};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, n;
    while(cin >> n && n != 0) {
        int s;
        cin >> s;
        for(int i = 1; i <= n; ++i)
            adj[i].clear();
        fill(indeg.begin(), indeg.begin() + n + 1, 0);
        int p, q;
        while(cin >> p >> q && p != 0) {
            adj[p].push_back(q);
            ++indeg[q];
        }
        auto [d, e] = topo_sort(n, s);
        cout << "Case " << ++cases << ": The longest path from " << s << " has length " << d << ", finishing at " << e << ".\n\n";
    }
    return 0;
}
