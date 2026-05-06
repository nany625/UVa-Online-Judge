#include <bits/stdc++.h>
using namespace std;

const int MAXV = 500;
vector<vector<int>> adj1(MAXV + 1), adj2(MAXV + 1);
vector<int> days(MAXV + 1);
bitset<MAXV + 1> visited;

void dfs1(int u, int& sum) {
    visited[u] = 1;
    sum -= days[u];
    for(int v : adj1[u]) {
        if(!visited[v])
            dfs1(v, sum);
    }
}

void dfs2(int u, int &sum) {
    for(int v : adj2[u]) {
        if(!visited[v]) {
            visited[v] = 1;
            sum -= days[v];
            dfs2(v, sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases = 0, v, e;
    while(cin >> v >> e && v != 0) {
        cout << "Case #" << ++cases << ":\n";
        int sum = 0;
        for(int i = 1; i <= v; ++i) {
            adj1[i].clear();
            adj2[i].clear();
            cin >> days[i];
            sum += days[i];
        }
        while(e--) {
            int x, y;
            cin >> x >> y;
            adj1[y].push_back(x);
            adj2[x].push_back(y);
        }
        int q;
        cin >> q;
        while(q--) {
            int x;
            cin >> x;
            visited.reset();
            int diff = sum;
            dfs1(x, diff);
            dfs2(x, diff);
            cout << diff << '\n';
        }
        cout << '\n';
    }
    return 0;
}
