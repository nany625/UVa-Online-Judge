#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
array<vector<int>, MAXN + 1> adj;
array<int, MAXN + 1> used;
bitset<MAXN + 1> visited;

int bfs(int X, int cnt) {
    visited.reset();
    queue<int> q;
    q.push(X);
    visited[X] = 1;
    int ans = 0, dist = 0;
    do {
        ++dist;
        queue<int> temp;
        do {
            int u = q.front();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    temp.push(v);
                    visited[v] = 1;
                    if(used[v] > 1) {
                        ans += dist;
                        --cnt;
                    }
                }
                if(cnt == 0)
                    return ans;
            }
            q.pop();
        } while(!q.empty());
        swap(q, temp);
    } while(!q.empty());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int N, S;
        cin >> N >> S;
        for(int i = 1; i <= N; ++i)
            adj[i].clear();
        fill(used.begin(), used.begin() + N + 1, 0);
        while(S--) {
            int u;
            cin >> u;
            ++used[u];
            int v;
            while(cin >> v && v != 0) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                ++used[v];
                u = v;
            }
        }
        vector<int> important;
        for(int i = 1; i <= N; ++i) {
            if(used[i] > 1)
                important.push_back(i);
        }
        int X, mn = INT_MAX;
        for(int u : important) {
            int dist = bfs(u, important.size() - 1);
            if(dist < mn) {
                mn = dist;
                X = u;
            }
        }
        cout << "Krochanska is in: " << X << '\n';
    }
    return 0;
}
