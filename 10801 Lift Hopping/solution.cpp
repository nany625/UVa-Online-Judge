#include <bits/stdc++.h>
using namespace std;

const int MAX_FLOOR = 100;
const int MAXN = 5;
array<vector<pair<int, int>>, MAX_FLOOR * MAXN> adj;
array<vector<int>, MAX_FLOOR> floorToNode;
unordered_map<int, int> nodeToFloor;

int dijkstra(int n, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n, INT_MAX);
    dist[floorToNode[0][0]] = 0;
    pq.emplace(0, floorToNode[0][0]);
    do {
        auto [d, u] = pq.top();
        if(nodeToFloor[u] == k)
            return dist[u];
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
    return INT_MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    while(cin >> n >> k) {
        for(int i = 0; i < adj.size(); ++i)
            adj[i].clear();
        for(int i = 0; i < MAX_FLOOR; ++i)
            floorToNode[i].clear();
        nodeToFloor.clear();
        vector<int> T(n);
        for(int i = 0; i < n; ++i)
            cin >> T[i];
        cin.ignore();
        int idx = 0;
        string line;
        for(int i = 0; i < n; ++i) {
            getline(cin, line);
            istringstream iss(line);
            int pre;
            iss >> pre;
            floorToNode[pre].push_back(idx);
            nodeToFloor[idx++] = pre;
            int cur;
            while(iss >> cur) {
                floorToNode[cur].push_back(idx);
                nodeToFloor[idx++] = cur;
                adj[idx - 2].emplace_back(idx - 1, (cur - pre) * T[i]);
                adj[idx - 1].emplace_back(idx - 2, (cur - pre) * T[i]);
                pre = cur;
            }
        }
        for(int i = 0; i < MAX_FLOOR; ++i) {
            if(floorToNode[i].size() > 1) {
                for(int j = 0; j < floorToNode[i].size() - 1; ++j) {
                    for(int l = j + 1; l < floorToNode[i].size(); ++l) {
                        adj[floorToNode[i][j]].emplace_back(floorToNode[i][l], 60 * (i > 0));
                        adj[floorToNode[i][l]].emplace_back(floorToNode[i][j], 60 * (i > 0));
                    }
                }
            }
        }
        int ans = dijkstra(idx, k);
        if(ans == INT_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
