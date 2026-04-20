#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
vector<vector<int>> adj(MAXN + 1);
vector<int> used(MAXN + 1);
bitset<MAXN + 1> visited;

void init(int N) {
    for(int i = 1; i <= N; ++i)
        adj[i].clear();
    fill(used.begin(), used.begin() + N + 1, 0);
}

int bfs(int X) {
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
                    if(used[v] > 1)
                        ans += dist;
                }
            }
            q.pop();
        } while(!q.empty());
        q = temp;
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
        init(N);
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
        int X = -1, mn = INT_MAX;
        for(int i = 1; i <= N; ++i) {
            if(used[i] > 1) {
                int dist = bfs(i);
                if(dist < mn) {
                    mn = dist;
                    X = i;
                }
            }
        }
        cout << "Krochanska is in: " << X << '\n';
    }
    return 0;
}
