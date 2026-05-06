#include <bits/stdc++.h>
using namespace std;

const int MAXI = 500;
vector<vector<pair<int, int>>> adj(MAXI + 1);
vector<int> dist(MAXI + 1);
bitset<MAXI + 1> used;

void dijkstra(int n, vector<int>& station) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<>> pq;
    fill(dist.begin(), dist.begin() + n + 1, INT_MAX);
    used.reset();
    for(int x : station) {
        pq.emplace(0, x);
        dist[x] = 0;
        used[x] = 1;
    }
    do {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    } while(!pq.empty());
}

int dijkstra(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> newDist = dist;
    newDist[s] = 0;
    pq.emplace(0, s);
    do {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > newDist[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(newDist[v] > newDist[u] + w) {
                newDist[v] = newDist[u] + w;
                pq.emplace(newDist[v], v);
            }
        }
    } while(!pq.empty());
    return *max_element(newDist.begin() + 1, newDist.begin() + n + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int f, i;
        cin >> f >> i;
        vector<int> station(f);
        for(int j = 0; j < f; ++j)
            cin >> station[j];
        cin.ignore();
        for(int j = 1; j <= i; ++j)
            adj[j].clear();
        string line;
        while(getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int u, v, w;
            iss >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        dijkstra(i, station);
        int mn = INT_MAX, ans = 1;
        for(int j = 1; j <= i; ++j) {
            if(!used[j]) {
                int temp = dijkstra(i, j);
                if(mn > temp) {
                    mn = temp;
                    ans = j;
                }
            }
        }
        cout << ans << '\n';
        if(cases)
            cout << '\n';
    }
    return 0;
}
