#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
vector<vector<int>> adj(MAXN + 1);
vector<int> dist(MAXN + 1);
bitset<MAXN + 1> hasAirport;

int dijkstra(int n, int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist.begin(), dist.begin() + n + 1, INT_MAX);
    dist[s] = 1 - hasAirport[s];
    pq.emplace(dist[s], s);
    do {
        auto [d, u] = pq.top();
        if(u == t)
            break;
        pq.pop();
        if(d > dist[u])
            continue;
        for(int v : adj[u]) {
            if(dist[v] > dist[u] + 1 - hasAirport[v]) {
                dist[v] = dist[u] + 1 - hasAirport[v];
                pq.emplace(dist[v], v);
            }
        }
    } while(!pq.empty());
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
                int ans = dijkstra(N, x, y);
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
