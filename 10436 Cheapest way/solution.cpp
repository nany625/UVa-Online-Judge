#include <bits/stdc++.h>
using namespace std;

const int MAXV = 19;
array<vector<pair<int, int>>, MAXV> adj;
array<string, MAXV> city;
array<int, MAXV> dist, pre, toll;
unordered_map<string, int> stationNum;

void dijkstra(int V, int S, int T) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist.begin(), dist.begin() + V, INT_MAX);
    iota(pre.begin(), pre.begin() + V, 0);
    dist[S] = toll[S];
    pq.emplace(toll[S], S);
    do {
        auto [d, u] = pq.top();
        if(u == T)
            break;
        pq.pop();
        if(d > dist[u])
            continue;
        for(auto [v, w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                pre[v] = u;
            }
        }
    } while(!pq.empty());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int maps;
	cin >> maps;
	for(int i = 1; i <= maps; ++i) {
	    cout << "Map #" << i << '\n';
	    int V;
	    cin >> V;
	    for(int j = 0; j < V; ++j) {
	        adj[j].clear();
	        cin >> city[j] >> toll[j];
	        stationNum[city[j]] = j;
	    }
	    int E;
	    cin >> E;
	    while(E--) {
	        string city1, city2;
	        int d;
	        cin >> city1 >> city2 >> d;
	        adj[stationNum[city1]].emplace_back(stationNum[city2], (d << 1) + toll[stationNum[city2]]);
	        adj[stationNum[city2]].emplace_back(stationNum[city1], (d << 1) + toll[stationNum[city1]]);
	    }
	    int q;
	    cin >> q;
	    for(int j = 1; j <= q; ++j) {
	        cout << "Query #" << j << '\n';
	        string city1, city2;
	        int passenger;
	        cin >> city1 >> city2 >> passenger;
	        int S = stationNum[city1];
	        int T = stationNum[city2];
	        dijkstra(V, S, T);
	        vector<int> path;
	        while(T != S) {
	            path.push_back(T);
	            T = pre[T];
	        }
	        path.push_back(S);
	        for(int k = path.size() - 1; k > 0; --k)
	            cout << city[path[k]] << ' ';
	        cout << city[path.front()] << "\nEach passenger has to pay : " << fixed << setprecision(2) << dist[path.front()] * 1.1 / passenger << " taka\n";
	    }
	    if(i < maps)
	        cout << '\n';
	}
	return 0;
}
