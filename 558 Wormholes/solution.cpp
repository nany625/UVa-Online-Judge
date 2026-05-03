// #解法一
#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edge;

bool bellmanFord(int n) {
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    for(int i = 0; i < n - 1; ++i) {
        bool update = false;
        for(auto [x, y, t] : edge) {
            if(dist[x] < 1e9 && dist[y] > dist[x] + t) {
                dist[y] = dist[x] + t;
                update = true;
            }
        }
        if(!update)
            return false;
    }
    for(auto [x, y, t] : edge) {
        if(dist[x] < 1e9 && dist[y] > dist[x] + t)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--) {
        int n, m;
        cin >> n >> m;
        edge.clear();
        while(m--) {
            int x, y, t;
            cin >> x >> y >> t;
            edge.emplace_back(x, y, t);
        }
        cout << (bellmanFord(n) ? "possible\n" : "not possible\n");
    }
    return 0;
}

// #解法二
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<vector<pair<int, int>>> adj(MAXN);
vector<int> dist(MAXN), cnt(MAXN);
bitset<MAXN> inQueue;

bool spfa(int n) {
    fill(dist.begin(), dist.begin() + n, 1e9);
    fill(cnt.begin(), cnt.begin() + n, 0);
    inQueue.reset();
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    inQueue[0] = 1;
    ++cnt[0];
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = 1;
                    ++cnt[v];
                    if(cnt[v] > n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            adj[i].clear();
        while(m--) {
            int x, y, t;
            cin >> x >> y >> t;
            adj[x].emplace_back(y, t);
        }
        cout << (spfa(n) ? "possible\n" : "not possible\n");
    }
    return 0;
}
