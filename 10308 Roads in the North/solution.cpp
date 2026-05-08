#include <bits/stdc++.h>
using namespace std;

const int MAXE = 10000;
array<vector<pair<int, int>>, MAXE + 1> roads;
bitset<MAXE + 1> visited;
int ans, S;

void init() {
    for(int i = 0; i <= MAXE; ++i)
        roads[i].clear();
    visited.reset();
    ans = 0;
}

void addRoads(string& line) {
    istringstream iss(line);
    int u, v, w;
    iss >> u >> v >> w;
    roads[u].emplace_back(v, w);
    roads[v].emplace_back(u, w);
}

void dfs(int V, int dist) {
    visited[V] = 1;
    for(int i = 0; i < roads[V].size(); ++i) {
        if(!visited[roads[V][i].first])
            dfs(roads[V][i].first, dist + roads[V][i].second);
    }
    if(ans < dist) {
        ans = dist;
        S = V;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    int u, v, w;
    while(getline(cin, line) && !line.empty()) {
        init();
        addRoads(line);
        while(getline(cin, line) && !line.empty())
            addRoads(line);
        dfs(1, 0);
        visited.reset();
        dfs(S, 0);
        cout << ans << '\n';
    }
    return 0;
}
