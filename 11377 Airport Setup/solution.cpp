#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
vector<vector<int>> adj(MAXN + 1);
vector<int> dist(MAXN + 1);
bitset<MAXN + 1> hasAirport;

int bfs01(int n, int s, int t) {
    deque<int> dq;
    fill(dist.begin(), dist.begin() + n + 1, INT_MAX);
    dist[s] = 1 - hasAirport[s];
    dq.push_back(s);
    do {
        int u = dq.front();
        if(u == t)
            break;
        dq.pop_front();
        for(int v : adj[u]) {
            int w = 1 - hasAirport[v];
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    } while(!dq.empty());
    return dist[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X;
    cin >> X;
    for(int i = 1; i <= X; ++i) {
        cout << "Case " << i << ":\n";
        int N, M, K;
        cin >> N >> M >> K;
        for(int j = 1; j <= N; ++j)
            adj[j].clear();
        hasAirport.reset();
        while(K--) {
            int c;
            cin >> c;
            hasAirport[c] = 1;
        }
        while(M--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int Q;
        cin >> Q;
        while(Q--) {
            int x, y;
            cin >> x >> y;
            if(x == y)
                cout << "0\n";
            else {
                int ans = bfs01(N, x, y);
                if(ans == INT_MAX)
                    cout << "-1\n";
                else
                    cout << ans << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
