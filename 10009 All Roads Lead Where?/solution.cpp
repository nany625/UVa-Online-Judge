// #解法一
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 26;
vector<vector<int>> adj(MAXV), nxt(MAXV, vector<int>(MAXV));
bitset<MAXV> visited;

vector<int> bfs(int S, int E) {
    visited.reset();
    queue<int> q;
    q.push(S);
    visited[S] = 1;
    vector<int> pre(MAXV);
    pre[S] = S;
    do {
        queue<int> temp;
        do {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    temp.push(v);
                    visited[v] = 1;
                    pre[v] = u;
                }
            }
        } while(!q.empty());
        q = temp;
    } while(!visited[E]);
    vector<int> path;
    while(E != S) {
        path.push_back(E);
        E = pre[E];
    }
    path.push_back(S);
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int m, n;
        cin >> m >> n;
        vector<int> cityID(MAXV, -1);
        string idToCity;
        int id = 0;
        string city1, city2;
        vector<pair<int, int>> edge;
        while(m--) {
            cin >> city1 >> city2;
            int u = city1[0] - 'A';
            int v = city2[0] - 'A';
            if(cityID[u] == -1) {
                cityID[u] = id++;
                idToCity.push_back(city1[0]);
            }
            if(cityID[v] == -1) {
                cityID[v] = id++;
                idToCity.push_back(city2[0]);
            }
            edge.emplace_back(cityID[u], cityID[v]);
        }
        for(int i = 0; i < id; ++i)
            adj[i].clear();
        for(auto [u, v] : edge) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(n--) {
            cin >> city1 >> city2;
            int u = cityID[city1[0] - 'A'];
            int v = cityID[city2[0] - 'A'];
            vector<int> path = bfs(u, v);
            for(int i = path.size() - 1; i >= 0; --i)
                cout << idToCity[path[i]];
            cout << '\n';
        }
        if(cases)
            cout << '\n';
    }
    return 0;
}

// #解法二
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 26;
vector<vector<int>> dist(MAXV, vector<int>(MAXV)), nxt(MAXV, vector<int>(MAXV));

void floydWarshall(int V) {
    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        int m, n;
        cin >> m >> n;
        vector<int> cityID(MAXV, -1);
        string idToCity;
        int id = 0;
        string city1, city2;
        vector<pair<int, int>> edge;
        while(m--) {
            cin >> city1 >> city2;
            int u = city1[0] - 'A';
            int v = city2[0] - 'A';
            if(cityID[u] == -1) {
                cityID[u] = id++;
                idToCity.push_back(city1[0]);
            }
            if(cityID[v] == -1) {
                cityID[v] = id++;
                idToCity.push_back(city2[0]);
            }
            edge.emplace_back(cityID[u], cityID[v]);
        }
        for(int i = 0; i < id; ++i) {
            for(int j = 0; j < id; ++j)
                dist[i][j] = i == j ? 0 : 1e9;
        }
        for(auto [u, v] : edge) {
            dist[u][v] = dist[v][u] = 1;
            nxt[u][v] = v;
            nxt[v][u] = u;
        }
        floydWarshall(id);
        while(n--) {
            cin >> city1 >> city2;
            cout << city1[0];
            int u = cityID[city1[0] - 'A'];
            int v = cityID[city2[0] - 'A'];
            while(u != v) {
                u = nxt[u][v];
                cout << idToCity[u];
            }
            cout << '\n';
        }
        if(cases)
            cout << '\n';
    }
    return 0;
}
