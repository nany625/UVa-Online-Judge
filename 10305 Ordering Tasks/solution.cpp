#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<vector<int>> adj(MAXN + 1);
vector<int> indeg(MAXN + 1);

vector<int> topo_sort(int n) {
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(indeg[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(--indeg[v] == 0)
                q.push(v);
        }
        topo.push_back(u);
    }
    if(topo.size() != n)
        return {};
    return topo;
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
        vector<int> topo = topo_sort(n);
        for(int i = 0; i < topo.size() - 1; ++i)
            cout << topo[i] << ' ';
        cout << topo.back() << '\n';
    }
    return 0;
}
