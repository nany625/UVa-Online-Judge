#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
array<vector<int>, MAXN + 1> adj;
array<int, MAXN + 1> indeg;

void topo_sort(int n) {
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
    }
    for(int i = 0; i < topo.size() - 1; ++i)
        cout << topo[i] << ' ';
    cout << topo.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m && n != 0) {
        for(int i = 1; i <= n; ++i)
            adj[i].clear();
        fill(indeg.begin(), indeg.begin() + n + 1, 0);
        while(m--) {
            int i, j;
            cin >> i >> j;
            adj[i].push_back(j);
            ++indeg[j];
        }
        topo_sort(n);
    }
    return 0;
}
